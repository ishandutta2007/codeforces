#include<bits/stdc++.h>
#define N 50005
using namespace std;
vector<int>id[N];
int x[N],y[N],best[N],a[N],ans[N];
int G[1000005],n,m,i,j,k;
int main(){
	for (i=1;i<=1000000;i++)
		G[i]=G[i-1]^i;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (i=1;i<=m;i++)
		scanf("%d%d",&x[i],&y[i]),
		id[y[i]].push_back(i);
	for (i=1;i<=n;i++) best[i]=0;
	for (i=1;i<=n;i++){
		best[i]=max(best[i],a[i]);
		for (j=i-1;j;j--){
			best[j]=max(best[j],best[j+1]);
			best[j]=max(best[j],G[a[i]]^G[a[j]]^min(a[i],a[j]));
	  }for (k=0;k<id[i].size();k++)
	  	ans[id[i][k]]=best[x[id[i][k]]];
  }for (i=1;i<=m;i++)
  	printf("%d\n",ans[i]);
}