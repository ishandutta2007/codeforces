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

ll inv(vector<int> &a) {
    int n = SZ(a), m = n / 2;
    if (n <= 1) return 0;

    vector<int> a_l(begin(a), begin(a) + m);
    vector<int> a_r(begin(a) + m, end(a));

    ll ans = inv(a_l) + inv(a_r);
    vector<int> b(n);
    for (int i = 0, l = 0, r = 0; i < n; i++) {
        if (r >= n - m || (l < m && a_l[l] <= a_r[r])) {
            b[i] = a_l[l++];
        } else {
            ans += m - l;
            b[i] = a_r[r++];
        }
    }

    a.swap(b);
    return ans;
}

bool solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    if (SZ(set(ALL(a))) != n) return true;
    else return ~inv(a) & 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        cout << (solve() ? "yEs" : "nO") << '\n';
    }
}