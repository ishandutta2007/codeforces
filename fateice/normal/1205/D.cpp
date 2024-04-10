#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,m,f[1010],x[1010];
vi a[1010];
inline void dp(int i,int j)
{
    f[i]=1;
    for(auto k:a[i])
      if(k!=j)
        {
         dp(k,i);
         f[i]+=f[k];
        }
}
inline void dfs(int i,int j,int u,int v)
{
    printf("%d %d %d\n",i,j,u*v);
    int l=1;
    for(auto k:a[i])
      if(k!=j)
        {
         dfs(k,i,l,v);
         l+=f[k];
        }
}
inline bool cmp(int i,int j)
{
    return f[i]<f[j];
}
inline bool orz(int s)
{
    int i,j,k,l;
    dp(s,0);
    k=0;
    for(auto i:a[s])
      k=max(k,f[i]);
    if(k>n/2)
      return 0;
    k=0;
    for(auto i:a[s])
      x[++k]=i;
    sort(x+1,x+k+1,cmp);
    j=1;
    for(i=1;j-1<(n-1)/3;i++)
      {
       dfs(x[i],s,j,1);
       j+=f[x[i]];
      }
    l=1;
    for(;i<=k;i++)
      {
       dfs(x[i],s,l,j);
       l+=f[x[i]];
      }
    return 1;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d",&n);
	m=2*n*n/9;
	for(i=1;i<n;i++)
	  {
       scanf("%d%d",&j,&k);
       a[j].pb(k);
       a[k].pb(j);
      }
    for(i=1;i<=n;i++)
      if(orz(i))
        break;
	return 0;
}