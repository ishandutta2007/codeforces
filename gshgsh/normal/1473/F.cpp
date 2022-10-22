#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 4001
#define MAXM 200001
#define INF 0x3fffffff
int N,M,lst[MAXN],s,t,fst[MAXN],now[MAXN],cnt=1,to[MAXM],flow[MAXM],nxt[MAXM],dep[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void add(int u,int v,int f){to[++cnt]=v,flow[cnt]=f,nxt[cnt]=fst[u],fst[u]=cnt;to[++cnt]=u,flow[cnt]=0,nxt[cnt]=fst[v],fst[v]=cnt;}
bool bfs()
{
	For(i,s,t)now[i]=fst[i],dep[i]=-1;queue<int>q;q.push(s);dep[s]=0;
	while(!q.empty()){int u=q.front();q.pop();if(u==t)return 1;for(int i=fst[u];i;i=nxt[i])if(flow[i]&&dep[to[i]]==-1)dep[to[i]]=dep[u]+1,q.push(to[i]);}return 0;
}
int dfs(int u,int in)
{
	int res=0;if(u==t||!in)return in;
	for(int i=now[u];i;i=nxt[i]){now[u]=i;if(flow[i]&&dep[to[i]]==dep[u]+1){int tmp=dfs(to[i],min(in,flow[i]));flow[i]-=tmp,flow[i^1]+=tmp,res+=tmp,in-=tmp;if(!in)break;}}return res;
}
int main()
{
	N=get();s=0,t=N+1;For(i,1,N){int x=get();For(j,1,x)if(x%j==0)if(lst[j])add(i,lst[j],INF);lst[x]=i;}int ans=0;For(i,1,N){int x=get();x>0?ans+=x,add(s,i,x):add(i,t,-x);}
	while(bfs())ans-=dfs(s,INF);cout<<ans<<'\n';
}