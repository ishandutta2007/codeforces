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

ll l, r, n, m, k, x, y, a[1000001], dk[1000001][2];
ll tt[1000001], ta[1000001];
vector <ll> an;

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

vector<pll> v;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    v.pb(mp(-2e9,a[1]-1));
    for (int i = 1; i < n; i++)
    {
        v.pb(mp(a[i]+1,a[i+1]-1));
    }
    v.pb(mp(a[n]+1,2e9));
    ll j=m, p=1;
    vector<ll> an;
    ll ans=0;
    while (j)
    {
        vector<pll> z;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].fi<=v[i].se && j && i!=0) ans+=p, an.pb(v[i].fi), v[i].fi++, j--;
            if (v[i].fi<=v[i].se && j && i!=v.size()-1) ans+=p, an.pb(v[i].se), v[i].se--, j--;
            if (v[i].fi<=v[i].se) z.pb(v[i]);
        }
        v=z;
        p++;
    }
    cout << ans << "\n";
    sort(an.begin(),an.end());
    for (int i = 0; i < an.size(); i++) cout << an[i] << " ";
    return 0;
}