#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000000 + 2;
int a[maxn], s[maxn], r[maxn], p[1 << 20];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i += 1) {
        cin >> a[i];
        s[i] = s[i - 1] ^ a[i];
    }
    int ans = 0;
    for (int h = 0, mask = (1 << 20) - 1; h < 20; h += 1) {
        r[n + 1] = n;
        for (int i = n; i >= 0; i -= 1) {
            if ((a[i] >> h) & 1) r[i] = r[i + 1];
            else r[i] = i - 1;
        }
        for (int d = 0; d < 2; d += 1) {
            for (int i = (n - d) / 2 * 2 + d; i >= d; i -= 2) {
                int x = s[i] & mask;
                if (r[i + 1] < p[x]) p[x] = 0;
                ans = max(p[x] - i, ans);
                p[x] = max(p[x], i);
            }
            for (int& px : p) px = 0;
        }
        mask ^= 1 << h;
    }
    cout << ans;
    return 0;
}