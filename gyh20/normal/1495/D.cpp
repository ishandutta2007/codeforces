#include<bits/stdc++.h>
#define N 1001
#define INF 0x3f3f3f3f
#define mod 998244353
using namespace std;
int n,m,d[N][N],f[N][N],ans;
vector<int>g[N];
inline void SPFA(int S,int*d,int*f){
	int i,x;queue<int>q;while(q.size())q.pop();
	for(i=1;i<=n;++i)d[i]=INF;
	q.push(S),f[S]=1,d[S]=0;
	while(!q.empty()){
		x=q.front();q.pop();
		for(int y:g[x])if(d[y]>d[x]+1)d[y]=d[x]+1,f[y]=f[x],q.push(y);
		else if(d[y]==d[x]+1)f[y]=min(f[y]+f[x],2);
	}
}
inline int Calc(int x,int y){
	int i,res=1,cnt;if(f[x][y]==2)return 0;
	for(i=1;i<=n;++i)if(d[x][i]+d[y][i]!=d[x][y]){
		cnt=0;for(int j:g[i])if(d[x][j]+1==d[x][i]&&d[y][j]+1==d[y][i])++cnt;
		res=1ll*res*cnt%mod;
	}return res;
}
signed main(void){
	int i,j,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)scanf("%d%d",&x,&y),g[x].push_back(y),g[y].push_back(x);
	for(i=1;i<=n;++i)SPFA(i,d[i],f[i]);
	for(i=1;i<=n;++i,putchar('\n'))for(j=1;j<=n;++j)printf("%d ",Calc(i,j));
	return 0;
}