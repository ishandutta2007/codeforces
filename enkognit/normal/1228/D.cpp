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

ll n, m, i, p, k, T, j, A, B, C, y, kol, tt[1000001];
vector <ll> c[100001];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    for (int i = 1; i <= n; i++) tt[i]=1;
    ll k1=n;
    for (int i = 0; i < c[1].size(); i++)
    {
        tt[c[1][i]]=0, k1--;
    }
    if (k1>n-2) {cout << -1;exit(0);}
    ll k2=n-k1, k3=0;
    for (int i = 1; i <= n; i++) if (!tt[i]) tt[i]=2;
    ll p=c[1][0];
    for (int i = 0; i < c[p].size(); i++)
    {
        if (tt[c[p][i]]==2) tt[c[p][i]]=3, k3++, k2--;
    }
    if (k1+k2+k3!=n || k1==0 || k2==0 || k3==0) {cout << -1;exit(0);}
    for (int i = 1; i <= n; i++)
    {
        if (tt[i]==1)
        {
            if (c[i].size()!=k2+k3) {cout << -1;exit(0);}
        }
        if (tt[i]==2)
        {
            if (c[i].size()!=k1+k3) {cout << -1;exit(0);}
        }
        if (tt[i]==3)
        {
            if (c[i].size()!=k2+k1) {cout << -1;exit(0);}
        }
        for (int j = 0; j < c[i].size(); j++) if (tt[c[i][j]]==tt[i]) {cout << -1;exit(0);}
    }
    for (int i = 1; i <= n; i++) cout << tt[i] << " ";
}