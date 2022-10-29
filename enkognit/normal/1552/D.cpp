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

ll n, m, k, T;

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

bool tt[1001];

void solve()
{
    cin >> n;
    vector<ll> a;
    bool tt=0;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        x=abs(x);
        if (x==0)
        {
            tt=1;
        }
        a.pb(x);
    }
    sort(all(a));
    if (tt)
    {
        cout << "YES\n";
        return;
    }
    for (int i = 0; i < a.size()-1; i++)
    {
        if (a[i]==a[i+1])
        {
            cout << "YES\n";
            return;
        }
    }
    //cout << (1<<((ll)a.size())) << "\n";
    for (int i = 1; i < (1<<((ll)a.size())); i++)
    {
        //cout << " " << i << "\n";
        ll x=i, o=0, j=0, z=0;
        while (x)
        {
            if (x%2) z+=a[j], o++;
            j++;
            x/=2;
        }
        //cout << i << " : " << z << "\n";
        for (int ii = 1; ii < (1<<((ll)a.size())); ii++)
            if (ii!=i)
            {
                //cout << " " << i << "\n";
                ll x=ii, o=0, j=0, zz=0;
                while (x)
                {
                    if (x%2) zz+=a[j], o++;
                    j++;
                    x/=2;
                }
                //cout << i << " : " << z << "\n";
                if (z==zz)
                {
                    cout << "YES\n";
                    return;
                }
            }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}