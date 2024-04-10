#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, a[maxn];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        while (true) {
            int p = n;
            while (p >= 1 && a[p] == a[n]) p--;
            if (!p) break;
            int start = max(1, p - (n - p) + 1);
            for (int i = start; i <= p; i++) a[i] = a[n];
            ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}