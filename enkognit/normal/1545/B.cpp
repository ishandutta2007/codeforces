#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("unroll-loops")
//#include "testlib.h"
//#pragma GCC optimize("popcnt")
#include <random>
#include <time.h>
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define ld long double

using namespace std;

mt19937_64 rnd(time(0));

ll MOD=998244353;
const ld E=1e-10;

ll n, m, k, T, a[500001], v[2];

ll binpow(ll h,ll r,ll md)
{
    ll l=1;
    while (r)
    {
        if (r&1) l=(l*h)%md;
        h=(h*h)%md;
        r/=2;
    }
    return l;
}

ll read()
{
    char c=getchar();
    while (!isdigit(c))
    {
        c=getchar();
    }
    ll res=0;
    while (isdigit(c))
    {
        res=res*10+c-'0';
        c=getchar();
    }
    return res;
}

ll gcd(ll x,ll y)
{
    while (x && y)
    {
        if (x<y) swap(x, y);
        x%=y;
    }
    return x+y;
}

ll fact[500001], infact[500001];

ll C(ll n,ll k)
{
    return fact[n]*infact[k]%MOD*infact[n-k]%MOD;
}

void solve()
{
    cin >> n;
    string s;
    cin >> s;
    s=' '+s;
    ll z=0, o=n, k=0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i]=='1')
        {
            k++;
        }else
        {
            if (k>0)
            {
                z+=k/2;
                if (k%2)
                {
                    o--;
                }
            }
            k=0;
        }
    }
    z+=k/2;
    if (k%2)
        o--;
    ll p=o-z*2;
    //cout << o << " " << z+p << " " << p << " " << z << "\n";
    cout << C(z+p,p) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fact[0]=1;
    infact[0]=1;
    for (int i = 1; i <= 1e5; i++)
    {
        fact[i]=fact[i-1]*i%MOD;
        infact[i]=binpow(fact[i], MOD-2, MOD);
    }
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}