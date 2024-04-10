#include<stdio.h>
#include<algorithm>
#define N 2505
using namespace std;
const int INF=2e9;
int Go[N<<1],Next[N<<1],End[N],cnt;
int a[N][N],f[N],pre[N],vis[N],flag[N];
int root,n,i,j,id,k;
void add(int u,int v){Go[++cnt]=v;Next[cnt]=End[u];End[u]=cnt;}
void DFS(int x,int Max){
	vis[x]=root;
	if (Max!=a[root][x]){
		puts("NOT MAGIC");
		exit(0);
  }
	for (int i=End[x],y;i;i=Next[i])
		if (vis[y=Go[i]]!=root)
			DFS(y,max(Max,a[x][y]));
}
int main(){
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for (i=1;i<=n;i++)
		if (a[i][i]) return puts("NOT MAGIC"),0;
	for (i=1;i<n;i++)
		for (j=i+1;j<=n;j++)
			if (a[i][j]!=a[j][i]) return puts("NOT MAGIC"),0;
  for (i=0;i<=n;i++) f[i]=INF;f[1]=0;
  for (i=1;i<=n;i++){
  	id=0;
  	for (k=1;k<=n;k++)
  		if (!flag[k]&&f[k]<f[id]) id=k;
  	flag[id]=1;
  	if (pre[id]) add(pre[id],id),add(id,pre[id]);
  	for (k=1;k<=n;k++)
  		if (a[id][k]<f[k])
  			pre[k]=id,f[k]=a[id][k];
  }for (i=1;i<=n;i++)
  	root=i,DFS(i,0);
  puts("MAGIC");
}