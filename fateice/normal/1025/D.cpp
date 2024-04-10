#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,x[710];
bool a[710][710],f[710][710],g[710][710];
inline int gcd(int n,int m)
{
    return m?gcd(m,n%m):n;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,l;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  scanf("%d",&x[i]);
	for(i=1;i<=n;i++)
	  for(j=1;j<=n;j++)
	    if(gcd(x[i],x[j])>1)
	      a[i][j]=1;
	for(i=1;i<=n;i++)
	  f[i][i]=g[i][i]=1;
	for(l=1;l<n;l++)
	  for(i=1;i+l<=n;i++)
	    {
         j=i+l;
         for(k=i+1;k<=j;k++)
           f[i][j]|=a[i][k]&f[k][j]&g[i+1][k];
         for(k=i;k<j;k++)
           g[i][j]|=a[k][j]&f[k][j-1]&g[i][k];
        }
    for(i=1;i<=n;i++)
      if(f[i][n]&g[1][i])
        break;
    if(i<=n)
      printf("Yes\n");
    else
      printf("No\n");
	return 0;
}