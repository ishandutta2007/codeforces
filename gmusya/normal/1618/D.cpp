#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll ans = 0;
        for (int i = 0; i < n - 2 * k; ++i) {
            ans += a[i];
        }
        int sum = 0;
        {
            map<int, int> map;
            for (int& x : a) {
                map[x] = 0;
            }
            for (auto& now : map) {
                now.second = sum++;
            }
            for (int& x : a) {
                x = map[x];
            }
        }
        vector<int> cnt(sum);
        for (int i = n - 2 * k; i < n; ++i) {
            ++cnt[a[i]];
        }
        set<pair<int, int>, greater<>> set;
        for (int i = 0; i < sum; ++i) {
            if (cnt[i]) {
                set.insert({cnt[i], i});
            }
        }
        while (k--) {
            if (set.size() == 1) {
                ++ans;
            } else {
                auto p1 = *set.begin();
                set.erase(set.begin());
                auto p2 = *set.begin();
                set.erase(set.begin());
                --p1.first;
                --p2.first;
                if (p1.first) {
                    set.insert(p1);
                }
                if (p2.first) {
                    set.insert(p2);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}