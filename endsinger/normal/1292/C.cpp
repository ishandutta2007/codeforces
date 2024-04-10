#include<bits/stdc++.h>
using namespace std;
const int N=3002;
struct node{
	int to,ne;
}e[N<<1];
vector<node>a[N];
int x,y,h[N],f[N][N],tot,sz[N][N],s,n,i,j;
long long ans,g[N][N];
void add(int x,int y){e[++tot]={y,h[x]},h[x]=tot;}
void dfs(int u,int fa,int dep){
	sz[s][u]=1;
	for (int i=h[u],v;i;i=e[i].ne)
		if ((v=e[i].to)!=fa) f[s][v]=u,dfs(v,u,dep+1),sz[s][u]+=sz[s][v];
	a[dep].push_back({s,u});
}
signed main(){
	scanf("%d",&n);
	for (i=1;i<n;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	for (i=1;i<=n;i++) s=i,dfs(i,0,0);
	for (i=1;i<n;i++)
		for (j=0;j<a[i].size();j++){
			x=a[i][j].to,y=a[i][j].ne;
			ans=max(ans,g[x][y]=max(g[x][f[x][y]],g[y][f[y][x]])+1ll*sz[x][y]*sz[y][x]);
		}
	printf("%lld",ans);
}