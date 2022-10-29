#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pb push_back


using namespace std;

const ll MOD=1e9+7;

ll n, m, k, l, r, i, j, a[1000001];
vector <ll> c[200001];
bool tt[200001];
vector <pair<pll, pll> > v;
set <ll> s;

void dfs(ll h)
{
    tt[h]=1;
    s.erase(h);
    sort(c[h].begin(),c[h].end());
    for (int i = 0; i < c[h].size()-1; i++)
        if (s.size())
    {
        ll l=*s.lower_bound(c[h][i]+1);
        while (l<c[h][i+1])
        {
            dfs(l);
            if (s.size()) l=*s.lower_bound(c[h][i]+1); else break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n+1; i++) s.insert(i), c[i].pb(0), c[i].pb(n+1);
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    ll ans=-1;
    for (int i = 1; i <= n; i++)
        if (!tt[i])
        {
            dfs(i);
            ans++;
        }
    cout << ans;
}