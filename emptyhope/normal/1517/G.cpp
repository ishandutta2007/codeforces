#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i) 
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i) 
#define int long long 
using namespace std; inline int read() { char c=getchar();int x=0;bool f=0; for(;!isdigit(c);c=getchar())f^=!(c^45); for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48); if(f)x=-x;return x; } 
#define fi first 
#define se second 
#define pb push_back 
#define mkp make_pair 
typedef pair<int,int>pii; typedef vector<int>vi;
const int maxn=10007,maxm=100007,inf=0x3f3f3f3f3f3f3f3f; int n,m,s,t,maxflow; int dep[maxn],cur[maxn]; int tot=1,head[maxn]; struct edge{ int to,nxt,w; }e[maxm<<1]; inline void adde(int u,int v,int w){ e[++tot]=(edge){v,head[u],w}; head[u]=tot; } inline void add(int u,int v,int w){ adde(u,v,w); adde(v,u,0); } bool bfs(int s,int t) { queue<int>q; memcpy(cur,head,sizeof cur); memset(dep,63,sizeof dep); dep[s]=0;q.push(s); while(!q.empty()) { int u=q.front();q.pop(); for(int i=head[u];i;i=e[i].nxt) { int v=e[i].to; if(dep[v]==inf&&e[i].w){ dep[v]=dep[u]+1; if(v==t)return 1; q.push(v); } } }return dep[t]<inf; } int dfs(int u,int t,int minn) { if(!minn||u==t)return minn; int res=0; for(int i=cur[u];i;i=e[i].nxt) { int v=e[i].to; cur[u]=i; if(dep[v]!=dep[u]+1)continue; int flow=dfs(v,t,min(minn,e[i].w)); if(!flow)continue; res+=flow,minn-=flow; e[i].w-=flow,e[i^1].w+=flow; if(!minn)break; } if(!res) dep[u]=0; return res; } inline int dinic(int s,int t) { int maxflow=0,flow=0; while(bfs(s,t))while(flow=dfs(s,t,inf))maxflow+=flow; return maxflow; }
int x[maxn],y[maxn],w[maxn],sum; map<pii,int>mp;
signed main() { n=read(); For(i,1,n)x[i]=read(),y[i]=read(),w[i]=read(), mp[mkp(x[i],y[i])]=i,sum+=w[i]; s=0,t=2*n+1; For(i,1,n) { add(i,i+n,w[i]); bool bx=(x[i]%2),by=(y[i]%2); int to; if(bx&&!by){ add(s,i,inf); if(mp.count(mkp(x[i]+1,y[i]))) add(i+n,mp[mkp(x[i]+1,y[i])],inf); if(mp.count(mkp(x[i]-1,y[i]))) add(i+n,mp[mkp(x[i]-1,y[i])],inf); } else if(!bx&&!by){ if(mp.count(mkp(x[i],y[i]-1))) add(i+n,mp[mkp(x[i],y[i]-1)],inf); if(mp.count(mkp(x[i],y[i]+1))) add(i+n,mp[mkp(x[i],y[i]+1)],inf); } else if(!bx&&by){ if(mp.count(mkp(x[i]+1,y[i]))) add(i+n,mp[mkp(x[i]+1,y[i])],inf); if(mp.count(mkp(x[i]-1,y[i]))) add(i+n,mp[mkp(x[i]-1,y[i])],inf); } else add(i+n,t,inf); } sum -= dinic(s,t); cout<<sum; return 0; }