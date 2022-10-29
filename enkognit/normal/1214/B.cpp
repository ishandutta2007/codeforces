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

const ll MOD = 998244353;

ll n, k, q, l, m, r, i, j, x, y, ans;
vector <ll> e, v;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> m >> k >> n;
    ll ans=n+1;
    for (int i = 0; i <= n; i++)
    {
        if (i>m || n-i>k) ans--;
    }
    cout << ans;
    return 0;
}
/*
6 15
E 5
V 9
M 3
V 2
M 5
V 6
*/