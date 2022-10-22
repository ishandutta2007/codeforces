#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u,f) for(int i=fst[u];i;i=nxt[i])if(to[i]!=f)
#define R (l+r>>1)
#define L (l+r>>1)+1
#define MAXN 300001
#define MAXM 10000001
int N,M,a[MAXN],v[MAXN],fst[MAXN],cnt,to[MAXN*2],nxt[MAXN*2],rt[MAXN],dep[MAXN],fa[MAXN],siz[MAXN],son[MAXN],top[MAXN],tot,ls[MAXM],rs[MAXM],sum[MAXM];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(int x){if(x<0)return putchar('-'),put(-x);if(x>=10)put(x/10);putchar(x%10+'0');}
void add(int u,int v){to[++cnt]=v,nxt[cnt]=fst[u],fst[u]=cnt;to[++cnt]=u,nxt[cnt]=fst[v],fst[v]=cnt;}
int New(int x){ls[++tot]=ls[x],rs[tot]=rs[x],sum[tot]=sum[x];return tot;}
int upd(int k,int l,int r,int x,int v){k=New(k);l!=r?x<=R?ls[k]=upd(ls[k],l,R,x,v):rs[k]=upd(rs[k],L,r,x,v),sum[k]=sum[ls[k]]^sum[rs[k]]:sum[k]^=v;return k;}
void dfs1(int u,int f){dep[u]=dep[f]+1;fa[u]=f;siz[u]=1;FOR(i,u,f)dfs1(to[i],u),siz[u]+=siz[to[i]],siz[to[i]]>siz[son[u]]?son[u]=to[i]:0;}
void dfs2(int u,int t){top[u]=t;rt[u]=upd(rt[fa[u]],1,N,a[u],v[a[u]]);if(!son[u])return;dfs2(son[u],t);FOR(i,u,fa[u])if(to[i]!=son[u])dfs2(to[i],to[i]);}
int lca(int x,int y){while(top[x]!=top[y]){if(dep[top[x]]<dep[top[y]])swap(x,y);x=fa[top[x]];}return dep[x]<dep[y]?x:y;}
int ask(int a,int b,int c,int d,int l,int r){return l!=r?sum[ls[a]]^sum[ls[b]]^sum[ls[c]]^sum[ls[d]]?ask(ls[a],ls[b],ls[c],ls[d],l,R):ask(rs[a],rs[b],rs[c],rs[d],L,r):l;}
int sol(int a,int b,int c,int d,int l,int r,int x,int y)
{
	if(l==x&&r==y)return sum[a]^sum[b]^sum[c]^sum[d]?ask(a,b,c,d,l,r):-1;
	if(y<=R)return sol(ls[a],ls[b],ls[c],ls[d],l,R,x,y);if(x>=L)return sol(rs[a],rs[b],rs[c],rs[d],L,r,x,y);
	int tmp=sol(ls[a],ls[b],ls[c],ls[d],l,R,x,R);return tmp!=-1?tmp:sol(rs[a],rs[b],rs[c],rs[d],L,r,L,y);
}
int main()
{
	srand(time(0));N=get(),M=get();For(i,1,N)a[i]=get(),v[i]=(rand()<<16)|rand();For(i,1,N-1)add(get(),get());dfs1(1,0);dfs2(1,1);
	For(i,1,M){int u=get(),v=get(),l=get(),r=get(),x=lca(u,v);put(sol(rt[u],rt[v],rt[x],rt[fa[x]],1,N,l,r)),putchar('\n');}return 0;
}