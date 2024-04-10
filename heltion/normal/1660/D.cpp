#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& ai : a) cin >> ai;
        int ans = 0, L = 0, R = n;
        auto check = [&](int l, int r) {
            int c2 = 0, pn = 0;
            for (int k = l; k < n - r; k += 1) {
                c2 += abs(a[k]) == 2;
                pn ^= a[k] < 0;
            }
            assert(not pn);
            if (c2 > ans) {
                ans = c2;
                L = l;
                R = r;
            }
        };
        for (int i = 0, j = 0; i < n; i = j += 1) if (a[i]) {
            while (j < n and a[j]) j += 1;
            int pn = 0;
            for (int k = i; k < j; k += 1) pn ^= a[k] < 0;
            if (not pn) check(i, n - j);
            else {
                int ii = i;
                while (a[ii] > 0) ii += 1;
                check(ii + 1, n - j);
                int jj = j;
                while (a[jj - 1] > 0) jj -= 1;
                check(i, n - jj + 1);
            }
        }
        cout << L << " " << R << "\n";
    }
    return 0;
}