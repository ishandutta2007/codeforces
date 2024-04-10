#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <memory.h>
#include <ctime>
#include <set>
#include <cmath>

#define ll long long

using namespace std;

ll mod=1000000007;

ll n=3;

int rec(int pos = 0,int last = 1)
{
    if (pos==n) return 1;
    int ans=0;
    for(int i=last;i<=n;i++)
        ans+=rec(pos+1,i);
    return ans;
}

ll modPow(ll a,ll x)
{
    ll res=1;
    while(a>0)
    {
        if (a&1) res=(res*x)%mod;
        x=(x*x)%mod;
        a/=2;
    }
    return res;
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    cin >> n;
    n--;
    ll f1=1,f2=1,f3=1;
    for(ll i=2;i<=n;i++)
        f3=(f3*i)%mod;
    f1=(f3*(n+1))%mod;
    f2=f1;
    for(ll i=n+2;i<=2*n+1;i++)
        f2=(f2*i)%mod;
    ll res=(f2*modPow(mod-2,f1))%mod;
    res=(res*modPow(mod-2,f3))%mod;
//  cout << res << endl;
    cout << (res*2-n-1+mod)%mod << endl;
    return 0;
}