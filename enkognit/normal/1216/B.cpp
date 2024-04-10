#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define mp make_pair
#define fi first
#define se second

using namespace std;

ll n, m, k, i, j, l, r;
pll a[1000001];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {cin >> a[i].fi;a[i].se=i;}
    sort(a,a+n);
    reverse(a,a+n);
    ll ans=0;
    for (int i = 0; i < n; i++) ans+=a[i].fi*i+1;
    cout << ans << "\n";
    for (int i = 0; i < n; i++) cout << a[i].se+1 << " ";
    return 0;
}