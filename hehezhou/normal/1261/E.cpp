#include <bits/stdc++.h>
using namespace std;
char ans[1010][1010];
int n, a[1010];
int main() {
    ios :: sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++)
        for (int j = 1; j <= n; j++) ans[i][j] = '0';
    for (int i = n, now = 0; i > 0; i--) {
        for (int j = 1; j <= n; j++) {
            if (a[j] == i) {
                while (a[j] --> 0) ans[(now + a[j]) % (n + 1)][j] = '1';
                now++;
            }
        }
    }
    cout << n + 1 << endl;
    for (int i = 0; i <= n; i++) cout << ans[i] + 1 << endl;
    return 0;
}