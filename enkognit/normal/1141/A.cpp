#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define fr front()
#define se second
#define pll pair<ll,ll>

using namespace std;

const ll MOD=1e9+7;

ll n, i, j, m, ans, k, q, l, r, z;
pll a[500001];
multiset<ll> s;

int main()
{
    //freopen("robots.in","r",stdin);
    //freopen("robots.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    if (m%n) {cout << -1;exit(0);}
    m/=n;
    ll l=0, r=0;
    while (m%2==0) l++,m/=2;
    while (m%3==0) r++,m/=3;
    if (m>1) {cout << -1;exit(0);}
    cout << l+r;
    return 0;
}