#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u) for(int i=fst[u];i;i=nxt[i])
#define MAXN 200001
#define MAXM 400001
int N,M,now[MAXN],key[MAXN][2],fst[MAXN],cnt,to[MAXM],nxt[MAXM],tot,dfn[MAXN],low[MAXN],top,sta[MAXN],Cnt,col[MAXN];bool in[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void add(int u,int v){to[++cnt]=v,nxt[cnt]=fst[u],fst[u]=cnt;}
void dfs(int u)
{
	dfn[u]=low[u]=++tot;sta[++top]=u;in[u]=1;FOR(i,u)!dfn[to[i]]?dfs(to[i]),0:0,in[to[i]]?low[u]=min(low[u],low[to[i]]):0;
	if(dfn[u]==low[u]){Cnt++;while(top){col[sta[top]]=Cnt;in[sta[top]]=0;if(sta[top--]==u)break;}}
}
int main()
{
	N=get(),M=get();For(i,1,N)now[i]=get();For(i,1,M){int x=get(),a;while(x--)a=get(),key[a][key[a][0]!=0]=i;}
	For(i,1,N)add(key[i][0],key[i][1]+M*(now[i]^1)),add(key[i][1],key[i][0]+M*(now[i]^1)),add(key[i][0]+M,key[i][1]+M*(now[i]&1)),add(key[i][1]+M,key[i][0]+M*(now[i]&1));
	For(i,1,M*2)if(!dfn[i])dfs(i);For(i,1,M)if(col[i]==col[i+M]){cout<<"NO\n";return 0;}cout<<"YES\n";return 0;
}