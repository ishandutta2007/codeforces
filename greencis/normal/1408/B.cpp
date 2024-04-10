#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
using namespace std;
using ld = long double;
using ll = int64_t;
using pii = pair<int, int>;
using ull = uint64_t;

int a[105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        if (k == 1) {
            cout << (a[0] == a[n - 1] ? 1 : -1) << '\n';
        } else {
            int diff = 1;
            for (int i = 0; i + 1 < n; ++i)
                diff += a[i] != a[i + 1];
            cout << (diff <= k ? 1 : 1 + (diff - k + (k - 1) - 1) / (k - 1)) << '\n';
        }
    }
}