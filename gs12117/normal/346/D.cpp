#include<stdio.h>
int n,m;
int edge[1001000][2];
int en[1001000];
int el[2001000];
int ren[1001000];
int rel[2001000];
int st;
int end;
int dp[1001000];
int ten[1001000];
int tdl[1001000];
int tdln;
int ntdl[1001000];
int antdl[1001000];
int ntdln;
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&edge[i][0],&edge[i][1]);
		en[edge[i][0]+2]++;
		ren[edge[i][1]+2]++;
	}
	for(i=0;i<n+7;i++){
		en[i+1]+=en[i];
		ren[i+1]+=ren[i];
	}
	for(i=0;i<m;i++){
		el[en[edge[i][0]+1]]=edge[i][1];
		en[edge[i][0]+1]++;
		rel[ren[edge[i][1]+1]]=edge[i][0];
		ren[edge[i][1]+1]++;
	}
	scanf("%d%d",&st,&end);
	for(i=1;i<=n;i++){
		dp[i]=999999999;
	}
	dp[end]=0;
	tdl[0]=end;
	tdln=1;
	while(tdln!=0){
		for(i=0;i<tdln;i++){
			for(j=ren[tdl[i]];j<ren[tdl[i]+1];j++){
				if(dp[tdl[i]]>=dp[rel[j]])continue;
				ten[rel[j]]++;
				if(ten[rel[j]]==1){
					dp[rel[j]]=dp[tdl[i]]+1;
					ntdl[ntdln]=rel[j];
					antdl[rel[j]]=ntdln;
					ntdln++;
				}
				if(ten[rel[j]]==en[rel[j]+1]-en[rel[j]]){
					dp[rel[j]]=dp[tdl[i]];
					tdl[tdln]=rel[j];
					tdln++;
					ntdln--;
					ntdl[antdl[rel[j]]]=ntdl[ntdln];
					antdl[ntdl[antdl[rel[j]]]]=antdl[rel[j]];
				}
			}
		}
		tdln=ntdln;
		ntdln=0;
		for(i=0;i<tdln;i++){
			tdl[i]=ntdl[i];
		}
	}
	if(dp[st]>9999999)printf("-1");
	else printf("%d",dp[st]);
}