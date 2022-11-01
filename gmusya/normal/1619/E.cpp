#include <iostream>
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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> cnt(n + 1);
        for (int i = 0; i < n; ++i) {
            ++cnt[a[i]];
        }
        vector<ll> d(n + 1);
        d[0] = 0;
        multiset<int> unused;
        for (int i = 0; i < cnt[0]; ++i) {
            unused.insert(0);
        }
        int mx = n;
        for (int x = 1; x <= n; ++x) {
            if (unused.empty()) {
                mx = x - 1;
                break;
            }
            int val = *unused.rbegin();
            unused.erase(unused.find(val));
            d[x] = d[x - 1] + (x - 1 - val);
            for (int i = 0; i < cnt[x]; ++i) {
                unused.insert(x);
            }
        }
        vector<ll> ans(n + 1, -1);
        for (int i = 0; i <= mx; ++i) {
            ans[i] = d[i] + cnt[i];
        }
        for (ll x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}