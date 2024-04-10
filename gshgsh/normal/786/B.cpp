#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u) for(int i=fst[u];i;i=nxt[i])
#define Pair pair<ll,int>
#define F first
#define S second
#define ls(x) x<<1
#define rs(x) x<<1|1
#define R (l+r>>1)
#define L (l+r>>1)+1
#define INF 0x3fffffffffffffff
#define MAXN 1000001
#define MAXM 10000001
int N,M,S,tot,fst[MAXN],cnt,to[MAXM],len[MAXM],nxt[MAXM],in[MAXN],out[MAXN];ll dis[MAXN];bool vis[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(ll x){if(x<0)return putchar('-'),put(-x);if(x>=10)put(x/10);putchar(x%10+'0');}
void add(int u,int v,int l){to[++cnt]=v,len[cnt]=l,nxt[cnt]=fst[u],fst[u]=cnt;}
void build(int k,int l,int r){l!=r?in[k]=++tot,out[k]=++tot,build(ls(k),l,R),build(rs(k),L,r),add(in[k],in[ls(k)],0),add(in[k],in[rs(k)],0),add(out[ls(k)],out[k],0),add(out[rs(k)],out[k],0),0:in[k]=out[k]=l;}
void upd(int k,int l,int r,int x,int y,int v,int w,int type){l<=y&&r>=x?l<x||r>y?upd(ls(k),l,R,x,y,v,w,type),upd(rs(k),L,r,x,y,v,w,type):type?add(out[k],v,w):add(v,in[k],w),0:0;}
int main()
{
	N=tot=get(),M=get(),S=get();build(1,1,N);For(i,1,M){int opt=get(),x=get(),y=get(),z=get();opt==1?add(x,y,z):upd(1,1,N,y,z,x,get(),opt&1);}
	For(i,1,tot)dis[i]=INF;dis[S]=0;priority_queue<Pair,vector<Pair>,greater<Pair> >q;q.push({0,S});
	while(!q.empty())if(!vis[q.top().S]){int u=q.top().S;vis[u]=1;FOR(i,u)if(dis[to[i]]>dis[u]+len[i])dis[to[i]]=dis[u]+len[i],q.push({dis[to[i]],to[i]});}else q.pop();
	For(i,1,N)put(dis[i]==INF?-1:dis[i]),putchar(' ');return 0;
}