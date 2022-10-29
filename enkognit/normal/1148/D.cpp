#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
//#pragma GCC optimize("-Otime")
//#pragma GCC optimize("unr")
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

ll n, m, i, j, k, l, r, a[300001];
pll dp[200001][2];

int main()
{
    //freopen("tickets.in","r",stdin);
    //freopen("tickets.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n;
    vector <pair<pll,ll> > v={}, z={};
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        if (x<y) z.pb(mp(mp(y,x),i));
        if (x>y) v.pb(mp(mp(y,x),i));
    }
    if (z.size()>v.size())
    {
        sort(z.begin(),z.end());
        cout << z.size() << "\n";
        for (int i = z.size()-1; i > -1; i--) cout << z[i].se << " ";
    }else
    {
        sort(v.begin(),v.end());
        cout << v.size() << "\n";
        for (int i = 0; i < v.size(); i++) cout << v[i].se << " ";
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