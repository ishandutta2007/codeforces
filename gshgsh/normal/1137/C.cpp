#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u) for(int i=fst[u];i;i=nxt[i])
#define MAXN 100001
#define MAXD 50
int N,M,D,u[MAXN],v[MAXN],fst[MAXN*MAXD],cnt,to[MAXN*MAXD],nxt[MAXN*MAXD],tot,dfn[MAXN*MAXD],low[MAXN*MAXD],top,sta[MAXN*MAXD],Col,val[MAXN*MAXD],col[MAXN*MAXD],tg[MAXN],ind[MAXN*MAXD],f[MAXN*MAXD],ans;bool op[MAXN*MAXD],in[MAXN*MAXD];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}int get1(){char c=getchar();while(c!='0'&&c!='1')c=getchar();return c-'0';}
void add(int u,int v){to[++cnt]=v,nxt[cnt]=fst[u],fst[u]=cnt;}
void dfs(int u)
{
	dfn[u]=low[u]=++tot;sta[++top]=u;in[u]=1;FOR(i,u)!dfn[to[i]]?dfs(to[i]),low[u]=min(low[u],low[to[i]]):in[to[i]]?low[u]=min(low[u],low[to[i]]):0;
	if(dfn[u]==low[u]){Col++;while(top){int now=sta[top--];col[now]=Col;in[now]=0;if(op[now]&&tg[now%(N+1)]!=Col)val[Col]++,tg[now%(N+1)]=Col;if(now==u)break;}}
}
int main()
{
	N=get(),M=get(),D=get();For(i,1,M){u[i]=get(),v[i]=get();For(j,0,D-1)add(u[i]+j*(N+1),v[i]+(j+1)%D*(N+1));}For(i,1,N)For(j,0,D-1)op[i+j*(N+1)]=get1();dfs(1);
	memset(fst,0,sizeof(fst));cnt=0;For(i,1,M)For(j,0,D-1)if(col[u[i]+j*(N+1)]&&col[v[i]+(j+1)%D*(N+1)]&&col[u[i]+j*(N+1)]!=col[v[i]+(j+1)%D*(N+1)])add(col[u[i]+j*(N+1)],col[v[i]+(j+1)%D*(N+1)]),ind[col[v[i]+(j+1)%D*(N+1)]]++;
	queue<int>q;q.push(col[1]);f[col[1]]=val[col[1]];while(!q.empty()){int u=q.front();q.pop();ans=max(ans,f[u]);FOR(i,u)f[to[i]]=max(f[to[i]],val[to[i]]+f[u]),ind[to[i]]--,!ind[to[i]]?q.push(to[i]),0:0;}cout<<ans<<endl;return 0;
}