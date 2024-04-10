#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define fi first
#define se second
#define pld pair<ld,ld>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 Enkognit
#define tm stanislavpolyn

using namespace std;

ll MOD=1e9+7;

ll n, m, k, l, r, T, i, j, kl, x, y;
ld ans;
ll tt[200001];
string s;
vector <ll> c[200001];
vector <pll> v;

void dfs(ll h)
{
    tt[h]=1;
    r=max(r,h);
    for (int i = 0; i < c[h].size(); i++)
        if (!tt[c[h][i]])
    {
        dfs(c[h][i]);
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    for (int i = 1; i <= n; i++)
        if (!tt[i])
        {
            l=i, r=i;
            dfs(i);
            v.pb(mp(l,r));
        }
    ll mx=0;
    ll ans=0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].fi<mx) ans++;
        mx=max(mx,v[i].se);
    }
    cout << ans;
    return 0;
}