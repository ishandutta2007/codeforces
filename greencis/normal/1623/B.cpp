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
        int n;
        cin >> n;
        vector<pii> cnt(n);
        for (int i = 0; i < n; ++i) {
            int l, r;
            cin >> l >> r;
            --l; --r;
            for (int j = l; j <= r; ++j)
                ++cnt[j].first;
            cnt[i].second = i;
        }
        sort(all(cnt));
        vector<pii> segs;
        segs.emplace_back(0, n - 1);
        for (auto [_, i] : cnt) {
            for (int z = 0; z < (int)segs.size(); ++z) {
                auto [l, r] = segs[z];
                if (l <= i && i <= r) {
                    cout << l + 1 << ' ' << r + 1 << ' ' << i + 1 << '\n';
                    if (l <= i - 1)
                        segs.emplace_back(l, i - 1);
                    if (i + 1 <= r)
                        segs.emplace_back(i + 1, r);
                    segs.erase(segs.begin() + z);
                    break;
                }
            }
        }
        cout << "\n";
    }
}