#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,x[3010][3010],w[3010][3010];
L f[3010][3010],p;
vi a[3010];
inline void dfs(int i,int j,int k,int l)
{
    x[k][i]=l;
    w[k][i]=1;
    for(auto u:a[i])
      if(u!=j)
        {
         dfs(u,i,k,l+1);
         w[k][i]+=w[k][u];
        }
}
inline void dp(int i,int j)
{
    for(auto k:a[i])
      if(x[k][j]>x[i][j])
        {
         if(!f[k][j])
           dp(k,j);
         f[i][j]=max(f[i][j],f[k][j]);
        }
    for(auto k:a[j])
      if(x[k][i]>x[i][j])
        {
         if(!f[k][i])
           dp(k,i);
         f[i][j]=max(f[i][j],f[k][i]);
        }
    f[i][j]+=w[i][j]*w[j][i];
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	  {
	   scanf("%d%d",&j,&k);
	   a[j].pb(k);
	   a[k].pb(j);
      }
    for(i=1;i<=n;i++)
      dfs(i,0,i,0);
    for(i=1;i<n;i++)
      for(auto j:a[i])
        if(i<j)
          {
           dp(i,j);
           p=max(p,f[i][j]);
          }
    cout<<p;
	return 0;
}