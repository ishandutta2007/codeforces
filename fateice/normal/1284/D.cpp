#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,a[200010],b[100010],c[200010],d[100010],x[200010],f[1000010],g[1000010],p;
map<int,int> h;
inline bool cmp(int i,int j)
{
    return a[i]+0.5*(i>n)<a[j]+0.5*(j>n);
}
inline void add(int i,int j,int k,int l,int r)
{
    f[i]=1;
    if(l<=j && k<=r)
      g[i]=1;
    else
      {
       if(l<=(j+k>>1))
         add(i<<1,j,j+k>>1,l,r);
       if(r>(j+k>>1))
         add((i<<1)|1,(j+k>>1)+1,k,l,r);
      }
}
inline int sum(int i,int j,int k,int l,int r)
{
    if(g[i]==1)
      return 1;
    if(l<=j && k<=r)
      return f[i];
    else
      {
       int p=0;
       if(l<=(j+k>>1))
         p+=sum(i<<1,j,j+k>>1,l,r);
       if(r>(j+k>>1))
         p+=sum((i<<1)|1,(j+k>>1)+1,k,l,r);
       return p;
      }
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
      scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]),x[2*i-1]=c[i],x[2*i]=d[i];
    sort(x+1,x+n+n+1);
    for(i=1;i<=2*n;i++)
      h[x[i]]=i;
    for(i=1;i<=n;i++)
      c[i]=h[c[i]],d[i]=h[d[i]];
    for(i=1;i<=n;i++)
      x[2*i-1]=a[i],x[2*i]=b[i];
    sort(x+1,x+n+n+1);
    for(i=1;i<=2*n;i++)
      h[x[i]]=i;
    for(i=1;i<=n;i++)
      a[i]=h[a[i]],b[i]=h[b[i]];
    for(i=n+1;i<=2*n;i++)
      a[i]=b[i-n],c[i]=d[i-n];
    for(p=1;p<2*n;p<<=1);
    for(i=1;i<=2*n;i++)
      x[i]=i;
    sort(x+1,x+2*n+1,cmp);
    for(i=1;i<=2*n;i++)
      if(x[i]>n)
        add(1,1,p,c[x[i]-n],d[x[i]-n]);
      else
        if(sum(1,1,p,c[x[i]],d[x[i]]))
          {
           printf("NO\n");
           return 0;
          }
    for(i=1;i<=2*p;i++)
      f[i]=g[i]=0;
    for(i=2*n;i>0;i--)
      if(x[i]<=n)
        add(1,1,p,c[x[i]],d[x[i]]);
      else
        if(sum(1,1,p,c[x[i]-n],d[x[i]-n]))
          {
           printf("NO\n");
           return 0;
          }
    for(i=1;i<=2*p;i++)
      f[i]=g[i]=0;
    for(i=1;i<=2*n;i++)
      swap(a[i],c[i]);
    for(i=1;i<=n;i++)
      swap(b[i],d[i]);
    sort(x+1,x+2*n+1,cmp);
    for(i=1;i<=2*n;i++)
      if(x[i]>n)
        add(1,1,p,c[x[i]-n],d[x[i]-n]);
      else
        if(sum(1,1,p,c[x[i]],d[x[i]]))
          {
           printf("NO\n");
           return 0;
          }
    for(i=1;i<=2*p;i++)
      f[i]=g[i]=0;
    for(i=2*n;i>0;i--)
      if(x[i]<=n)
        add(1,1,p,c[x[i]],d[x[i]]);
      else
        if(sum(1,1,p,c[x[i]-n],d[x[i]-n]))
          {
           printf("NO\n");
           return 0;
          }
    for(i=1;i<=2*p;i++)
      f[i]=g[i]=0;
    printf("YES\n");
    return 0;
}