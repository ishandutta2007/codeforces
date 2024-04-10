#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

unsigned long long a[36][36];

int main() {
    int n, h;
    scanf("%d%d", &n, &h);
    a[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < i; k++) {
                a[i][j] -= a[k][j - 1] * a[i - k - 1][j - 1];
                for (int t = 0; t <= j - 1; t++) {
                    a[i][j] += a[k][j - 1] * a[i - k - 1][t] + a[k][t] * a[i - k - 1][j - 1];
                }
            }
        }
    }
    unsigned long long ans = 0;
    for (int i = h; i <= n; i++)
        ans += a[n][i];
    cout << ans << endl;
    return 0;
}