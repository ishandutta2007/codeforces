#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int s, n, m = 0;
        cin >> s >> n;
        vector<int> p(10), c(10);
        for (int i = 0; i < 10; i += 1) {
            p[i] = i ? p[i - 1] * 10 : 1;
            c[i] = s / p[i] % 10;
            m += c[i];
        }
        while (m < n) {
            for (int i = 1; i < 10; i += 1) {
                if (c[i]) {
                    c[i] -= 1;
                    c[i - 1] += 10;
                    m += 9;
                    break;
                }
            }
        }
        for (int i = 0, j = 0; i < n; i += 1) {
            int x = 0;
            for (int k = 0; k < (i ? 1 : m - (n - 1)); k += 1) {
                while (c[j] == 0) j += 1;
                x += p[j];
                c[j] -= 1;
            }
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}