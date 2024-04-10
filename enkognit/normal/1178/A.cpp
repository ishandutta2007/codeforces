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

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    cin >> p;
    ll l=p;
    for (int i = 1; i < n; i++)
    {
        cin >> a[i].fi;
        a[i].se=i+1;
        l+=a[i].fi;
    }
    l/=2;
    sort(a+1,a+n);
    ll r=1, o=p;
    vector <ll> v={};
    v.pb(1);
    while (r<n && a[r].fi*2<=p) o+=a[r].fi,v.pb(a[r].se),r++;
    if (o>l)
    {
        cout << v.size() << "\n";
        for (int i = 0; i< v.size(); i++) cout << v[i] << " ";
    }else cout << 0;
    return 0;
}


/*

| 1 5 13 29 | 2 7 17 37 | 18 39 22 47 |


*/