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

ll n, m, k, f[200001], q, p, ans, l, r, i, j, x, y;

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
    ll q;
    cin >> q;
    while (q--)
    {
        cin >> n;
        ll x1=-1e5, y1=-1e5, x2=1e5, y2=1e5;
        for (int i = 0; i < n; i++)
        {
            ll x, y;
            cin >> x >> y;
            for (int i = 0; i < 4; i++)
            {
                cin >> f[i];
            }
            if (!f[0]) x1=max(x1,x);
            if (!f[1]) y2=min(y2,y);
            if (!f[2]) x2=min(x2,x);
            if (!f[3]) y1=max(y1,y);
        }
        if (y1>y2 || x1>x2) cout << "0\n"; else cout << "1 " << x1 << " " << y1 << "\n";
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