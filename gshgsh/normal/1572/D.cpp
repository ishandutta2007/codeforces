#include<algorithm>
#include<iostream>
#include<cstring>
#include<random>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define INF 0x3fffffff
#define MAXN 12000001
#define MAXM 100001
int N,M,K,a[MAXN],id[MAXN];bool b[MAXN];pair<int,pair<int,int>>v[MAXN];int s,t,fst[MAXM],cnt=1,to[MAXM],flow[MAXM],len[MAXM],nxt[MAXM],dis[MAXM],mflow[MAXM],pre[MAXM],ans,cost;bool in[MAXM];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void add(int u,int v,int f,int l){to[++cnt]=v,flow[cnt]=f,len[cnt]=l,nxt[cnt]=fst[u],fst[u]=cnt;to[++cnt]=u,flow[cnt]=0,len[cnt]=-l,nxt[cnt]=fst[v],fst[v]=cnt;}
bool spfa()
{
	memset(dis,0xbf,sizeof(dis));memset(in,0,sizeof(in));queue<int>q;q.push(s);dis[s]=0;in[s]=1;mflow[s]=INF;
	while(!q.empty()){int u=q.front();q.pop();in[u]=0;for(int i=fst[u];i;i=nxt[i])if(flow[i]&&dis[to[i]]<dis[u]+len[i]){dis[to[i]]=dis[u]+len[i];mflow[to[i]]=min(mflow[u],flow[i]);pre[to[i]]=i;if(!in[to[i]])q.push(to[i]),in[to[i]]=1;}}
	return dis[t]!=0xbfbfbfbf;
}
void upd(){int x=t;while(x!=s){x=pre[x];flow[x]-=mflow[t],flow[x^1]+=mflow[t],x=to[x^1];}ans+=mflow[t],cost+=dis[t]*mflow[t];}
int main()
{
	N=get(),K=get();For(i,0,(1<<N)-1)a[i]=get();
	For(i,0,(1<<N)-1)if(__builtin_popcount(i)&1)For(j,0,N-1)v[++M]={a[i]+a[i^1<<j],{i,i^1<<j}};
	int cnt=min(M,2*K*N);nth_element(v+1,v+cnt,v+M+1,greater<pair<int,pair<int,int>>>());
	For(i,1,cnt)b[v[i].second.first]=b[v[i].second.second]=1;int c=0;For(i,0,(1<<N)-1)if(b[i])id[i]=++c;s=0,t=c+1;
	For(i,0,(1<<N)-1)if(id[i])__builtin_popcount(i)&1?add(s,id[i],1,0):add(id[i],t,1,0);For(i,1,cnt)add(id[v[i].second.first],id[v[i].second.second],1,v[i].first);
	int T=K;while(T--&&spfa())upd();cout<<cost<<'\n';
}