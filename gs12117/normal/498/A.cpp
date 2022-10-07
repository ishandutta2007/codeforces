#include<stdio.h>
int n;
long long int sx,sy;
long long int dx,dy;
int road[100100][3];
int ans;
int main(){
	int i;
	scanf("%I64d%I64d%I64d%I64d",&sx,&sy,&dx,&dy);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d",&road[i][0],&road[i][1],&road[i][2]);
		if((sx*road[i][0]+sy*road[i][1]+road[i][2]>0)!=(dx*road[i][0]+dy*road[i][1]+road[i][2]>0))ans++;
	}
	printf("%d",ans);
}