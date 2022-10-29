#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pii pair<int,int>
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))
#define y1 Enkognit
#define y2 based

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, m, k, sz, a[300005], kol[300005], kl[300005], ans[300005];

ll binpow(ll h,ll r,ll md)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h, l%=md;
        h*=h;
        h%=md;
        r/=2;
    }
    return l;
}

ll K=600;

bool cmp(pair<pll, ll> x,pair<pll, ll> y)
{
    return x.fi.se>y.fi.se || x.fi.se==y.fi.se && x.fi.fi>y.fi.fi;
}

void solve()
{
    //n=read();
    //m=read();
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<pair<pll, ll> > z;
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        z.pb(mp(mp(x, y), i));
    }
    sort(all(z));
    ll l=0;
    for (int i = 0; i < K && l<z.size(); i++)
    {
        ll r=l;
        while (r+1<z.size() && z[r+1].fi.fi/K==z[r].fi.fi/K)
            r++;
        sort(z.begin()+l,z.begin()+r,cmp);
        l=r+1;
    }
    ll mx=0;
    ll x=1, y=0;
    for (int i = 0; i < z.size(); i++)
    {
        ll l=z[i].fi.fi, r=z[i].fi.se;
        while (y<r)
        {
            y++;
            kl[kol[a[y]]]--;
            kol[a[y]]++;
            kl[kol[a[y]]]++;
            while (kl[mx+1]) mx++;
        }

        while (x>l)
        {
            x--;
            kl[kol[a[x]]]--;
            kol[a[x]]++;
            kl[kol[a[x]]]++;
            while (kl[mx+1]) mx++;
        }

        while (y>r)
        {
            kl[kol[a[y]]]--;
            kol[a[y]]--;
            kl[kol[a[y]]]++;
            y--;
            while (kl[mx]==0) mx--;
        }

        while (x<l)
        {
            kl[kol[a[x]]]--;
            kol[a[x]]--;
            kl[kol[a[x]]]++;
            x++;
            while (kl[mx]==0) mx--;
        }

        if (mx>(r-l+2)/2)
            ans[z[i].se]=(mx-(r-l+1-mx)); else
            ans[z[i].se]=1;
    }

    for (int i = 1; i <= m; i++)
        cout << ans[i] << "\n";
    cout << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
        //cout << "-\n";
    }
    return 0;
}
/*

*/