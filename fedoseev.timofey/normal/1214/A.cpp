#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, d, e;
    cin >> n >> d >> e;
    int res = n;
    for (int x = 0; x * d <= n; ++x) {
        res = min(res, (n - x * d) % (5 * e));
    }
    cout << res << '\n';
}