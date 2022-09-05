#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, P = 1000000007;
int n, a[maxn], b[maxn], c[maxn];
long long sum[maxn], d[maxn];

int main() {
    scanf("%d", &n);
    // n = 100000;
    // mt19937 rnd(time(0));
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        // a[i] = rnd() % 100000 + 1;
    }
    double st = clock();
    for (int i = 1; i <= n; i++) {
        int m = n / i;
        for (int j = 1; j <= m; j++) {
            b[j] = a[i * j];
        }
        if (i >= 700) {
            for (int j = 1; j <= m; j++) {
                for (int k = 1; k <= m; k++) {
                    sum[i] += __gcd(b[j], b[k]);
                }
            }
        } else {
            memset(c, 0, sizeof(c));
            for (int j = 1; j <= m; j++) {
                c[b[j]]++;
            }
            for (int j = 100000; j; j--) {
                d[j] = 0;
                int num = c[j];
                for (int k = j + j; k <= 100000; k += j) {
                    num += c[k], d[j] -= d[k];
                }
                d[j] += 1LL * num * num;
                sum[i] += 1LL * j * d[j];
            }
        }
    }
    int ans = 0;
    for (int i = n; i; i--) {
        for (int j = i + i; j <= n; j += i) sum[i] -= sum[j];
        ans = (ans + sum[i] % P * i) % P;
    }
    printf("%d\n", ans);
    // cerr << clock() - st << endl;
    return 0;
}