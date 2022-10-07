#include<stdio.h>
int n;
int q;
int dp[1000][1000];
int xmax;
void scat(int x,int y){
	if(x>xmax)xmax=x;
	if(dp[x][y]<=3)return;
	dp[x][y]-=4;
	dp[x+1][y]++;
	scat(x+1,y);
	dp[x][y+1]++;
	scat(x,y+1);
	if(x==1){
		dp[x-1][y]+=2;
		scat(x-1,y);
	}
	else if(x!=0){
		dp[x-1][y]++;
		scat(x-1,y);
	}
	if(y==1){
		dp[x][y-1]+=2;
		scat(x,y-1);
	}
	else if(y!=0){
		dp[x][y-1]++;
		scat(x,y-1);
	}
}
int main(){
	int i,x,y;
	scanf("%d%d",&n,&q);
	for(i=0;i<n;i++){
		dp[0][0]++;
		scat(0,0);
	}
	for(i=0;i<q;i++){
		scanf("%d%d",&x,&y);
		if(x<0)x=-x;
		if(y<0)y=-y;
if(x>900||y>900)printf("0\n");
		else printf("%d\n",dp[x][y]);
	}
}