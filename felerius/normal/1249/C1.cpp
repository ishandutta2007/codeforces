#include <bits/stdc++.h>

// Contest: Codeforces Round #595 (Div. 3) (https://codeforces.com/contest/1249)
// Problem: C2: Good Numbers (hard version) (https://codeforces.com/contest/1249/problem/C2)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    while (q--) {
        ll n; cin >> n;
        vector<int> b3;
        while (n) {
            b3.push_back(n % 3);
            n /= 3;
        }
        for (int i = 0; i < b3.size(); ++i) {
            if (b3[i] == 2) {
                b3[i] = 0;
                for (int j = i + 1; ; ++j) {
                    if (j == b3.size()) {
                        b3.push_back(1);
                        break;
                    }
                    if (++b3[j] == 3)
                        b3[j] = 0;
                    else
                        break;
                }
                for (int j = 0; j < i; ++j)
                    b3[j] = 0;
            }
        }

        reverse(begin(b3), end(b3));
        ll m = 0;
        for (auto i : b3)
            m = 3 * m + i;
        cout << m << '\n';
    }

    return 0;
}