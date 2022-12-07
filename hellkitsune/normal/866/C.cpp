#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
typedef long double Double;

int n, r;
int f[50], s[50];
Double p[50];

Double d[51][5555];
int sum[51];

int main() {
    scanf("%d%d", &n, &r);
    forn(i, n) {
        int tmp;
        scanf("%d%d%d", f + i, s + i, &tmp);
        p[i] = 0.01 * tmp;
    }
    forn(i, n) sum[i + 1] = sum[i] + s[i];
    Double lo = 0, hi = 1e11, mid;
    forn(_, 100) {
        mid = (lo + hi) / 2;
        memset(d, 0, sizeof d);
        forn(i, r + 1) {
            d[n][i] = 0;
        }
        for (int i = r + 1; i <= sum[n]; ++i) {
            d[n][i] = mid;
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = sum[i]; j >= 0; --j) {
                d[i][j] = p[i] * (min(mid, d[i + 1][j + f[i]]) + f[i]) +
                    (1 - p[i]) * (min(mid, d[i + 1][j + s[i]]) + s[i]);
//                printf("%10.2f ", d[i][j]);
            }
//            puts("");
        }
        if (d[0][0] > mid) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    printf("%.18f\n", (double)lo);
    return 0;
}