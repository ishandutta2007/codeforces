#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
const int inf=1e8;
int n,a[1500010],b[1500010],f[1500010],p;
struct st
{
    int f[2000010],g[2000010],x[2000010],ad[2000010],mi[2000010];
    L s[2000010];
    inline void down(int i,int k)
    {
        if(ad[i])
          {
           ad[i<<1]+=ad[i];
           mi[i<<1]+=ad[i];
           f[i<<1]+=ad[i];
           g[i<<1]+=ad[i];
           s[i<<1]+=(L)(k>>1)*ad[i];
           ad[(i<<1)|1]+=ad[i];
           mi[(i<<1)|1]+=ad[i];
           f[(i<<1)|1]+=ad[i];
           g[(i<<1)|1]+=ad[i];
           s[(i<<1)|1]+=(L)(k>>1)*ad[i];
           ad[i]=0;
          }
        if(mi[i]<f[i<<1])
          {
           mi[i<<1]=mi[i];
           s[i<<1]-=(L)x[i<<1]*(f[i<<1]-mi[i]);
           f[i<<1]=mi[i];
          }
        if(mi[i]<f[(i<<1)|1])
          {
           mi[(i<<1)|1]=mi[i];
           s[(i<<1)|1]-=(L)x[(i<<1)|1]*(f[(i<<1)|1]-mi[i]);
           f[(i<<1)|1]=mi[i];
          }
        mi[i]=inf;
    }
    inline void upd(int i)
    {
        s[i]=s[i<<1]+s[(i<<1)|1];
        f[i]=max(f[i<<1],f[(i<<1)|1]);
        x[i]=0;
        if(f[i]==f[i<<1])
          x[i]+=x[i<<1];
        if(f[i]==f[(i<<1)|1])
          x[i]+=x[(i<<1)|1];
        g[i]=-inf;
        if(f[i]==f[i<<1])
          g[i]=max(g[i],g[i<<1]);
        else
          g[i]=max(g[i],f[i<<1]);
        if(f[i]==f[(i<<1)|1])
          g[i]=max(g[i],g[(i<<1)|1]);
        else
          g[i]=max(g[i],f[(i<<1)|1]);
    }
    inline void add(int i,int j,int k,int l,int r,int p)
    {
        if(l<=j && k<=r)
          {
           ad[i]+=p;
           mi[i]+=p;
           f[i]+=p;
           g[i]+=p;
           s[i]+=(k-j+1)*p;
          }
        else
          {
           down(i,k-j+1);
           if(l<=(j+k>>1))
             add(i<<1,j,j+k>>1,l,r,p);
           if(r>(j+k>>1))
             add((i<<1)|1,(j+k>>1)+1,k,l,r,p);
           upd(i);
          }
    }
    inline void modify(int i,int j,int k,int l,int p)
    {
        if(j==k)
          {
           ad[i]=0;
           mi[i]=inf;
           f[i]=p;
           g[i]=0;
           x[i]=1;
           s[i]=p;
          }
        else
          {
           down(i,k-j+1);
           if(l<=(j+k>>1))
             modify(i<<1,j,j+k>>1,l,p);
           else
             modify((i<<1)|1,(j+k>>1)+1,k,l,p);
           upd(i);
          }
    }
    inline void minn(int i,int j,int k,int l,int r,int p)
    {
        if(p>=f[i])
          return;
        down(i,k-j+1);
        if(l<=j && k<=r && p>g[i])
          {
           mi[i]=p;
           s[i]-=(L)x[i]*(f[i]-p);
           f[i]=p;
          }
        else
          {
           if(l<=(j+k>>1))
             minn(i<<1,j,j+k>>1,l,r,p);
           if(r>(j+k>>1))
             minn((i<<1)|1,(j+k>>1)+1,k,l,r,p);
           upd(i);
          }
    }
}x,y;
inline void add(int i)
{
    for(;i<=n;i+=(i&-i))
      f[i]++;
}
inline int sum(int i)
{
    int k=0;
    for(;i;i^=(i&-i))
      k+=f[i];
    return k;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  scanf("%d",&a[i]),b[a[i]]=i;
	for(p=1;p<n;p<<=1);
	for(i=1;i<2*p;i++)
	  x.mi[i]=y.mi[i]=inf;
	for(i=1;i<=n;i++)
	  {
       x.f[p+i-1]=1;
       x.x[p+i-1]=1;
       x.s[p+i-1]=1;
       y.f[p+i-1]=n-1;
       y.x[p+i-1]=1;
       y.s[p+i-1]=n-1;
      }
    for(i=p-1;i>0;i--)
      {
       x.upd(i);
       y.upd(i);
      }
	for(i=1;i<=n;i++)
	  {
       j=b[i];
       add(b[i]);
       k=sum(b[i]);
       if(j<n)
         x.add(1,1,p,j+1,n,1);
       if(j>1)
         x.minn(1,1,p,1,j-1,k);
       x.modify(1,1,p,j,i+1);
       if(j<n)
         y.add(1,1,p,j+1,n,-1);
       if(j<n)
         y.minn(1,1,p,j+1,n,n-(k+1));
       y.modify(1,1,p,j,n-1);
       printf("%lld\n",x.s[1]-((L)n*n-y.s[1]));
      }
	return 0;
}