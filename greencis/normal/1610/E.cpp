#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma,tune=native")
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
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        int ans = 0;
        for (int ptr = 0, nxt; ptr < n; ptr = nxt) {
            for (nxt = ptr; nxt < n && a[nxt] == a[ptr]; ++nxt);
            int len = nxt - ptr;
            for (int i = nxt; i < n; ) {
                ++len;
                i = lower_bound(all(a), 2 * a[i] - a[ptr]) - a.begin();
            }
            ans = max(ans, len);
        }
        cout << n - ans << '\n';
    }
}