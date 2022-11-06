#include <bits/stdc++.h>

// Contest: Codeforces Round #592 (Div. 2) (https://codeforces.com/contest/1244)
// Problem: E: Minimizing Difference (https://codeforces.com/contest/1244/problem/E)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; ll k; cin >> n >> k;
    vector<int> a(n);
    for (auto& ai : a) cin >> ai;
    sort(begin(a), end(a));

    if (*begin(a) == *rbegin(a)) {
        cout << "0\n";
        return 0;
    }

    auto itf = begin(a), itb = prev(end(a));
    int mn = *itf, mn_count = 0;
    while (*itf == mn)
        ++mn_count, ++itf;

    int mx = *itb, mx_count = 0;
    while (itf <= itb && *itb == mx)
        ++mx_count, --itb;

    while (k > 0 && itf <= itb) {
        if (mn_count < mx_count) {
            int next = *itf;
            int steps = min(k / mn_count, (ll)next - mn);
            if (steps == 0)
                break;
            mn += steps;
            k -= steps * (ll)mn_count;
            while (itf <= itb && *itf == mn)
                ++mn_count, ++itf;
        } else {
            int next = *itb;
            int steps = min(k / mx_count, (ll)mx - next);
            if (steps == 0)
                break;
            mx -= steps;
            k -= steps * (ll)mx_count;
            while (itf <= itb && *itb == mx)
                ++mx_count, --itb;
        }
    }

    auto red = min(k / min(mn_count, mx_count), (ll)mx - mn);
    cout << (mx - mn - red) << '\n';
    return 0;
}