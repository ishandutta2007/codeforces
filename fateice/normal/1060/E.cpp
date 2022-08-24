#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,f[200010],f2[200010],x[200010],w[2];
vi a[200010];
L g[200010],g2[200010],p;
inline void dp(int i,int j)
{
    w[x[i]]++;
    f[i]=1;
    for(auto k:a[i])
      if(k!=j)
        {
         x[k]=x[i]^1;
         dp(k,i);
         f[i]+=f[k];
         g[i]+=g[k]+f[k];
        }
}
inline void dp2(int i,int j)
{
    for(auto k:a[i])
      if(k!=j)
        {
         g[k]+=g[i]-g[k]-f[k]+n-f[k];
         dp2(k,i);
        }
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
    dp(1,0);
    dp2(1,0);
    for(i=1;i<=n;i++)
      p+=(g[i]+w[x[i]^1])/2;
    cout<<p/2;
	return 0;
}