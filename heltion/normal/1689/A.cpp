#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m, k;
        string a, b, c;
        cin >> n >> m >> k >> a >> b;
        ranges::sort(a);
        ranges::sort(b);
        for (int i = 0, j = 0, cnt = 0; i < n and j < m;) {
            if (cnt == k) {
                cnt = -1;
                c += b[j ++];
            }
            else if (cnt == -k) {
                cnt = 1;
                c += a[i ++];
            }
            else if (a[i] < b[j]) {
                cnt = max(cnt, 0) + 1;
                c += a[i ++];
            }
            else {
                cnt = min(cnt, 0) - 1;
                c += b[j ++];
            }
        }
        cout << c << "\n";
    }
    return 0;
}