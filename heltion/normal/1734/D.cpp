#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, k;
        cin >> n >> k;
        vector<LL> a(n + 1), s(n + 1);
        for (int i = 1; i <= n; i += 1) {
            cin >> a[i];
            s[i] = s[i - 1] + a[i];
        }
        int L = k, R = k;
        LL cur = a[k];
        int fL = k, fR = k, gL = k, gR = k;
        int ok = 1;
        while (true) {
            while (fL > 1 and cur + s[L - 1] - s[fL - 2] >= 0) {
                fL -= 1;
                if (s[fL - 1] < s[gL - 1]) gL = fL;
            }
            while (fR < n and cur + s[fR + 1] - s[R] >= 0) {
                fR += 1;
                if (s[fR] > s[gR]) gR = fR;
            }
            if (fL == 1 or fR == n) break;
            if (gL != L) {
                cur += s[L - 1] - s[gL - 1];
                L = gL;
            }
            else if (gR != R) {
                cur += s[gR] - s[R];
                R = gR;
            }
            else {
                ok = 0;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    };
}