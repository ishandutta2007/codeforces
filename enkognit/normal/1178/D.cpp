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

ll n, m, k, q, p, ans, l, r, i, j, g0, x, y, z;
pll a[100001];
bool t[1000001];
string s;

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 2; i <= 1000; i++)
        if (!t[i])
        {
           ll j=i*i;
           while (j<=1000000) t[j]=1, j+=i;
        }
    vector <pll> v;
    for (int i = 1; i < n; i++) v.pb(mp(i,i+1));
    v.pb(mp(n,1));
    ll o=n, r=2;
    while (t[o] && r<=n/2)
    {
        v.pb(mp(n-r+2,r));
        o++;
        r++;
    }
    //if (t[o] && n>3) v.pb(mp(n,2)),o++;
    //cout << o << "\n";
    if (t[o]) cout << -1; else
    {
        cout << v.size() << "\n";
        for (int i = 0; i < v.size(); i++)
            cout << v[i].fi << " " << v[i].se << "\n";
    }
    return 0;
}


/*

| 1 5 13 29 | 2 7 17 37 | 18 39 22 47 |


*/