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
        string a, b;
        cin >> n >> a >> b;
        int a0 = 0, a1 = 0;
        for (char c : a)
            ++(c == '0' ? a0 : a1);
        int b0 = 0, b1 = 0;
        for (char c : b)
            ++(c == '0' ? b0 : b1);
        int ans = 1e9;
        if (a0 == b0 && a1 == b1) {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (a[i] != b[i])
                    ++cnt;
            }
            if (cnt % 2 == 0)
                ans = min(ans, cnt);
        }
        if (b0 == a1 - 1 && b1 == a0 + 1) {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (a[i] == b[i])
                    ++cnt;
            }
            if (cnt % 2 != 0)
                ans = min(ans, cnt);
        }
        if (ans == 1e9)
            ans = -1;
        cout << ans << "\n";
    }
}