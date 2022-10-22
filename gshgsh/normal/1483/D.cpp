#include<iostream>
#include<cstring>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u) for(int i=fst[u];i;i=nxt[i])
#define MAXN 601
#define MAXM 400001
int N,M,K,u[MAXM],v[MAXM],l[MAXM],fst[MAXN],cnt,to[MAXM],len[MAXM],nxt[MAXM];ll dis[MAXN][MAXN],f[MAXN][MAXN],ans;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void add(int u,int v,int l){to[++cnt]=v,len[cnt]=l,nxt[cnt]=fst[u],fst[u]=cnt;to[++cnt]=u,len[cnt]=l,nxt[cnt]=fst[v],fst[v]=cnt;}
int main()
{
	N=get(),M=get();memset(dis,0x3f,sizeof(dis));For(i,1,N)dis[i][i]=0;For(i,1,M)u[i]=get(),v[i]=get(),dis[u[i]][v[i]]=dis[v[i]][u[i]]=l[i]=get();K=get();For(i,1,K){int u=get(),v=get(),l=get();add(u,v,l);}
	For(k,1,N)For(i,1,N)For(j,1,N)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);memset(f,0xbf,sizeof(f));For(i,1,N)For(j,1,N)FOR(k,j)f[i][j]=max(f[i][j],len[k]-dis[i][to[k]]);
	For(i,1,M){bool flag=0;For(j,1,N)flag|=dis[j][v[i]]+l[i]<=f[u[i]][j];ans+=flag;}cout<<ans<<endl;return 0;
}