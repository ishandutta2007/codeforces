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
#define y1 Enkognit

using namespace std;

const ll MOD=1e9+7;

ll n, m, i, p, k, T, j, A, B, C, y, kol, r[1001], c[1001], a[1001][1001];
ll b[80];
string s, t;
bool tt[1001][1001];


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i];
        for (int j = 1; j <= r[i]; j++)
        {
            a[i][j]=1;
        }
        tt[i][r[i]+1]=1;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> c[i];
        for (int j = 1; j <= c[i]; j++)
        {
            a[j][i]=1;
        }
        tt[c[i]+1][i]=1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i][r[i]+1]==1) {cout << 0;exit(0);}
    }
    for (int i = 1; i <= m; i++)
    {
        if (a[c[i]+1][i]==1) {cout << 0;exit(0);}
    }
    ll ans=1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!a[i][j])
    {
        if (!tt[i][j]) ans*=2, ans%=MOD;
    }
    cout << ans;
}