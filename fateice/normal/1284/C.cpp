#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,q,p,a[250010];
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    int i;
    scanf("%d%d",&n,&q);
    a[0]=1;
    for(i=1;i<=n;i++)
      a[i]=(L)a[i-1]*i%q;
    for(i=1;i<=n;i++)
      p=(p+(L)(n-i+1)*a[n-i+1]%q*a[i])%q;
    cout<<p;
    return 0;
}