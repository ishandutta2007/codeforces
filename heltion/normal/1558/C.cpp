#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 3000;
int a[maxn];
void rev(int p) {
    cout << p << " ";
    reverse(a + 1, a + p + 1);
}
int main() {
    ios::sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, ok = 1;
        cin >> n;
        for (int i = 1; i <= n; i += 1) {
            cin >> a[i];
            if (i % 2 != a[i] % 2) {
                ok = 0;
            }
        }
        if (not ok) {
            cout << "-1\n";
            continue;
        }
        cout << n / 2 * 5 << "\n";
        for (int i = n; i > 1; i -= 2) {
            int p = find(a + 1, a + i + 1, i) - a;
            rev(p);
            int q = find(a + 1, a + i + 1, i - 1) - a;
            rev(q - 1);
            rev(q + 1);
            rev(3);
            rev(i);
        }
        cout << "\n";
        for (int i = 1; i <= n; i += 1) assert(a[i] == i);
    }
    return 0;
}