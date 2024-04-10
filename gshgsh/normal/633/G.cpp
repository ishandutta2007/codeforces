#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<bitset>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define ls(x) x<<1
#define rs(x) x<<1|1
#define R (l+r>>1)
#define L (l+r>>1)+1
#define MAXN 100001
#define MAXM 1001
int N,M,a[MAXN],tot,dfn[MAXN],siz[MAXN],tg[MAXN*4];bitset<MAXM>prm,sum[MAXN*4];vector<int>E[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void dfs(int u,int f){dfn[u]=++tot;siz[u]=1;for(auto v:E[u])if(v!=f)dfs(v,u),siz[u]+=siz[v];}
void build(int k,int l,int r){sum[k][0]=1;if(l!=r)build(ls(k),l,R),build(rs(k),L,r);}
void pt(int k,int v){tg[k]=(tg[k]+v)%M;sum[k]=sum[k]>>M-v|sum[k]<<v;}void dwn(int k){if(tg[k])pt(ls(k),tg[k]),pt(rs(k),tg[k]),tg[k]=0;}
void upd(int k,int l,int r,int x,int y,int v){if(l>=x&&r<=y)return pt(k,v);dwn(k);x<=R&&(upd(ls(k),l,R,x,y,v),0),y>=L&&(upd(rs(k),L,r,x,y,v),0),sum[k]=sum[ls(k)]|sum[rs(k)];}
auto ask(int k,int l,int r,int x,int y){if(l>=x&&r<=y)return sum[k];dwn(k);bitset<MAXM>ans;x<=R&&(ans|=ask(ls(k),l,R,x,y),0),y>=L&&(ans|=ask(rs(k),L,r,x,y),0);return ans;}
int main()
{
	N=get(),M=get();For(i,2,M-1)prm[i]=1;For(i,2,M-1)if(prm[i])for(int j=i*2;j<M;j+=i)prm[j]=0;
	For(i,1,N)a[i]=get()%M;For(i,1,N-1){int u=get(),v=get();E[u].push_back(v),E[v].push_back(u);}
	dfs(1,0);build(1,1,N);For(i,1,N)upd(1,1,N,dfn[i],dfn[i],a[i]);
	int Q=get();while(Q--){int opt=get(),x=get();if(opt==1)upd(1,1,N,dfn[x],dfn[x]+siz[x]-1,get()%M);else cout<<(ask(1,1,N,dfn[x],dfn[x]+siz[x]-1)&prm).count()<<'\n';}
}