#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ld long double
#define all(v) v.begin(),v.end()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))

using namespace std;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, m, k, o, T, Z, ZZ;

ll binpow(ll h,ll r,ll md=MOD)
{
    ll l=1;
    while (r)
    {
        if (r&1) l=(l*h)%MOD;
        h=(h*h)%MOD;
        r/=2;
    }
    return l;
}

void solve()
{
    cin >> n;
    ll p=0;
    for (int i = 2; i <= n; i++)
    {
        cout << "? 1 " << i-1 << "\n";
        cout << i << "\n";
        for (int j = 1; j < i; j++) cout << j << " ";
        cout << "\n";
        ll x;
        cin >> x;
        fflush(stdout);
        if (x!=0)
        {
            p=i;
            break;
        }
    }
    vector<ll> ans;
    for (int i = p+1; i <= n; i++)
    {
        cout << "? 1 1\n" << p << "\n" << i << "\n";
        ll x;
        cin >> x;
        fflush(stdout);
        if (x==0)
        {
            ans.pb(i);
        }
    }
    ll l=1, r=p-1;
    while (l<r)
    {
        ll w=(l+r)/2;
        cout << "? 1 " << w << "\n";
        cout << p << "\n";
        for (int i = 1; i <= w; i++) cout << i << " ";
        cout << "\n";
        ll x;
        cin >> x;
        fflush(stdout);
        if (x==0) l=w+1; else r=w;
    }
    for (int i = 1; i < p; i++)
        if (i!=l) ans.pb(i);
    cout << "! " << ans.size() << " ";
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << "\n";
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
10 10
1 3
3 5
5 7
7 9
2 9
1 4
4 6
6 8
8 10
2 10
*/