#include <bits/stdc++.h>

// Contest: Codeforces Round #501 (Div. 3) (https://codeforces.com/contest/1015)
// Problem: C: Songs Compression (https://codeforces.com/contest/1015/problem/C)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<ll> s(n);
    ll sum_a = 0, sum_b = 0;
    for (int i = 0; i < n; ++i) {
        ll a, b; cin >> a >> b;
        sum_a += a; sum_b += b;
        s[i] = a - b;
    }
    sort(begin(s), end(s), greater{});

    ll diff = 0;
    for (int i = 0; i < n; ++i) {
        if (sum_a - diff <= m) {
            cout << i << '\n';
            return 0;
        }
        diff += s[i];
    }

    if (sum_b <= m)
        cout << n << '\n';
    else
        cout << -1 << '\n';

    return 0;
}