#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u,f) for(int i=fst[u];i;i=nxt[i])if(to[i]!=f)
#define MAXN 200001
int N,a[MAXN],fst[MAXN],cnt,to[MAXN*2],nxt[MAXN*2],c[MAXN],tot,dfn[MAXN],siz[MAXN];map<int,int>Cnt,now;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void add(int u,int v){to[++cnt]=v,nxt[cnt]=fst[u],fst[u]=cnt;to[++cnt]=u,nxt[cnt]=fst[v],fst[v]=cnt;}
void dfs(int u,int f)
{
	dfn[u]=++tot,siz[u]=1;int lst=now[a[u]];now[a[u]]++;
	FOR(i,u,f){int tmp=now[a[u]];dfs(to[i],u);siz[u]+=siz[to[i]];if(now[a[u]]>tmp)c[1]++,c[dfn[to[i]]]--,c[dfn[to[i]]+siz[to[i]]]++;}
	if(now[a[u]]-lst<Cnt[a[u]])c[dfn[u]]++,c[dfn[u]+siz[u]]--;
}
int main(){N=get();For(i,1,N)Cnt[a[i]=get()]++;For(i,1,N-1)add(get(),get());dfs(1,0);int ans=0;For(i,1,N)c[i]+=c[i-1],ans+=!c[i];cout<<ans<<endl;return 0;}