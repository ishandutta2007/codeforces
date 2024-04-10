#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,m;
L x[100010],s[100010];
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    L i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
      scanf("%lld",&x[i]);
    sort(x+1,x+n+1);
    for(i=1;i<n;i++)
      x[i]=x[i+1]-x[i];
    x[n]=2e18;
    sort(x+1,x+n+1);
    for(i=1;i<=n;i++)
      s[i]=s[i-1]+x[i];
    scanf("%d",&m);
    while(m--)
      {
       scanf("%lld%lld",&i,&j);
       i=j-i+1;
       j=lower_bound(x+1,x+n+1,i)-x-1;
       printf("%lld ",s[j]+(L)(n-j)*i);
      }
    return 0;
}