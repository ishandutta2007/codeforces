#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ld long double
#define pll pair<ll,ll>
#define pld pair<ld,ld>

using namespace std;

const ll MOD=998244353;

ll n, m, k, l, r, ttt, x, y, i, T, t, j, kol, q;
ll a[1000001], b[100001], kl[1000001], ps[1000001];
ll tt[1000001];
vector<ll> v[1000001];

ll binpow(ll h,ll r)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h, l%=MOD;
        h*=h;
        h%=MOD;
        r/=2;
    }
    return l;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    ll ans=0, all=0;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        for (int j = 1; j <= x; j++)
        {
            ll y;
            cin >> y;
            tt[y]++;
            v[i].pb(y);
        }
        all=(all+binpow(x,MOD-2))%MOD;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
            ans=(ans+binpow(n,MOD-2)*binpow(v[i].size(),MOD-2)%MOD*binpow(n,MOD-2)%MOD*tt[v[i][j]]%MOD)%MOD;
    }

    //cout << ans << " " << all << "\n";
    //cout << 7*(binpow(8,MOD-2))%MOD << "\n";
    cout << ans%MOD;
    return 0;
}
/*
4
2
3
8
5
10
1
11
15
*/