#include <bits/stdc++.h>
using namespace std;

int n, m, ans = INT_MAX;
long long a[1 << 20], b[1 << 20];
char s[20][100000];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < m; i++) {
        int S = 0;
        for (int j = 0; j < n; j++) {
            if (s[j][i] == '1') S |= 1 << j;
        }
        a[S]++;
    }
    for (int i = 0; i < 1 << n; i++) {
        int j = __builtin_popcount(i);
        b[i] = min(j, n - j);
    }
    auto FWT = [&](long long *a) {
        for (int i = 1; i < 1 << n; i <<= 1) {
            for (int j = 0; j < 1 << n; j += i << 1) {
                for (int k = 0; k < i; k++) {
                    long long p = a[j + k], q = a[i + j + k];
                    a[j + k] = p + q, a[i + j + k] = p - q;
                }
            }
        }
    };
    FWT(a), FWT(b);
    for (int i = 0; i < 1 << n; i++) {
        a[i] *= b[i];
    }
    FWT(a);
    for (int i = 0; i < 1 << n; i++) {
        ans = min(ans, int(a[i] >> n));
    }
    printf("%d\n", ans);
    return 0;
}