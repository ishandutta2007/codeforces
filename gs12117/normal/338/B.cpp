#include<stdio.h>
int n,m,d;
int edge[100100][2];
int en[100100];
int elist[200100];
int kchk[100100];
int chk[100100];
int md[100100];
int smd[100100];
int mdl[100100];
int ans;
void dfs(int loc){
	int i;
	chk[loc]=1;
	if(kchk[loc]==1)md[loc]=0;
	else md[loc]=-1;
	mdl[loc]=-1;
	smd[loc]=-1;
	for(i=en[loc];i<en[loc+1];i++){
		if(chk[elist[i]]==0){
			dfs(elist[i]);
			if(md[elist[i]]==-1)continue;
			if(md[loc]<md[elist[i]]+1){
				smd[loc]=md[loc];
				md[loc]=md[elist[i]]+1;
				mdl[loc]=elist[i];
			}
			else if(smd[loc]<md[elist[i]]+1){
				smd[loc]=md[elist[i]]+1;
			}
		}
	}
}
void sdfs(int loc,int mud){
	int i,t;
	chk[loc]=2;
	if(md[loc]<=d&&mud<=d)ans++;
	for(i=en[loc];i<en[loc+1];i++){
		if(chk[elist[i]]==1){
			if(elist[i]==mdl[loc]){
				t=smd[loc];
			}
			else{
				t=md[loc];
			}
			if(t<mud)t=mud;
			if(t==-1){
				sdfs(elist[i],-1);
			}
			else{
				sdfs(elist[i],t+1);
			}
		}
	}
}
int main(){
	int i,j,t;
	scanf("%d%d%d",&n,&m,&d);
	for(i=0;i<m;i++){
		scanf("%d",&t);
		kchk[t]=1;
	}
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
		en[edge[i][0]+1]++;
		elist[en[edge[i][1]+1]]=edge[i][0];
		en[edge[i][1]+1]++;
	}
	dfs(1);
	sdfs(1,-1);
	printf("%d",ans);
}