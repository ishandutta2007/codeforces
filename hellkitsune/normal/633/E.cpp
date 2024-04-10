#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
typedef long double Double;

int n, k;
int v[20][1000000], c[20][1000000];
int sz[1000005];
int val[1000000];
Double f[2000005];

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    REP(i, n) scanf("%d", v[0] + i);
    REP(i, n) scanf("%d", c[0] + i);
    REP(i, 19) REP(j, n - (2 << i) + 1) {
        v[i + 1][j] = max(v[i][j], v[i][j + (1 << i)]);
        c[i + 1][j] = min(c[i][j], c[i][j + (1 << i)]);
    }
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
        while ((2 << cur) < i) ++cur;
        sz[i] = cur;
    }
    REP(i, n) {
        int lo = i - 1, hi = n - 1, mid;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            int s = sz[mid - i + 1];
            int a = 100 * max(v[s][i], v[s][mid - (1 << s) + 1]);
            int b = min(c[s][i], c[s][mid - (1 << s) + 1]);
            if (a <= b) lo = mid;
            else hi = mid - 1;
        }
        val[i] = 0;
        for (int j = max(lo, i); j <= min(lo + 1, n - 1); ++j) {
            int s = sz[j - i + 1];
            int a = 100 * max(v[s][i], v[s][j - (1 << s) + 1]);
            int b = min(c[s][i], c[s][j - (1 << s) + 1]);
            val[i] = max(val[i], min(a, b));
        }
    }
   /*REP(i, n) printf("%d ", val[i]);
    printf("\n");*/
    sort(val, val + n);
    f[0] = f[1] = 0;
    for (int i = 2; i < 2 * n + 3; ++i) {
        f[i] = f[i - 1] + log((Double)i);
    }
    Double ans = 0;
    REP(i, n) {
        //c(n - i - 1, k - 1) / c(n, k)
        if (n - i < k) break;
        Double z = f[n - i - 1] - f[k - 1] - f[n - i - k] - f[n] + f[k] + f[n - k];
        ans += exp(z) * val[i];
    }
    printf("%.15f\n", (double)ans);
    return 0;
}