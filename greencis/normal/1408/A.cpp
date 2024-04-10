#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
using namespace std;
using ld = long double;
using ll = int64_t;
using pii = pair<int, int>;
using ull = uint64_t;

int p[105], a[105], b[105], c[105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        for (int i = 0; i < n; ++i) cin >> c[i];
        p[0] = a[0];
        for (int i = 1; i < n; ++i) {
            int x = a[i];
            if (p[i - 1] == x || (i == n - 1 && p[0] == x)) {
                x = b[i];
                if (p[i - 1] == x || (i == n - 1 && p[0] == x)) {
                    x = c[i];
                }
            }
            p[i] = x;
        }
        for (int i = 0; i < n; ++i) cout << p[i] << ' ';
        cout << '\n';
    }
}