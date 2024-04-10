#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 998244353
#define MAXN 401
int N,M,dis[MAXN][MAXN],cnt[MAXN][MAXN];vector<int>E[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void bfs(int s)
{
	int*d=dis[s],*c=cnt[s];queue<int>q;For(i,1,N)d[i]=-1;d[s]=0,c[s]=1;q.push(s);
	while(!q.empty()){int u=q.front();q.pop();for(auto v:E[u])if(d[v]==-1)d[v]=d[u]+1,c[v]=c[u],q.push(v);else if(d[v]==d[u]+1)c[v]=min(c[u]+c[v],2);}
}
int solve(int x,int y){int ans=1;For(i,1,N)if(dis[x][i]+dis[y][i]!=dis[x][y]){int c=0;for(auto j:E[i])if(dis[x][j]+1==dis[x][i]&&dis[y][j]+1==dis[y][i])c++;ans=1ll*ans*c%P;}return ans;}
int main()
{
	N=get(),M=get();For(i,1,M){int u=get(),v=get();E[u].push_back(v),E[v].push_back(u);}For(i,1,N)bfs(i);
	For(i,1,N)For(j,1,N)cout<<(cnt[i][j]==1?solve(i,j):0)<<" \n"[j==N];
}