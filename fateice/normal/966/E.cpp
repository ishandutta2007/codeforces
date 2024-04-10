#include<bits/stdc++.h>
#define L long long
#define pb push_back
const int M=400,inf=1000000000;
using namespace std;
int n,m,w[100010],ww[100010],f[255][200010],g[255];
vector<int> a[100010];
int x[100010],y[100010],p,v[100010],fa[100010],ff[100010],q;
inline void dp(int i,int j)
{
    v[i]=1;
    for(auto k:a[i])
      if(k!=j)
        {
         fa[k]=i;
         dp(k,i);
         v[i]+=v[k];
        }
}
inline void lp(int i,int j,int k)
{
    ff[i]=k;
    x[++p]=i;
    y[i]=p;
    int u=0;
    for(auto l:a[i])
      if(l!=j && v[l]>v[u])
        u=l;
    if(u)
      lp(u,i,k);
    for(auto l:a[i])
      if(l!=j && l!=u)
        lp(l,i,l);
}
inline void add1(int i)
{
    g[i]--;
    q-=f[i][g[i]];
}
inline void del1(int i)
{
    q+=f[i][g[i]];
    g[i]++;
}
inline void add2(int i,int k)
{
    if(w[k]>1e8)
      {
       w[k]++;
       return;
      }
    f[i][w[k]]--;
    w[k]++;
    f[i][w[k]]++;
    if(w[k]==g[i])
      q--;
}
inline void del2(int i,int k)
{
    if(w[k]>1e8)
      {
       w[k]--;
       return;
      }
    f[i][w[k]]--;
    w[k]--;
    f[i][w[k]]++;
    if(w[k]==g[i]-1)
      q++;
}
inline void orz1(int k)
{
    int i=k/M;
    if(w[k]<g[i])
      q--;
    f[i][w[k]]--;
    w[k]+=inf;
}
inline void orz2(int k)
{
    int i=k/M;
    w[k]-=inf;
    f[i][w[k]]++;
    if(w[k]<g[i])
      q++;
}
inline void add(int l,int r)
{
    int i=l/M,j=r/M,k;
    if(i==j)
      {
       for(k=l;k<=r;k++)
         add2(i,k);
       return;
      }
    for(k=i+1;k<j;k++)
      add1(k);
    for(k=l;k<(i+1)*M && k<=n;k++)
      add2(i,k);
    for(k=j*M;k<=r && k<=n;k++)
      add2(j,k);
}
inline void del(int l,int r)
{
    int i=l/M,j=r/M,k;
    if(i==j)
      {
       for(k=l;k<=r;k++)
         del2(i,k);
       return;
      }
    for(k=i+1;k<j;k++)
      del1(k);
    for(k=l;k<(i+1)*M && k<=n;k++)
      del2(i,k);
    for(k=j*M;k<=r && k<=n;k++)
      del2(j,k);
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=2;i<=n;i++)
	  {
       scanf("%d",&j);
       a[j].pb(i);
      }
    for(i=1;i<=n;i++)
      {
       scanf("%d",&ww[i]);
      }
    dp(1,0);
    lp(1,0,1);
    for(i=1;i<=n;i++)
      {
       w[i]=ww[x[i]];
       w[i]+=n;
       f[i/M][w[i]]++;
      }
    for(i=0;i<=n/M;i++)
      g[i]=n;
    //for(i=1;i<=n;i++)
      //cout<<i<<" "<<fa[i]<<" "<<ff[i]<<"\n";
    while(m--)
      {
       scanf("%d",&i);
       if(i>0)
         k=0;
       else
         i=-i,k=1;
       if(k)
         orz2(y[i]);
       else
         orz1(y[i]);
       for(;i>0;i=fa[j])
         {
          j=ff[i];
          //cout<<i<<" "<<j<<"\n";
          if(k)
            add(y[j],y[i]);
          else
            del(y[j],y[i]);
         }
       printf("%d ",q);
      }
	return 0;
}