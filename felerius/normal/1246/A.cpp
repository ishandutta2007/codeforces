#include <bits/stdc++.h>

// Contest: Codeforces Round #596 (Div. 1, based on Technocup 2020 Elimination Round 2) (https://codeforces.com/contest/1246)
// Problem: A: p-binary (https://codeforces.com/contest/1246/problem/A)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, p; cin >> n >> p;

    if (p == 0) {
        cout << __builtin_popcountll(n) << '\n';
        return 0;
    }
    for (int i = 1; ; ++i) {
        ll rem = n - p * i;
        if (rem <= 0)
            break;
        if (i >= __builtin_popcountll(rem) && rem >= i) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}