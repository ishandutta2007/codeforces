#include<stdio.h>
#include<vector>
#define N 200005
using namespace std;
vector<int>ans[N];
int Go[N<<1],Next[N<<1],Value[N<<1],End[N],cnt;
int Max,n,i,x,y,k;
void add(int u,int v,int w){
	Go[++cnt]=v;Next[cnt]=End[u];End[u]=cnt;Value[cnt]=w;
}
void DFS(int x,int Fa,int Limit){
	int now=0;
	for (int i=End[x],y;i;i=Next[i])
		if ((y=Go[i])!=Fa){
			if ((++now)==Limit) now++;
			ans[now].push_back(Value[i]);
			Max=max(Max,now);
			DFS(y,x,now);
		}
}
int main(){
	scanf("%d",&n);
	for (i=1;i<n;i++)
		scanf("%d%d",&x,&y),add(x,y,i),add(y,x,i);
	DFS(1,0,0);
	printf("%d\n",Max);
	for (i=1;i<=Max;i++,puts(""))
		for (printf("%d",ans[i].size()),k=0;k<ans[i].size();k++)
			printf(" %d",ans[i][k]);
}