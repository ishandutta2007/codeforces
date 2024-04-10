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

ll n, m, T, k, l, r, i, t, j, sum, kol=0, a[1000001], d[1000001];
pll b[1000001];
string s;
vector <pll> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> k >> t;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    vector <pll> v;
    for (int i = 0; i < k; i++)
    {
        cin >> b[i].fi >> b[i].se >> d[i];
        if (b[i].fi>b[i].se) {i--;k--;}
    }
    sort(a+1,a+m+1);
    reverse(a+1,a+m+1);
    a[0]=1e18;
    ll l=0, r=m;
    while (l<r)
    {
        ll w=(l+r+1)/2, an=n+1, mx=0;
        vector <pll> v;
        for (int i = 0; i < k; i++)
        {
            if (d[i]>a[w]) v.pb(mp(b[i].fi,b[i].se));
        }
        sort(v.begin(),v.end());
        for (int i = 0; i < v.size(); i++)
        {
            an+=max(v[i].se-max(v[i].fi-1,mx),0ll)*2;
            mx=max(mx,v[i].se);
        }
        //cout << a[w] << " " << w << " " << an << "\n";
        if (an<=t) l=w; else r=w-1;
    }
    cout << l;
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