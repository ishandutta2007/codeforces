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

ll n, m, k, T, a[200005], b[200005];

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

char rev(char c)
{
    if (c=='R') return 'B'; else return 'R';
}

void solve()
{
    cin >> n;
    string s;
    cin >> s;
    s=' '+s;
    ll k=0;
    ll ans=0;
    for (int i = 1; i < n; i++)
        if (s[i]!='?' && s[i+1]!='?' && s[i]==s[i+1]) ans++;
    vector<pll> v;
    for (int i = 1; i <= n; i++)
    {
        if (s[i]=='?')
        {
            if (k==0)
                v.pb(mp(i, i)), k=1;
            else v.back().se++;
        }else
        {
            k=0;
        }
    }
    for (int i = 0; i < v.size(); i++)
        if (v[i].fi>1)
        {
            for (int j = v[i].fi; j <= v[i].se; j++)
                if ((j-v[i].fi)%2) s[j]=s[v[i].fi-1]; else s[j]=rev(s[v[i].fi-1]);
        }else
        if (v[i].se<n)
        {
            for (int j = v[i].fi; j <= v[i].se; j++)
                if ((v[i].se-j)%2) s[j]=s[v[i].se+1]; else s[j]=rev(s[v[i].se+1]);
        }else
        {
            for (int j = 1; j <= n; j++)
                if (j%2) s[j]='B'; else s[j]='R';
        }
    s.erase(s.begin());
    cout << s << "\n";
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