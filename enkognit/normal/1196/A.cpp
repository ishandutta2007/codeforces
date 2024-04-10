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

const ll MOD = 998244353;

ll n, m, k, a[200001], q, p, ans, l, r, i, j, x, y;

ll func(ll p,ll r,ll l)
{
    if (r+p<=l) return r+p; else
    return (p-(l-r))/2+l;
}

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n;
    while (n--)
    {
        for (int i = 0; i < 3; i++) cin >> a[i];
        sort(a,a+3);
        cout << max(func(a[0],a[1],a[2]), max(func(a[1],a[0],a[2]), func(a[2],a[0],a[1])));
        cout << "\n";
    }
    return 0;
}


/*
2 4 4 2
1 2
1 4
2 3
2 1
1 3


*/