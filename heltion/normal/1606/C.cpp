#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        LL n, k;
        cin >> n >> k;
        k += 1;
        vector<int> v(10);
        for (int i = 0, a; i < n; i += 1) {
            cin >> a;
            v[a] = 1;
        }
        LL ans = 0;
        for (LL i = 0, p = 1; i < 10; i += 1, p *= 10) if (v[i]) {
            int j = i + 1;
            while (j < 10 and not v[j]) j += 1;
            if (j == 10) ans += p * k;
            else {
                LL x = 1;
                for (int y = i; y < j; y += 1) x = x * 10;
                LL h = min(k, x - 1);
                k -= h;
                ans += p * h;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}