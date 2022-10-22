#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u) for(int i=fst[u];i;i=nxt[i])
#define INF 0x3fffffff
#define MAXN 501
#define MAXM 100001
int N,M,K,s,t,r,b,tot,R[MAXN],B[MAXN],fst[MAXN],cnt=1,to[MAXM],flow[MAXM],len[MAXM],nxt[MAXM],mflow[MAXN],pre[MAXN];ll dis[MAXN],ans;bool in[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void add(int u,int v,int f,int l){to[++cnt]=v,flow[cnt]=f,len[cnt]=l,nxt[cnt]=fst[u],fst[u]=cnt;to[++cnt]=u,flow[cnt]=0,len[cnt]=-l,nxt[cnt]=fst[v],fst[v]=cnt;}
bool spfa()
{
	memset(dis,0x3f,sizeof(dis));memset(in,0,sizeof(in));queue<int>q;q.push(s);dis[s]=0;in[s]=1;mflow[s]=INF;
	while(!q.empty()){int u=q.front();q.pop();in[u]=0;FOR(i,u)if(flow[i]&&dis[to[i]]>dis[u]+len[i]){dis[to[i]]=dis[u]+len[i];mflow[to[i]]=min(mflow[u],flow[i]);pre[to[i]]=i;if(!in[to[i]])q.push(to[i]),in[to[i]]=1;}}return dis[t]!=0x3f3f3f3f3f3f3f3f;
}
void upd(){int x=t;while(x!=s){x=pre[x];flow[x]-=mflow[t],flow[x^1]+=mflow[t],x=to[x^1];}ans+=dis[t]*mflow[t];}
int main()
{
	N=get(),M=get(),K=get(),r=get(),b=get(),s=0,t=N+M+1;
	For(i,1,N){char c;cin>>c;c=='R'||c=='B'?tot++,c=='R'?add(s,i,1,-INF),add(s,i,INF,0):(add(i,t,1,-INF),add(i,t,INF,0)):(add(s,i,INF,0),add(i,t,INF,0));}
	For(i,1,M){char c;cin>>c;c=='R'||c=='B'?tot++,c=='R'?add(i+N,t,1,-INF),add(i+N,t,INF,0):(add(s,i+N,1,-INF),add(s,i+N,INF,0)):(add(s,i+N,INF,0),add(i+N,t,INF,0));}
	For(i,1,K){int u,v;cin>>u>>v;add(u,v+N,1,r);R[i]=cnt-1;add(v+N,u,1,b);B[i]=cnt-1;}while(spfa()){if(dis[t]<=0)upd();else if(ans+tot*INF<INF)break;}
	ans+=1ll*tot*INF;if(ans>INF){cout<<-1<<endl;return 0;}cout<<ans<<endl;For(i,1,K)cout<<(!flow[R[i]]?'R':!flow[B[i]]?'B':'U');return 0;
}