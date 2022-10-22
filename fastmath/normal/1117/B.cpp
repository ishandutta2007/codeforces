#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;
int n, m, k;
int a[N];
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin); cout.precision(20);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(20);
    #endif
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    reverse(a, a + n);
    int c2 = m / (k + 1);
    cout << a[1] * c2 + a[0] * (m - c2) << '\n';
}