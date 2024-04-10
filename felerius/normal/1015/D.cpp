#include <bits/stdc++.h>

// Contest: Codeforces Round #501 (Div. 3) (https://codeforces.com/contest/1015)
// Problem: D: Walking Between Houses (https://codeforces.com/contest/1015/problem/D)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k, s; cin >> n >> k >> s;
    ll d = 1, p = 0;
    ll st = s / k;
    if (st == 0 || (n - 1) * k < s) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < s % k; ++i) {
        p += d * (st + 1);
        d = -d;
        cout << (p + 1) << ' ';
    }
    for (int i = 0; i < (k - s % k); ++i) {
        p += d * st;
        d = -d;
        cout << (p + 1) << ' ';
    }
    cout << '\n';

    return 0;
}