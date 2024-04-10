#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>

using namespace std;

ll n, m, k, l, r, i, j, k1, k0, a[100001];
string s;

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);
    swap(a[n-1],a[n-2]);
    if (a[n-2]>=a[n-1]+a[n-3]) {cout << "NO\n";exit(0);}
    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}