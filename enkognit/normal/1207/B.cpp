#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 Enkognit

using namespace std;

ll n, m, k, q, ans=1e18, l, r, i, j, x, y, kol=0, a[1001][1001];
pll b[100001];
vector <ll> c[300001];
string s;

int main()
{
    //freopen("walk.in","r",stdin);
    //freopen("walk.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i<= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] && !(a[i][j] && a[i+1][j] && a[i][j+1] && a[i+1][j+1]) &&
                !(a[i][j] && a[i-1][j] && a[i][j-1] && a[i-1][j-1]) &&
                !(a[i][j] && a[i-1][j] && a[i][j+1] && a[i-1][j+1]) &&
                !(a[i][j] && a[i+1][j] && a[i][j-1] && a[i+1][j-1])) {cout << -1;exit(0);}
    vector <pll> v;
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            if (a[i][j] && a[i+1][j] && a[i][j+1] && a[i+1][j+1]) v.pb(mp(i,j));
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) cout << v[i].fi << " " << v[i].se << "\n";
    return 0;
}