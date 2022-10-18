#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
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
        int n, l;
        cin >> n >> l;
        vector<int> cnt(l);
        while (n--) {
            int x;
            cin >> x;
            for (int i = 0; i < l; ++i) {
                int bit = (x >> i) & 1;
                cnt[i] += bit ? 1 : -1;
            }
        }
        int ans = 0;
        for (int i = 0; i < l; ++i) {
            if (cnt[i] > 0)
                ans |= 1 << i;
        }
        cout << ans << '\n';
    }
}