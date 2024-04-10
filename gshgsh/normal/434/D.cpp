#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u) for(int i=now[u];i;i=nxt[i])
#define INF 0x3fffffffffff
#define inf 0x3fffffff
#define MAXN 20001
#define MAXM 1000001
int N,M,a[MAXN],b[MAXN],c[MAXN],l[MAXN],r[MAXN],sum[MAXN],s,t,fst[MAXN],now[MAXN],cnt=1,to[MAXM],nxt[MAXM],dep[MAXN];ll flow[MAXM],ans;
void add(int u,int v,ll f){to[++cnt]=v,flow[cnt]=f,nxt[cnt]=fst[u],fst[u]=cnt;to[++cnt]=u,flow[cnt]=0,nxt[cnt]=fst[v],fst[v]=cnt;}
bool bfs()
{
	memset(dep,-1,sizeof(dep));dep[s]=0;queue<int>q;q.push(s);
	while(!q.empty()){int u=q.front();q.pop();if(u==t)return 1;now[u]=fst[u];FOR(i,u)if(flow[i]&&dep[to[i]]==-1)dep[to[i]]=dep[u]+1,q.push(to[i]);}return 0;
}
ll dfs(int u,ll in)
{
	if(u==t||!in)return in;ll ans=0;
	FOR(i,u){now[u]=i;if(dep[to[i]]!=dep[u]+1)continue;ll tmp=dfs(to[i],min(in,1ll*flow[i]));in-=tmp,ans+=tmp,flow[i]-=tmp,flow[i^1]+=tmp;if(!in)break;}return ans;
}
int id(int x,int y){return sum[x-1]+y-l[x]+1;}
int main()
{
    cin>>N>>M;For(i,1,N)cin>>a[i]>>b[i]>>c[i];For(i,1,N)cin>>l[i]>>r[i],sum[i]=sum[i-1]+r[i]-l[i]+2;s=0,t=sum[N]+1;
    For(i,1,N){add(s,id(i,l[i]),INF);For(j,l[i],r[i])add(id(i,j),id(i,j+1),inf-a[i]*j*j-b[i]*j-c[i]);add(id(i,r[i]+1),t,INF);}
    For(i,1,M){int u,v,d;cin>>u>>v>>d;For(j,l[u],r[u]+1)if(j-d>=l[v]&&j-d<=r[v]+1)add(id(u,j),id(v,j-d),INF);}
    while(bfs())ans+=dfs(s,INF*(N+1));cout<<1ll*N*inf-ans<<endl;return 0;
}