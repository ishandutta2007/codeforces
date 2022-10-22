#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 300001
int N,M,a[MAXN],b[MAXN],p[MAXN],v[MAXN],ans[MAXN],rt,tot,ls[MAXN],rs[MAXN],id[MAXN],val[MAXN],val2[MAXN],tg[MAXN],tg2[MAXN],siz[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int New(int v,int x){tot++;val[tot]=v;val2[tot]=rand();id[tot]=x;siz[tot]=1;return tot;}
void dwn(int u){if(u)ans[id[ls[u]]]+=tg[u],ans[id[rs[u]]]+=tg[u],val[ls[u]]+=tg2[u],val[rs[u]]+=tg2[u],tg[ls[u]]+=tg[u],tg[rs[u]]+=tg[u],tg2[ls[u]]+=tg2[u],tg2[rs[u]]+=tg2[u],tg[u]=tg2[u]=0;}
void upd(int u){if(u)siz[u]=siz[ls[u]]+siz[rs[u]]+1,dwn(u);}
int mrg(int x,int y){if(!x||!y)return x+y;dwn(x),dwn(y);if(val2[x]>val2[y])return rs[x]=mrg(rs[x],y),upd(x),x;return ls[y]=mrg(x,ls[y]),upd(y),y;}
void split(int x,int&a,int&b,int v){if(!x){a=b=0;return;}dwn(x);if(val[x]<=v)a=x,split(rs[x],rs[a],b,v);else b=x,split(ls[x],a,ls[b],v);upd(a),upd(b);}
void insert(int&rt,int v,int x){int a,b;split(rt,a,b,v);rt=mrg(mrg(a,New(v,x)),b);}
void insert(int&rt,int u){int a,b;split(rt,a,b,val[u]);rt=mrg(mrg(a,u),b);}
void ins(int&rt,int u,int v){if(!u)return;dwn(u);ins(rt,ls[u],v);ins(rt,rs[u],v);ls[u]=rs[u]=0,siz[u]=1;ans[id[u]]++,val[u]-=v;insert(rt,u);}
void Ask(int x){if(!x)return;dwn(x);Ask(ls[x]);Ask(rs[x]);}
int main()
{
	N=get();For(i,1,N)a[i]=get(),b[i]=get(),p[i]=i;sort(p+1,p+N+1,[&](int x,int y){return b[x]!=b[y]?b[x]>b[y]:a[x]<a[y];});
	M=get();For(i,1,M)v[i]=get(),insert(rt,v[i],i);
	For(i,1,N)
	{
		int c=a[p[i]],x,y,z;split(rt,x,y,c-1);split(y,y,z,c*2-1);val[z]-=c,ans[id[z]]++,tg[z]++,tg2[z]-=c;
		ins(x,y,c);rt=mrg(x,z);
	}
	Ask(rt);For(i,1,M)cout<<ans[i]<<" \n"[i==M];return 0;
}