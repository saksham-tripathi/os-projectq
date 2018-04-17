#include<stdio.h>
#include <stdlib.h>
#define N 100
int ck=0;
int rp=0;
int count=0;
void Level2_Round_Robin();
struct level1_process{
	int at,bt,priority,p_id,c_id;
};
void Level_2_Ready_Queue(struct level1_process queue);
struct level2_process2{
	int at2,bt2,priority_2,p_id2;
}process_2[N];
int main(){
	system("COLOR A");
	int total_processes,time,i,l,m;
        int j=0,k=1,count=0,flag=0;
	printf("Enter no. of processes :");
	scanf("%d",&total_processes);
	struct level1_process process[total_processes];
for(i=0;i<total_processes;i++)
    {		printf("Enter process id\n ");
			scanf("%d",&process[i].p_id);
			printf("Enter arrival time of %d :",process[i].p_id);
			scanf("%d",&process[i].at);
                        printf("Enter priority of %d :",process[i].p_id);
                        scanf("%d",&process[i].priority);
			printf("Enter burst time of %d :",process[i].p_id);
			scanf("%d",&process[i].bt);
                        process[i].c_id=process[i].bt;
			system("clear");
			}
                 printf("Gantt chart for level 1 priority scheduling :\n");
			int flag1=0;
		for(i=0;i<total_processes;i++){
		int btd=process[i].c_id;
		int iterator=0;
		k=1;
			for(j=0;j<btd;j++)
                        {
			if(i==0 && process[i].at!=0){
					for(l=0;l<process[i].at;l++){
							count++	;
											}
			time=process[i].at;
			printf("|%d\tprocess[%d]\t%d|",0,0,time);
				}
			else if(i==0 && process[i].at==0 && iterator==0){
				for(l=0;l<process[i+1].at;l++){
					count++;
					process[i].bt--;
				}
			flag1=1;
				printf("|%d\tprocess[%d]\t%d|",process[i].at,process[i].p_id,count);
				time=process[i].at+count;
}
if(i==(total_processes-1)){
				if(count==1);
				for(m=0;m<process[i].bt;m++){
					count++;
		         	}
				printf("|%d\tprocess[%d]\t%d|",time,process[i].p_id,count);
	break;}
	if( count!=0 && ((count%2)==0) && (process[k+i].priority>process[i].priority))//compare the priorities
        {
					printf("|%d\tprocess[%d]\t%d|",time,process[i].p_id,count);
					time=count;
					count++;
					process[i].bt--;
					flag++;
					k++;
					iterator=1;
					continue;
				}
				else if( count!=0 && ((count%2)==0) && (process[i+k].priority < process[i].priority))
				{
				if(k==2){
				printf("|%d\tprocess[%d]\t%d|",time,process[i].p_id,count);
				ck++;
				Level_2_Ready_Queue(process[i+1]); 
				i=i+1;
				iterator=1;
				time=count;
				count++;
				process[i+1].bt--;
				count=1;
					break;
				}
					if(flag1!=1){
					printf("|%d\tprocess[%d]\t%d|",time,process[i].p_id,count);
					}flag1=0;
					if(process[i].bt>0){
						ck++;
							Level_2_Ready_Queue(process[i]);}
				iterator=1;
				time=count;
				count++;
				process[i+1].bt--;
				count=1;
					break;
					}
				else
				{
				flag++;
				process[i].bt--;
				count++;
				iterator=1;
                 		}
 			}
		}
	Level2_Round_Robin();
}
void Level_2_Ready_Queue(struct level1_process queue){
process_2[rp].bt2=queue.bt;
process_2[rp].at2=queue.at;
process_2[rp].priority_2=queue.priority;
process_2[rp].p_id2=queue.p_id;
        rp++;
}
void Level2_Round_Robin(){

  int i, end, total = 0, x, count = 0, Time_Quantum,l,m;
      int waiting_time = 0, Turnaround_Time = 0, atime[15], btime[15], temp[15];
      float Average_waiting_time, Average_Turnaround_Time;
      end=ck;
      x = end;
      for(i = 0; i <end ; i++)
      {
            atime[i]=process_2[i].at2;
            btime[i]=process_2[i].bt2;
            temp[i] = btime[i];
      }
          printf("\n\n");
      printf("\nEnter Time Quantum for level 2 in multiples of 2:\t");
      scanf("%d", &Time_Quantum);
      printf("Following are the burst time,waiting time and turnaround time of proceeses  preemepted from level 1 to level 2");
      printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");
 for(total = 0, i = 0; x != 0;)
      {
            if(temp[i] <= Time_Quantum && temp[i] > 0)
            {
                  total = total + temp[i];
                  temp[i] = 0;
                  count = 1;
            }
            else if(temp[i] > 0)
            {
                  temp[i] = temp[i] - Time_Quantum;
                  total = total + Time_Quantum;
            }
            if(temp[i] == 0 && count == 1)
            {
                  x--;
            printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", process_2[i].p_id2, btime[i],total - atime[i] - btime[i], total - atime[i]);
                  waiting_time = waiting_time + total - atime[i] - btime[i];
                  Turnaround_Time = Turnaround_Time + total - atime[i];
                  count = 0;
            }
            if(i == end - 1)
            {
                  i = 0;
            }
            else if(atime[i + 1] <= total)
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
      }
      Average_waiting_time = waiting_time * 1.0 / end;
      Average_Turnaround_Time = Turnaround_Time * 1.0 / end;
      printf("\n\nAverage Waiting Time of processes entered in level 2:\t%f", Average_waiting_time);
      printf("\nAvg Turnaround Time of processes entered in level 2:\t%f\n", Average_Turnaround_Time);
}
