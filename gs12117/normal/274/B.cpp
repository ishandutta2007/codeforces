#include<stdio.h>
int n;
long long int ans;
int elist[200100];
int en[100100];
int edge[100100][2];
int v[100100];
int chk[100100];
long long int sup[100100];
long long int sdn[100100];
void dfs(int loc){
	int i;
	chk[loc]=1;
	for(i=en[loc];i<en[loc+1];i++){
		if(chk[elist[i]]==0){
			dfs(elist[i]);
			if(sup[elist[i]]>sup[loc]){
				sup[loc]=sup[elist[i]];
			}
			if(sdn[elist[i]]>sdn[loc]){
				sdn[loc]=sdn[elist[i]];
			}
		}
	}
	if(sup[loc]>sdn[loc]+v[loc]){
		sdn[loc]=sup[loc]-v[loc];
	}
	else{
		sup[loc]=sdn[loc]+v[loc];
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
	for(i=1;i<=n;i++){
		scanf("%d",&v[i]);
	}
	dfs(1);
	printf("%I64d",sup[1]+sdn[1]);
}