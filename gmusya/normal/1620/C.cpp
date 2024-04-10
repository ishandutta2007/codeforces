#include <algorithm>
#include <iostream>
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
        ll x;
        cin >> n >> k >> x;
        --x;
        vector<char> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<pair<int, int>> arr;
        int l = 0, r = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 'a') {
                arr.emplace_back(l, r);
                l = i + 1, r = i;
            } else {
                ++r;
            }
        }
        if (l <= r) {
            arr.emplace_back(l, r);
        }
        string ans;
        reverse(arr.begin(), arr.end());
        for (auto& now : arr) {
            ans += "a";
            int L = now.first;
            int R = now.second;
            if (L <= R) {
                ll c = (R - L + 1) * k + 1;
                ll kek = x % c;
                x /= c;
                for (ll i = 0; i < kek; ++i) {
                    ans += "b";
                }
            }
        }
        reverse(ans.begin(), ans.end());
        if (a.back() != 'a') {
            ans.pop_back();
        }
        cout << ans << '\n';
    }
    return 0;
}