#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    map<int, int> va, vb;
    auto upd = [&](vector<int>& a, vector<int>& b) {
        for (int val : a) {
            ++va[val];
        }
        for (int val : b) {
            if (va.count(val)) {
                --va[val];
                if (va[val] == 0) {
                    va.erase(val);
                }
            } else {
                ++vb[val];
            }
        }
    };
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    upd(a, b);
    auto f = [](int x) {
        int cnt = 1;
        while (x >= 10) {
            x /= 10, ++cnt;
        }
        return cnt;
    };
    int ans = 0;
    vector<int> lim = {9, 1};
    for (auto l : lim) {
        a.clear(), b.clear();
        for (auto [val, cnt] : va) {
            for (int i = 0; i < cnt; i++) {
                int x = val;
                if (val > l) {
                    x = f(x), ++ans;
                }
                a.push_back(x);
            }
        }
        for (auto [val, cnt] : vb) {
            for (int i = 0; i < cnt; i++) {
                int y = val;
                if (y > l) {
                    y = f(y), ++ans;
                }
                b.push_back(y);
            }
        }
        va.clear(), vb.clear();
        upd(a, b);
    }
    printf("%d\n", ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}