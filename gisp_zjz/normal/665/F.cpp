#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll maxn=1e11;
const ll maxp=sqrt(maxn)+10;
ll f[maxp],g[maxp];

ll solve(ll n)
{
    ll i,j,m;
    for (m=1;m*m<=n;m++) f[m]=n/m-1;
    for (i=1;i<=m;i++) g[i]=i-1;
    for (i=2;i<=m;i++)
    {
        if (g[i]==g[i-1]) continue;
        for (j=1;j<=min(m-1,n/i/i);j++)
            if (i*j<m) f[j]-=f[i*j]-g[i-1]; else f[j]-=g[n/i/j]-g[i-1];
        for (j=m;j>=i*i;j--) g[j]-=g[j/i]-g[i-1];
    }
    ll res=0;
    for (i=2;i<m;i++)
    {
        if (g[i]==g[i-1]) continue;
        res+=f[i]-g[i];
    }
    j=(int)pow(n,1.0/3);
    return res+g[j];
}

int main()
{
    ll n;
    scanf("%lld",&n);
    cout << solve(n) << endl;
    return 0;
}