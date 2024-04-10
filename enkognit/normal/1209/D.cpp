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
#define y1 Enkognit

using namespace std;

ll n, m, i, n1, p, n2, k, T, j, y, kol=1,  a[200001], b[200001];
string s, d;
vector <ll> c[300001];
ll tt[100001];

void dfs(ll h)
{
    tt[h]=1;
    for (int i = 0; i < c[h].size(); i++)
        if (!tt[c[h][i]])
        {
            T++;
            dfs(c[h][i]);
        }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i];
        c[a[i]].pb(b[i]);
        c[b[i]].pb(a[i]);
    }
    ll ans=0;
    for (int i = 1; i <= n; i++)
        if (!tt[i])
        {
            T=0;
            dfs(i);
            ans+=T;
        }
    cout << m-ans;
    return 0;
}