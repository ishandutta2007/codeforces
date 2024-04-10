#include <bits/stdc++.h>
// #include <atcoder/modint>

using namespace std;
// using namespace atcoder;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using pii = pair<int, int>;

int solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int e = 0;
    for (int x : a) {
        e += __builtin_ctz(x);
    }
    if (e >= n) return 0;

    int ops = 0;
    for (int k = __lg(n); k > 0; k--) {
        for (int i = 1 << k; i <= n; i += 2 << k) {
            e += k;
            ops++;
            if (e >= n) return ops;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        cout << solve() << '\n';
    }
}