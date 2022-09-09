#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, ans = 0;
        cin >> n;
        vector<int> a(n);
        auto check = [&](int L, int R) {
            for (int i = L; i <= R; i += 1)
                for (int j = i + 1; j <= R; j += 1)
                    for (int k = j + 1; k <= R; k += 1) {
                        if (a[i] <= a[j] and a[j] <= a[k]) return 0;
                        if (a[i] >= a[j] and a[j] >= a[k]) return 0;
                    }
            return 1;
        };
        for (int& x : a) cin >> x;
        for (int i = 0; i < n; i += 1) {
            for (int j = i; j < n; j += 1) {
                if (check(i, j)) ans += 1;
                else break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}