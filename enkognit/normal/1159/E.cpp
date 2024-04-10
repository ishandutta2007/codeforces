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
#define pii pair<int,int>

using namespace std;

const ll MOD=1e9+7;

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

ll n, m, T, k, l, r, i, j, O, kol=0, a[1000001], f[2000001], tt[1000001];
vector <ll> c[1000001];
void update(ll h)
{
    for (int i = h; i <= n; i+=(i&-i)) f[i]++;
}

ll get(ll h)
{
    ll ans=0;
    for (int i = h; i > 0; i-=(i&-i)) ans+=f[i];
    return ans;
}

void dfs(ll h)
{
    tt[h]=T;
    update(h);
    T--;
    for (int i = 0; i < c[h].size(); i++)
    {
        if (get(h-1)-get(c[h][i])>0) {O=1;return;}
        dfs(c[h][i]);
        if (O) return;
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n+1; i++)  c[i].clear(), tt[i]=0;
    for (int i = 0; i <= n; i++) f[i]=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c[a[i]].pb(i);
    }
    T=n+1;
    for (int i = n+1; i > 0; i--) if (!tt[i]) dfs(i);
    if (O) {cout << "-1\n";O=0;return;}
    for (int i = 1; i <= n; i++) cout << tt[i] << " ";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
/*
5 6
X...XX
XX...X
......
..XX..
XXX..X
*/