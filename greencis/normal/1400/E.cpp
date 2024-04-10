#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
using namespace std;
using ld = long double;
using ll = int64_t;
using pii = pair<int, int>;
using ull = uint64_t;

int a[5005];

int solve(int L, int R, int addon = 0) {
    if (L >= R) return 0;
    int ans = R - L;
    int mn = *min_element(a + L, a + R);
    int alt = mn - addon;
    int prv = L - 1;
    for (int i = L; alt < ans && i < R; ++i) {
        if (a[i] == mn) {
            alt += solve(prv + 1, i, mn);
            prv = i;
        }
    }
    if (alt < ans)
        alt += solve(prv + 1, R, mn);
    return min(ans, alt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << solve(0, n);
}