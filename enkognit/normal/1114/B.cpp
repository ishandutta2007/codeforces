#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

ll n, m, i, j, k, l, r;
pll a[1000001];
string s, d;
vector <ll> v;

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {cin >> a[i].fi;a[i].se=i;}
    sort(a,a+n);
    vector <pll> v;
    ll ans=0;
    for (int i = n-1; i >= n-m*k; i--)
    {
        ans+=a[i].fi;
        v.pb(mp(a[i].se,a[i].fi));
    }
    sort(v.begin(),v.end());
    cout << ans << "\n";
    for (int i = m-1; i < m*(k-1); i+=m) cout << v[i].fi+1 << " ";
    return 0;
}