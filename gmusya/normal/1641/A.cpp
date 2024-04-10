#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <set>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        multiset<ll> s;
        for (int i = 0; i < n; ++i) {
            ll val;
            cin >> val;
            s.insert(val);
        }
        int cnt = 0;
        while (!s.empty()) {
            ll v = *s.begin();
            if (s.find(x * v) != s.end()) {
                s.erase(s.find(v));
                s.erase(s.find(x * v));
                continue;
            }
            ++cnt;
            s.erase(s.find(v));
        }
        cout << cnt << '\n';
    }
    return 0;
}