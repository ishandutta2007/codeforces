#include <bits/stdc++.h>
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int cnt[2] = {0, 0};
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[i] = x % 2;
            ++cnt[x % 2];
        }
        if (abs(cnt[0] - cnt[1]) > 1) {
            cout << "-1\n";
            continue;
        }
        ll ans = 1e18;
        for (int val = 0; val < (n % 2 == 0 ? 2 : 1); ++val) {
            int bit_needed = n % 2 == 0 ? val : cnt[0] > cnt[1] ? 0 : 1;
            int curstack[2] = {0, 0};
            int ptr = 0;
            ll cur = 0;
            for (int i = 0; i < n; ++i) {
                ++curstack[a[i]];
                while (ptr < n) {
                    if (curstack[bit_needed]) {
                        --curstack[bit_needed];
                        cur += curstack[bit_needed ^ 1];
                        bit_needed ^= 1;
                        ++ptr;
                    } else break;
                }
            }
            ans = min(ans, cur);
        }
        cout << ans << '\n';
    }
}