#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n;
long long c[maxn];
unsigned long long ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &c[i]);
    }
    for (int i = 1; i <= n; i++) if (i & 1) {
        long long cl = 0, cr = 0;
        for (int j = i + 1; j <= n; j++) {
            if (j - 1 > i) {
                int k = j - 1;
                if (k & 1) {
                    cl += c[k];
                } else {
                    long long t = min(cl, c[k]);
                    cl -= t, cr += c[k] - t;
                }
            }
            if ((j - i) % 2 == 1) {
                ans += max(0LL, min(c[i] - cr + (cr > 0), c[j] - cl + (cl > 0)));
            }
        }
    }
    printf("%llu\n", ans);
    return 0;
}