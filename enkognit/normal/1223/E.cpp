#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
#define pii pair<int,int>
#define y1 Enkognit

using namespace std;

const ll MOD=1e9+7;

int n, m, it, i, p, k, T, j, a[2000001], B, C, y, kol;
ll dp[500002][2];
string s;
vector <pii> c[500015];
bool tt[1000001];

void dfs(ll h)
{
    tt[h]=1;
    vector <ll> v;
    ll p=0;
    for (int i = 0; i < c[h].size(); i++)
        if (!tt[c[h][i].fi])
        {
            dfs(c[h][i].fi);
            p+=max(dp[c[h][i].fi][1],dp[c[h][i].fi][0]);
            v.pb(dp[c[h][i].fi][0]+c[h][i].se-max(dp[c[h][i].fi][1],dp[c[h][i].fi][0]));
        }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    ll q=p;
    for (int i = 0; i < min((ll)k,(ll)v.size()); i++)
    {
        p+=v[i];
        q=max(p,q);
    }
    if (k<v.size()) dp[h][1]=p+v[k];
    dp[h][0]=q;
    //cout << dp[h][0] << " " << dp[h][1] << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n >> k;
        k--;
        for (int i = 1; i <= n; i++) c[i].clear(), tt[i]=0, dp[i][0]=0, dp[i][1]=0;
        for (int i = 1; i < n; i++)
        {
            ll x, y, h;
            cin >> x >> y >> h;
            c[x].pb(mp(y,h));
            c[y].pb(mp(x,h));
        }
        dfs(1);
        cout << max(dp[1][0],dp[1][1]) << "\n";;
    }
}
/*
9 12
1 9 4
1 2 5
2 3 7
2 4 3
4 3 6
3 6 4
8 7 10
6 7 5
5 8 1
9 5 7
5 4 12
6 8 2
2
4 7
5
1 6
5 3
4 8
5 8
1 5
*/