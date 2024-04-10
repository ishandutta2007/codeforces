#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,m,w[10010],a[5010],x[5010],s,f[10010],h[10010],p;
vi b[10010];
L ans;
inline void dp(int i)
{
    for(auto j:b[i])
      {
       dp(j);
       w[i]+=w[j];
      }
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,l;
	scanf("%d",&n);
	m=n;
	while(n--)
	  {
       scanf("%d",&i);
       w[max(i,1)]++;
      }
    n=p=5000;
    for(i=2;i<=n;i++)
      {
       for(j=2;i%j;j++);
       a[i]=j;
      }
    for(i=2;i<=n;i++)
      {
       for(j=i,k=a[j],l=x[k];j>1;j/=a[j])
         {
          if(j>a[j] && a[j]!=a[j/a[j]])
            {
             k=a[j/a[j]];
             l=x[k];
            }
          x[a[j]]++;
          s++;
         }
       h[i]=s;
       for(j=k+1;j<=i;j++)
         l+=x[j];
       for(j=i-1;h[j]>l;j=f[j])
         k=j;
       if(h[j]==l)
         f[i]=j;
       else
         {
          f[i]=++p;
          f[p]=j;
          f[k]=p;
          h[p]=l;
         }
       ans+=(L)w[i]*h[i];
      }
    for(i=1;i<=p;i++)
      b[f[i]].pb(i);
    dp(1);
    for(i=1,j=2;j<=p;j++)
      if(w[j]>m/2 && h[j]>h[i])
        i=j;
    for(;i>1;i=f[i])
      ans-=(L)(w[i]*2-m)*(h[i]-h[f[i]]);
    cout<<ans;
	return 0;
}