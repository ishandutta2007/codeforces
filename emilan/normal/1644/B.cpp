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

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    iota(RALL(a), 1);

    auto print = [&](const auto &v) {
        REP(i, n) cout << v[i] << " \n"[i == n - 1];
    };

    print(a);

    REP(i, n - 1) {
        vector<int> b = a;
        swap(b[i], b[i + 1]);
        print(b);
    }
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