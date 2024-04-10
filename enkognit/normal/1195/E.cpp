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

ll n, m, k, q, a, b, ans, l, r, i, j, g0, x, y, z;
int aa[3001][3001], bb[3001], f[3001][3001];
deque<ll> d;

void add(ll h)
{
    while (!d.empty() && d.back()>h) d.pop_back();
    d.push_back(h);
}

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> a >> b;
    cin >> g0 >> x >> y >> z;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            aa[i][j]=g0;
            g0=(g0*x+y)%z;
        }
    for (int i = 1; i <= n; i++)
    {
        d.clear();
        for (int j = 1; j <= b; j++) add(aa[i][j]);
        f[i][1]=d.front();
        for (int j = 1; j < m-b+1; j++)
        {
            if (aa[i][j]==d.front()) d.pop_front();
            add(aa[i][j+b]);
            f[i][j+1]=d.front();
        }
    }
    for (int j = 1; j <= m-b+1; j++)
    {
        d.clear();
        for (int i = 1; i <= a; i++) add(f[i][j]);
        ans+=d.front();
        for (int i = 1; i < n-a+1; i++)
        {
            if (f[i][j]==d.front()) d.pop_front();
            add(f[i+a][j]);
            ans+=d.front();
        }
    }
    cout << ans;
    return 0;
}


/*

| 1 5 13 29 | 2 7 17 37 | 18 39 22 47 |


*/