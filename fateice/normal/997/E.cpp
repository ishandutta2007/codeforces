#include<bits/stdc++.h>
#define L long long
using namespace std;
int n,m,t,x[120010],a[120010],p,b[120010],q;
L ans[120010];
struct ask
{
    int l,r,p;
}w[120010];
struct tag
{
    int t,u,ut,w;
    inline void yc(int tt)
    {
        if(w==u)
          ut+=tt-t;
        t=tt;
    }
    inline void plus(int x)
    {
        if(w==u)
          ut--;
        w+=x;
        if(w<u)
          u=w,ut=0;
        if(w==u)
          ut++;
    }
    inline void clear()
    {
        u=ut=w=0;
    }
}g[1050000];
struct orz
{
    int t,u,v;
    L p;
    inline void yc(int tt)
    {
        if(u==0)
          p+=(L)v*(tt-t);
        t=tt;
    }
    inline void plus(int x)
    {
        if(u==0)
          p-=v;
        u+=x;
        if(u==0)
          p+=v;
    }
}f[1050000],h;
inline bool cmp(ask a,ask b)
{
    return a.r<b.r;
}
inline void down(tag &a,tag &b)
{
    b.t=a.t;
    if(b.w+a.u<b.u)
      b.u=b.w+a.u,b.ut=0;
    if(b.w+a.u==b.u)
      b.ut+=a.ut;
    b.w+=a.w;
}
inline void down(tag &a,orz &b)
{
    b.t=a.t;
    if(b.u+a.u==0)
      b.p+=(L)a.ut*b.v;
    b.u+=a.w;
}
inline void merge(orz &a,orz &b,orz &c)
{
    a=b;
    if(c.u<a.u)
      a.u=c.u,a.v=0;
    if(c.u==a.u)
      a.v+=c.v;
    a.p+=c.p;
}
inline void make(int i,int j,int k,int p,orz h)
{
    g[i].yc(p);
    if(j==k)
      {
       g[i].clear();
       f[i]=h;
      }
    else
      {
       down(g[i],g[i<<1]);
       down(g[i],g[i<<1|1]);
       down(g[i],f[i<<1]);
       down(g[i],f[i<<1|1]);
       g[i].clear();
       if(p<=(j+k>>1))
         make(i<<1,j,j+k>>1,p,h);
       else
         make(i<<1|1,(j+k>>1)+1,k,p,h);
       merge(f[i],f[i<<1],f[i<<1|1]);
      }
    //cout<<i<<" "<<j<<" "<<k<<" "<<p<<"  "<<f[8].p<<" "<<f[8].u<<" "<<f[8].v<<" "<<f[8].t<<"!!\n";
    //if(i==1)
    //cout<<i<<" "<<j<<" "<<k<<" "<<p<<"  "<<f[1].p<<" "<<f[1].u<<" "<<f[1].v<<"!!\n";
}
inline void add(int i,int j,int k,int l,int r,int x,int t)
{
    g[i].yc(t);
    if(l<=j && k<=r)
      {
       g[i].plus(x);
       f[i].yc(t);
       f[i].plus(x);
      }
    else
      {
       down(g[i],g[i<<1]);
       down(g[i],g[i<<1|1]);
       down(g[i],f[i<<1]);
       down(g[i],f[i<<1|1]);
       g[i].clear();
       if(l<=(j+k>>1))
         add(i<<1,j,j+k>>1,l,r,x,t);
       if(r>(j+k>>1))
         add(i<<1|1,(j+k>>1)+1,k,l,r,x,t);
       merge(f[i],f[i<<1],f[i<<1|1]);
      }
    //if(i==1)
      //cout<<l<<" "<<r<<" "<<x<<" "<<t<<"  "<<f[1].p<<" "<<f[1].u<<" "<<f[1].v<<"\n";
}
inline L sum(int i,int j,int k,int l,int r,int t)
{
    g[i].yc(t);
    if(l<=j && k<=r)
      {
       f[i].yc(t);
       return f[i].p;
      }
    else
      {
       down(g[i],g[i<<1]);
       down(g[i],g[i<<1|1]);
       down(g[i],f[i<<1]);
       down(g[i],f[i<<1|1]);
       g[i].clear();
       L p=0;
       if(l<=(j+k>>1))
         p+=sum(i<<1,j,j+k>>1,l,r,t);
       if(r>(j+k>>1))
         p+=sum(i<<1|1,(j+k>>1)+1,k,l,r,t);
       return p;
      }
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  scanf("%d",&x[i]);
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	  scanf("%d%d",&w[i].l,&w[i].r),w[i].p=i;
	sort(w+1,w+m+1,cmp);
	for(t=1;t<n;t<<=1);
	for(i=1;i<2*t;i++)
	  f[i].u=1e9;
	for(i=1,j=1;i<=n;i++)
	  {
       h.t=i;
       h.u=0;
       h.v=1;
       h.p=1;
       make(1,1,t,i,h);
       while(p && x[i]>x[a[p]])
         {
          add(1,1,t,a[p-1]+1,a[p],x[i]-x[a[p]],i);
          p--;
         }
       a[++p]=i;
       while(q && x[i]<x[b[q]])
         {
          add(1,1,t,b[q-1]+1,b[q],x[b[q]]-x[i],i);
          q--;
         }
       b[++q]=i;
       if(i>1)
         add(1,1,t,1,i-1,-1,i);
       while(j<=m && w[j].r==i)
         {
          ans[w[j].p]=sum(1,1,t,w[j].l,w[j].r,i);
          j++;
         }
      }
    for(i=1;i<=m;i++)
      printf("%lld\n",ans[i]);
	return 0;
}