#include<stdio.h>
int n;
int edge[100100][2];
int en[100100];
int elist[200100];
int chk[100100];
double ans;
void dfs(int loc,int dep){
	int i;
	chk[loc]=1;
	ans+=1.0/dep;
	for(i=en[loc];i<en[loc+1];i++){
		if(chk[elist[i]]==0){
			dfs(elist[i],dep+1);
		}
	}
}
int main(){
	int i;
	scanf("%d",&n);
	for(i=0;i<n-1;i++){
		scanf("%d%d",&edge[i][0],&edge[i][1]);
		en[edge[i][0]+2]++;
		en[edge[i][1]+2]++;
	}
	for(i=0;i<n+3;i++){
		en[i+1]+=en[i];
	}
	for(i=0;i<n-1;i++){
		elist[en[edge[i][0]+1]]=edge[i][1];
		elist[en[edge[i][1]+1]]=edge[i][0];
		en[edge[i][0]+1]++;
		en[edge[i][1]+1]++;
	}
	dfs(1,1);
	printf("%.30lf",ans);
}