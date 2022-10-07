#include<stdio.h>
int n,m;
int edge[100100][3];
int query[100100][2];
double prob[100100];
double ans;
int elist[200100];
int en[100100];
int sn[100100];
int dep[100100];
void dfs(int loc){
	sn[loc]=1;
	int i;
	for(i=en[loc];i<en[loc+1];i++){
		if(sn[elist[i]]==0){
			dfs(elist[i]);
			sn[loc]+=sn[elist[i]];
		}
	}
}
int main(){
	int i;
	scanf("%d",&n);
	for(i=0;i<n-1;i++){
		scanf("%d%d%d",&edge[i][0],&edge[i][1],&edge[i][2]);
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
	for(i=0;i<n-1;i++){
		if(sn[edge[i][0]]>sn[edge[i][1]]){
			prob[i]=(double)sn[edge[i][1]]*(n-sn[edge[i][1]])*2/n/(n-1);
		}
		else{
			prob[i]=(double)sn[edge[i][0]]*(n-sn[edge[i][0]])*2/n/(n-1);
		}
		ans+=prob[i]*edge[i][2];
	}
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&query[i][0],&query[i][1]);
		query[i][0]--;
		ans-=prob[query[i][0]]*edge[query[i][0]][2];
		ans+=prob[query[i][0]]*query[i][1];
		edge[query[i][0]][2]=query[i][1];
		printf("%.20lf\n",3*ans);
	}
}