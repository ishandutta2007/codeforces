#include <bits/stdc++.h>

// Contest: Codeforces Round #592 (Div. 2) (https://codeforces.com/contest/1244)
// Problem: G: Running in Pairs (https://codeforces.com/contest/1244/problem/G)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k; cin >> n >> k;
    auto orig_k = k;
    if (k < n * (n + 1) / 2) {
        cout << "-1\n";
        return 0;
    }
    k -= n * (n + 1) / 2;

    vector<int> res(n);
    iota(begin(res), end(res), 1);
    for (ll i = 0; k > 0 && i < n / 2; ++i) {
        ll num = n - i;
        ll pos_steps = n - 2 * i - 1;
        if (k >= pos_steps) {
            swap(res[i], res[n - 1 - i]);
            k -= pos_steps;
        } else {
            auto idx = n - 1 - i;
            for (int j = 0; j < k; ++j)
                swap(res[idx - j], res[idx - j - 1]);
            k = 0;
        }
    }


    cout << (orig_k - k) << '\n';
    for (int i = 1; i <= n; ++i)
        cout << i << ' ';
    cout << '\n';
    for (auto i : res)
        cout << i << ' ';
    cout << '\n';

    return 0;
}