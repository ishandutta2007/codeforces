#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
const int q=1000000007;
int n,m,p,r,t[100010],c[100010],d[100010],w[100010],u[100010],v[100010],f[100010][400],g[400][400];
bool o[100010];
vi a[100010],b[100010],x[400],y[100010];
map<vi,int> h;
inline void pre(int n,vi x)
{
    if(n==-1)
      {
       if(!h[x])
         {
          h[x]=++p;
          ::x[p]=x;
         }
       return;
      }
    vi y=x;
    pre(n-1,x);
    int i,j;
    for(i=(1<<n);i<(1<<n+1);i++)
      {
       x=y;
       x.pb(i);
       for(j=0;j<x.size()-1;j++)
         if(x[j]&(1<<n))
           x[j]^=i;
       pre(n-1,x);
      }
}
inline void dfs(int i,int j)
{
    int k;
    t[i]=r;
    for(k=0;k<a[i].size();k++)
      if(a[i][k]!=1 && a[i][k]!=j)
        if(!t[a[i][k]])
          {
           w[a[i][k]]=w[i]^b[i][k];
           dfs(a[i][k],i);
          }
        else if(i<a[i][k])
          y[r].pb(w[i]^w[a[i][k]]^b[i][k]);
}
inline int get(int i,int j)
{
    int k;
    for(k=0;k<a[i].size();k++)
      if(a[i][k]==j)
        return b[i][k];
}
inline bool cmp(int i,int j)
{
    return i>j;
}
inline int get(vi x)
{
    if(x.size()>5)
      return 0;
    int i,j;
    for(i=0;i<x.size();i++)
      {
       sort(x.begin(),x.end(),cmp);
       for(j=0;j<x.size();j++)
         if(i!=j)
           if(x[i]==x[j])
             return 0;
           else if((x[i]^x[j])<x[j])
             x[j]^=x[i];
      }
    return h[x];
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,l;
	pre(4,vi());
	//cerr<<p<<"\n";
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	  {
       scanf("%d%d%d",&j,&k,&l);
       a[j].pb(k);
       b[j].pb(l);
       a[k].pb(j);
       b[k].pb(l);
      }
    for(i=0;i<a[1].size();i++)
      if(!t[a[1][i]])
        {
         r++;
         c[r]=a[1][i];
         d[r]=b[1][i];
         dfs(a[1][i],1);
         u[r]=get(y[r]);
         //cout<<r<<" "<<u[r]<<"\n";
        }
      else
        {
         k=t[a[1][i]];
         y[k].pb(d[k]^b[1][i]^get(a[1][i],c[k]));
         v[k]=get(y[k]);
         o[k]=1;
         //cout<<r<<" "<<v[r]<<"\n";
        }
    for(i=1;i<=p;i++)
      for(j=1;j<=p;j++)
        {
         vi a=x[i];
         for(auto k:x[j])
           a.pb(k);
         g[i][j]=get(a);
        }
    f[1][1]=1;
    for(i=1;i<=r;i++)
      for(j=1;j<=p;j++)
        if(f[i][j])
        {
         f[i+1][j]=(f[i+1][j]+f[i][j])%q;
         k=g[j][u[i]];
         if(!o[i])
           f[i+1][k]=(f[i+1][k]+f[i][j])%q;
         else
           {
            f[i+1][k]=(f[i+1][k]+2ll*f[i][j])%q;
            k=g[j][v[i]];
            f[i+1][k]=(f[i+1][k]+f[i][j])%q;
           }
        }
    for(i=1,k=0;i<=p;i++)
      k=(k+f[r+1][i])%q;
    printf("%d\n",k);
	return 0;
}