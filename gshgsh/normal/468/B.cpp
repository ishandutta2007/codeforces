#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u) for(int i=fst[u];i;i=nxt[i])
#define MAXN 200001
#define MAXM 400001
int N,A,B,a[MAXN],fst[MAXN],cnt,to[MAXM],nxt[MAXM],tot,dfn[MAXN],low[MAXN],top,sta[MAXN],Cnt,col[MAXN],ans;bool in[MAXN];map<int,int>pos;
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
	N=get(),A=get(),B=get();For(i,1,N)pos[a[i]=get()]=i;For(i,1,N)pos[A-a[i]]?pos[B-a[i]]?add(i,pos[B-a[i]]),0:0,add(i,pos[A-a[i]]):add(i,i+N),pos[B-a[i]]?pos[A-a[i]]?add(i+N,pos[A-a[i]]+N),0:0,add(i+N,pos[B-a[i]]+N):add(i+N,i);
	For(i,1,N*2)if(!dfn[i])dfs(i);For(i,1,N)if(col[i]==col[i+N]){cout<<"NO\n";return 0;}cout<<"YES\n";For(i,1,N)put(col[i]>col[i+N]),putchar(' ');return 0;
}