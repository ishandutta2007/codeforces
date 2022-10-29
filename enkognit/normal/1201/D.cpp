#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>

using namespace std;

const ll MOD = 998244353;

ll n, m, k, lf[200001], rg[200001], q, p, ans, l, r, i, j, x, y, b[200001], dp[200001][2];
pll a[200001];
string s;
vector <ll> v[200001];
vector <pll> z;

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n >> m >> k >> q;
    if (k==0) {cout << 0;exit(0);}
    //ll z=k;
    for (int i = 0; i < k; i++)
    {
        ll x, y;
        cin >> x >> y;
        v[x].pb(y);
    }
    for (int i = 0; i < q; i++)
    {
        cin >> b[i];
    }
    sort(b,b+q);
    ll w=0;
    sort(v[1].begin(),v[1].end());
    if (v[1].size()) z.pb(mp(v[1][0],v[1][v[1].size()-1])), w=1; else z.pb(mp(1,1));

    for (int i = 2; i <= n; i++)
    {
        if (v[i].size())
        {
            sort(v[i].begin(),v[i].end());
            z.pb(mp(v[i][0], v[i][v[i].size()-1]));
            w=i;
        }
    }
    //cout << z[0].fi << " " << z[0].se << "\n";
    dp[0][0]=z[0].se+z[0].se-z[0].fi-1;
    dp[0][1]=z[0].se-1;

    //ll p=1;
    //cout << dp[0][0] << " " << dp[0][1] << "\n";
    for (int i = 1; i < z.size(); i++)
    {
        ll l1=z[i].fi, r1=z[i].se, l2=z[i-1].fi, r2=z[i-1].se, dst=1e18;
        dp[i][0]=1e18;dp[i][1]=1e18;

        ll rr=upper_bound(b,b+q,l2-1)-b, lr=rr-1;
        dst=1e18;
        if (rr<q) dst=min(dst, abs(b[rr]-l2) + abs(b[rr]-r1) + abs(r1-l1));
        if (lr>=0) dst=min(dst, abs(b[lr]-l2) + abs(b[lr]-r1) + abs(r1-l1));
        dp[i][0]=min(dp[i][0],dp[i-1][0]+dst);
        dst=1e18;
        if (rr<q) dst=min(dst, abs(b[rr]-l2) + abs(b[rr]-l1) + abs(r1-l1));
        if (lr>=0) dst=min(dst, abs(b[lr]-l2) + abs(b[lr]-l1) + abs(r1-l1));
        dp[i][1]=min(dp[i][1],dp[i-1][0]+dst);

        rr=upper_bound(b,b+q,r2-1)-b, lr=rr-1;
        dst=1e18;
        if (rr<q) dst=min(dst, abs(b[rr]-r2) + abs(b[rr]-r1) + abs(r1-l1));
        if (lr>=0) dst=min(dst, abs(b[lr]-r2) + abs(b[lr]-r1) + abs(r1-l1));
        dp[i][0]=min(dp[i][0],dp[i-1][1]+dst);
        dst=1e18;
        if (rr<q) dst=min(dst, abs(b[rr]-r2) + abs(b[rr]-l1) + abs(r1-l1));
        if (lr>=0) dst=min(dst, abs(b[lr]-r2) + abs(b[lr]-l1) + abs(r1-l1));
        dp[i][1]=min(dp[i][1],dp[i-1][1]+dst);

        //cout << dp[i][0] << " " << dp[i][1] << "\n";
    }
    cout << w+min(dp[z.size()-1][0],dp[z.size()-1][1]) - 1;
    return 0;
}


/*
2 4 4 2
1 2
1 4
2 3
2 1
1 3


*/