#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

const int mx = 2e4, inf = 1 << 30;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    int ans_a = inf, ans_b = inf, ans_c = inf, mv = inf;
    for (int i = 1; i <= mx; i++) {
        for (int j = i; j <= mx; j += i) {
            int fc = c / j * j, k;
            if (fc > 0 && c - fc < fc + j - c) k = fc;
            else k = fc + j;
            int cur = abs(a - i) + abs(b - j) + abs(c - k);

            if (cur < mv) {
                mv = cur;
                ans_a = i;
                ans_b = j;
                ans_c = k;
            }
        }
    }

    cout << mv << '\n' << ans_a << ' ' << ans_b << ' ' << ans_c << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}