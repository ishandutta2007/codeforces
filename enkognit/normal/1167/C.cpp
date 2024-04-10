#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define fr front()
#define sqr(a) ((a)*(a))
#define y1 Enkognit

using namespace std;

const ll MOD=998244353;

ll n, m, w, l, r, T, k, sum, ans[500001];
vector <ll> c[500001];
int t[1000001];

void dfs(ll h)
{
    T++;
    t[h]=1;
    for (int i = 0; i < c[h].size(); i++) if (!t[c[h][i]]) dfs(c[h][i]);
}

void dfs1(ll h)
{
    ans[h]=T;
    t[h]=2;
    for (int i = 0; i < c[h].size(); i++) if (t[c[h][i]]!=2) dfs1(c[h][i]);
}

int main()
{
    //freopen("divisors.in","r",stdin);
    //freopen("divisors.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll p;
        cin >> p;
        ll y;
        if (p>0)cin >> y;
        for (int j = 1; j < p; j++)
        {
            ll x;
            cin >> x;
            c[y].pb(x);
            c[x].pb(y);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!t[i])
        {
            T=0;
            dfs(i);
            dfs1(i);
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}
/*
5
2 3 4 5 6
6
1 2 4
1 2 3
0 1 1
0 4 7
1 1 3
1 1 4

*/