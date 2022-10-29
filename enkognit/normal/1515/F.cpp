#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("unroll-loops")
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

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, X, m, k, L, a[300001];
vector<pll> ans;
vector<pll> c[300001];

ll d[1000001];

void make_sets(int h)
{
    for (int i = 1; i <= h; i++) d[i]=i;
}

ll find_set(int h)
{
    if (h==d[h]) return h; else return d[h]=find_set(d[h]);
}

void unite_sets(int x,int y)
{
    x=find_set(x);
    y=find_set(y);
    if (c[x].size()>c[y].size())
        swap(x, y);
    d[x]=y;
    while (c[x].size())
    {
        c[y].pb(c[x].back());
        c[x].pop_back();
    }
    a[y]+=a[x]-X;
}



void solve()
{
    cin >> n >> m >> X;
    ll sm=0;
    set<pll> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s.insert(mp(-a[i], i));
        sm+=a[i];
    }
    vector<pll> ed;
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(mp(y, i));
        c[y].pb(mp(x, i));
    }

    if (sm<(n-1)*X)
    {
        cout << "NO\n";
        exit(0);
    }

//    for (int i = 0; i < c[4].size(); i++) cout << c[4][i].fi << " ";

    vector<ll> ans;

    make_sets(n);

    while (!s.empty())
    {
        ll h=(*s.begin()).se;
        //cout << " " << (*s.begin()).fi << "\n";
        s.erase(s.begin());
        //cout << h << " " << c[h].size() << "\n";
        while (c[h].size()>0 && find_set(c[h].back().fi)==find_set(h)) c[h].pop_back();
        //cout << "--\n";
        if (c[h].size()==0) break;
        ans.pb(c[h].back().se);
        ll p=find_set(c[h].back().fi);
        c[h].pop_back();
        //cout << p << " " << c[p].size() << "-\n";
        s.erase(mp(-a[p], p));
        //cout << "--\n";
        unite_sets(p, h);
        //cout << "--\n";
        s.insert(mp(-a[find_set(h)],find_set(h)));
    }
    cout << "YES\n";
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << "\n";
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
5
1 -1 1 -1 1

5
1 -2 3 -4 5

10
1 -3 -5 7 -9 10 8 -6 -4 2

*/