#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u) for(int i=fst[u];i;i=nxt[i])
#define MAXN 1001
#define MAXM 10000001
int T,N,a[MAXN][MAXN],fst[MAXN*4],cnt,to[MAXM],nxt[MAXM],tot,dfn[MAXN*4],low[MAXN*4],top,sta[MAXN*4],Cnt,col[MAXN*4];bool in[MAXN*4];
int get(){char c=getchar();while(c<'0'||c>'9')c=getchar();return c-'0';}
void add(int u,int v){to[++cnt]=v,nxt[cnt]=fst[u],fst[u]=cnt;}
void dfs(int u)
{
	dfn[u]=low[u]=++tot;sta[++top]=u;in[u]=1;FOR(i,u)!dfn[to[i]]?dfs(to[i]),0:0,in[to[i]]?low[u]=min(low[u],low[to[i]]):0;
	if(dfn[u]==low[u]){Cnt++;while(top){col[sta[top]]=Cnt;in[sta[top]]=0;if(sta[top--]==u)break;}}
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N*4)in[i]=fst[i]=dfn[i]=low[i]=col[i]=0;tot=Cnt=top=0;For(i,1,N)For(j,1,N)a[i][j]=get();
		For(i,1,N)For(j,1,N){int x=get()^a[i][j];x?add(i,j+N*3),add(j+N,i+N*2),add(i+N*2,j+N),add(j+N*3,i):(add(i,j+N),add(j+N,i),add(i+N*2,j+N*3),add(j+N*3,i+N*2));}
		For(i,1,N*4)if(!dfn[i])dfs(i);bool flag=1;For(i,1,N*2)if(col[i]==col[i+N*2]){cout<<"NO\n";flag=0;break;}if(flag)cout<<"YES\n";
	}
	return 0;
}