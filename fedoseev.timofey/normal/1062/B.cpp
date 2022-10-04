#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

vector <pair <int, int>> primes(int x) {
    vector <pair <int, int>> mem;
    for (int d = 2; d * d <= x; ++d) {
        if (x % d == 0) {
            mem.push_back({d, 0});
            while (x % d == 0) {
                x /= d;
                ++mem.back().second;
            }
        }
    }
    if (x != 1) mem.push_back({x, 1});
    return mem;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    auto cur = primes(n);
    int mx = -1;
    for (auto p : cur) mx = max(mx, p.second);
    bool kek = true;
    if (cur.empty()) {
        cout << "1 0\n";
        return 0;
    }
    int ans = 0;
    int j = 0;
    for (int i = 0; i < 30; ++i) {
        if ((1 << i) <= mx) j = i;
    }
    int need = j;
    bool fl = false;
    if ((1 << j) != mx) {
        ++need;
        fl = true;
    }
    bool good = true;
    for (auto p : cur) {
        if (fl || p.second != mx) {
            good = false;
        }
    }
    if (!good) ++need;
    int res = 1;
    for (auto p : cur) res *= p.first;
    cout << res << ' ' << need << '\n';
}