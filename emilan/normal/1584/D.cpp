#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for (int i = 0; (i) < (n); (i)++)
#define REP1(i, n)  for (int i = 1; (i) <= (n); (i)++)
#define SZ(a)       int(size(a))
#define ALL(a)      begin(a), end(a)
#define RALL(a)     rbegin(a), rend(a)

using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
using ld = long double;
using pii = pair<int, int>;

// [l, r)
auto query(int l, int r) {
    cout << "? " << l + 1 << ' ' << r << endl;
    ll ans;
    cin >> ans;
    return ans;
}

void solve() {
    int n;
    cin >> n;

    ll total = query(0, n);

    int l = 2, r = n + 1;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (query(0, m) == total) r = m;
        else l = m;
    }
    int k = r - 1;

    int j = int(k - (total - query(0, k)));

    ll right = ll(k - j) * (k - j + 1) / 2;
    ll left = total - right;
    int i = (j - 1) - int(left - query(0, j - 1));

    cout << "! " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}