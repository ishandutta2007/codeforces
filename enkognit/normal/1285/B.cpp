#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define pll pair<ll,ll>
#define y1 Enkognit
#define fi first
#define se second
#define pld pair<ld,ld>

using namespace std;

const ll MOD=1000000007;

ll l, r, n, m, k, y, a[1000001], x[1000001], b[1000001];
bool dp[21][2000001];
vector <ll> an;
vector <ll> vv[1001];

ll binpow(ll h,ll r)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h,l%=MOD;
        h*=h;
        h%=MOD;
        r/=2;
    }
    return l;
}

ll d[10000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll p=0, sm=0, mx=-1e18;
        for (int i = 1; i <= n; i++)
        {
            ll x;
            cin >> x;
            sm+=x;
            if (sm<=0) p=1;
            if (i<n) mx=max(mx,sm);
        }
        if (!p && mx<sm) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}
/*
4
0 5 1
1 7 2
4 4 1
7 15 1
*/