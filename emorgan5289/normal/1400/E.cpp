#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 5005;
ll a[N];

ll dfs(ll l, ll r, ll d) {
    if (l > r) return 0;
    ll m = min_element(a+l, a+r+1)-a;
    return min(a[m]-d+dfs(l, m-1, a[m])+dfs(m+1, r, a[m]), r-l+1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << dfs(0, n-1, 0) << "\n";
}