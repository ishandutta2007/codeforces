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

const ll MOD=1e9+7;

ll n, m, k, T, TT;

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

map<int, int> s[500005];

void solve()
{
    cin >> n;
    string ss;
    cin >> ss;
    ss=' '+ss;
    ll k1=0, k2=0;
    vector<pll> v;
    for (int i = 1; i <= n; i++)
    {
        if (ss[i]=='D') k1++; else k2++;
        ll p1=k1, p2=k2, u=0;
        ll o=gcd(p1, p2);
        v.pb(mp(p1, p2));
        p1/=o, p2/=o;
        if (s[p1].find(p2)!=s[p1].end())
            u=s[p1][p2];
        u++;
        cout << u << " ";
        s[p1][p2]++;
    }
    for (int i = 0; i < v.size(); i++)
        s[v[i].fi].clear();
    cout << "\n";
}

int main(int argc, char **argv) {
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
/*
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
*/