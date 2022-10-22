#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u) for(int i=now[u];i;i=nxt[i])
#define INF 0x3fffffff
#define MAXN 201
#define MAXV 100001
#define MAXM 1000001
int N,M,a[MAXN][MAXN],s,t,fst[MAXV],now[MAXV],cnt=1,to[MAXM],flow[MAXM],nxt[MAXM],dep[MAXV],ans;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void add(int u,int v,int f){to[++cnt]=v,flow[cnt]=f,nxt[cnt]=fst[u],fst[u]=cnt;to[++cnt]=u,flow[cnt]=0,nxt[cnt]=fst[v],fst[v]=cnt;}
bool bfs()
{
	memset(dep,-1,sizeof(dep));dep[s]=0;queue<int>q;q.push(s);
	while(!q.empty()){int u=q.front();q.pop();if(u==t)return 1;now[u]=fst[u];FOR(i,u)if(flow[i]&&dep[to[i]]==-1)dep[to[i]]=dep[u]+1,q.push(to[i]);}return 0;
}
int dfs(int u,int in)
{
	if(u==t||!in)return in;int ans=0;
	FOR(i,u){now[u]=i;if(dep[to[i]]!=dep[u]+1)continue;int tmp=dfs(to[i],min(in,flow[i]));in-=tmp,ans+=tmp,flow[i]-=tmp,flow[i^1]+=tmp;if(!in)break;}return ans;
}
int main()
{
	N=get(),M=get();int sum=0;For(i,1,N)For(j,1,M){char c;cin>>c;sum+=a[i][j]=c=='#';}s=0,t=(N-1)*M+(M-1)*N+1;
	int E=0;For(i,1,N)For(j,1,M-1)if(a[i][j]&&a[i][j+1])E++,add(s,(i-1)*(M-1)+j,1);For(i,1,N-1)For(j,1,M)if(a[i][j]&&a[i+1][j])E++,add(N*(M-1)+(j-1)*(N-1)+i,t,1);
	For(i,1,N)For(j,1,M)if(a[i][j])
	{
		vector<int>tmp;if(j>1&&a[i][j-1])tmp.push_back((i-1)*(M-1)+j-1);if(j<M&&a[i][j+1])tmp.push_back((i-1)*(M-1)+j);
		if(i>1&&a[i-1][j])for(auto x:tmp)add(x,N*(M-1)+(j-1)*(N-1)+i-1,1);if(i<N&&a[i+1][j])for(auto x:tmp)add(x,N*(M-1)+(j-1)*(N-1)+i,1);
	}
	ans=sum-E;while(bfs())ans+=dfs(s,INF);cout<<ans<<endl;return 0;
}