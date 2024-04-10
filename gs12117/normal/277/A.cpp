#include<stdio.h>
int n,m;
int lnum[110];
int llist[110][110];
int uft[110];
int ruft[110];
int find(int x){
	if(x==uft[x])return x;
	int r=find(uft[x]);
	uft[x]=r;
	return r;
}
int main(){
	int i,j,t;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&lnum[i]);
		for(j=0;j<lnum[i];j++){
			scanf("%d",&t);
			llist[i][t]=1;
		}
		uft[i]=i;
	}
	for(i=0;i<n;i++){
		if(lnum[i]!=0){
			break;
		}
	}
	if(i==n){
		printf("%d",n);
		return 0;
	}
	for(i=1;i<=m;i++){
		t=-1;
		for(j=0;j<n;j++){
			if(llist[j][i]==1){
				if(t!=-1&&find(j)!=find(t)){
					uft[find(j)]=find(t);
				}
				t=j;
			}
		}
	}
	for(i=0;i<n;i++){
		ruft[find(i)]=1;
	}
	int ans=-1;
	for(i=0;i<n;i++){
		ans+=ruft[i];
	}
	printf("%d",ans);
	return 0;
}