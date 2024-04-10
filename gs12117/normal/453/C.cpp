#include<stdio.h>
int n,m;
int edge[100100][2];
int d[100100];
int elist[200100];
int en[100100];
int chk[100100];
int ansl;
int ans[600100];
int root[100100];
void dfs(int loc){
	int i;
	chk[loc]=1;
	ans[ansl]=loc;
	ansl++;
	d[loc]^=1;
	for(i=en[loc];i<en[loc+1];i++){
		if(chk[elist[i]]==0){
			root[elist[i]]=loc;
			dfs(elist[i]);
		}
	}
	ans[ansl]=root[loc];
	ansl++;
	d[root[loc]]^=1;
	if(d[loc]==1){
		ans[ansl]=loc;
		ansl++;
		d[loc]^=1;
		ans[ansl]=root[loc];
		ansl++;
		d[root[loc]]^=1;
	}
}
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&edge[i][0],&edge[i][1]);
		en[edge[i][0]+2]++;
		en[edge[i][1]+2]++;
	}
	for(i=0;i<n+3;i++){
		en[i+1]+=en[i];
	}
	for(i=0;i<m;i++){
		elist[en[edge[i][0]+1]]=edge[i][1];
		elist[en[edge[i][1]+1]]=edge[i][0];
		en[edge[i][0]+1]++;
		en[edge[i][1]+1]++;
	}
	for(i=1;i<=n;i++){
		scanf("%d",&d[i]);
	}
	for(i=1;i<=n;i++){
		if(d[i]==1){
			dfs(i);
			break;
		}
	}
	if(ansl!=0)ansl--;
	if(ansl>=3&&ans[ansl-2]==0){
		ansl-=3;
	}
	for(i=1;i<=n;i++){
		if(d[i]==1){
			break;
		}
	}
	if(i<=n){
		printf("-1");
	}
	else{
		printf("%d\n",ansl);
		for(i=0;i<ansl;i++){
			printf("%d ",ans[i]);
		}
	}
}