#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u) for(int i=fst[u];i;i=nxt[i])
#define MAXN 201
#define MAXM 100001
int N,M,l[MAXN],r[MAXN],fst[MAXN],cnt,to[MAXM],nxt[MAXM],tot,dfn[MAXN],low[MAXN],top,sta[MAXN],Cnt,col[MAXN];bool in[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void add(int u,int v){to[++cnt]=v,nxt[cnt]=fst[u],fst[u]=cnt;}
void dfs(int u)
{
	dfn[u]=low[u]=++tot;sta[++top]=u;in[u]=1;FOR(i,u)!dfn[to[i]]?dfs(to[i]),0:0,in[to[i]]?low[u]=min(low[u],low[to[i]]):0;
	if(dfn[u]==low[u]){Cnt++;while(top){col[sta[top]]=Cnt;in[sta[top]]=0;if(sta[top--]==u)break;}}
}
int main()
{
	N=get(),M=get();For(i,1,M)l[i]=get(),r[i]=get(),l[i]>r[i]?swap(l[i],r[i]),0:0;For(i,1,M)For(j,1,M)if((l[i]<l[j]&&r[i]>l[j]&&r[i]<r[j])||(l[i]>l[j]&&l[i]<r[j]&&r[i]>r[j]))add(i,j+M),add(i+M,j);
	For(i,1,M*2)if(!dfn[i])dfs(i);For(i,1,M)if(col[i]==col[i+M]){cout<<"Impossible\n";return 0;}For(i,1,M)putchar(col[i]<col[i+M]?'i':'o');return 0;
}