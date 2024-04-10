#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u) for(int i=fst[u];i;i=nxt[i])
#define MAXN 201
#define MAXM 20001
int N,M,fst[MAXN],cnt,to[MAXM],nxt[MAXM],tot,dfn[MAXN],low[MAXN],top,sta[MAXN],Cnt,col[MAXN],ans;bool in[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(int x){if(x>=10)put(x/10);putchar(x%10+'0');}
void add(int u,int v){to[++cnt]=v,nxt[cnt]=fst[u],fst[u]=cnt;}
void dfs(int u)
{
	dfn[u]=low[u]=++tot;sta[++top]=u;in[u]=1;FOR(i,u)!dfn[to[i]]?dfs(to[i]),0:0,in[to[i]]?low[u]=min(low[u],low[to[i]]):0;
	if(dfn[u]==low[u]){Cnt++;while(top){col[sta[top]]=Cnt;in[sta[top]]=0;if(sta[top--]==u)break;}}
}
int main()
{
	N=get(),M=get();For(i,1,M){int u=get(),v=get(),t=get();add(u,v+N*(t^1)),add(u+N,v+N*(t&1)),add(v,u+N*(t^1)),add(v+N,u+N*(t&1));}For(i,1,N*2)if(!dfn[i])dfs(i);
	For(i,1,N)if(col[i]==col[i+N]){cout<<"Impossible\n";return 0;}For(i,1,N)ans+=col[i]<col[i+N];put(ans),putchar('\n');For(i,1,N)if(col[i]<col[i+N])put(i),putchar(' ');return 0;
}