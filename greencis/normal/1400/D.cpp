#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
using namespace std;
using ld = long double;
using ll = int64_t;
using pii = pair<int, int>;
using ull = uint64_t;

int a[3005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i], --a[i];
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> left_cnt(n), right_cnt(n);
            ll addon = 0;
            for (int j = i + 1; j < n; ++j)
                ++right_cnt[a[j]];
            for (int j = i + 1; j < n; ++j) {
                addon -= left_cnt[a[j]];
                --right_cnt[a[j]];
                if (a[j] == a[i])
                    ans += addon;
                ++left_cnt[a[j]];
                addon += right_cnt[a[j]];
            }
        }
        cout << ans << endl;
    }
}