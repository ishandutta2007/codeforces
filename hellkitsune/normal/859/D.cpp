#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
typedef long double Double;

int n;
Double a[64][64];
Double p[7][64];
Double ans[7][64];

int main() {
    scanf("%d", &n);
    int cnt = 1 << n;
    forn(i, cnt) forn(j, cnt) {
        int x;
        scanf("%d", &x);
        a[i][j] = 0.01 * x;
    }
    forn(i, cnt) p[0][i] = 1;
    forn(i, cnt) ans[0][i] = 0;
    forn(i, n) forn(j, cnt) {
        int from = j;
        from >>= i;
        from ^= 1;
        from <<= i;
        int to = from + (1 << i);
        Double prob = 0;
        for (int k = from; k < to; ++k) {
            prob += p[i][k] * a[j][k];
        }
        p[i + 1][j] = p[i][j] * prob;

        for (int k = from; k < to; ++k) {
            ans[i + 1][j] = max(ans[i + 1][j], ans[i][k] + ans[i][j]);
        }
        ans[i + 1][j] += (1 << i) * p[i + 1][j];
    }
    Double res = 0;
    forn(i, cnt) res = max(res, ans[n][i]);
    printf("%.15f\n", (double)res);
    return 0;
}