#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

double d[1 << 20] = {};
int pc[1 << 20];
int n, k, on;
double p[20];
double ans[20] = {};
int pos[20];

int main() {
    //freopen("input.txt", "r", stdin);
    REP(i, 1 << 20) pc[i] = __builtin_popcount(i);
    scanf("%d%d", &n, &k);
    int cnt = 0;
    REP(i, n) {
        double x;
        scanf("%lf", &x);
        if (x > 1e-5) {
            p[cnt] = x;
            pos[cnt++] = i;
        }
    }
    on = n;
    n = cnt;
    k = min(k, n);
    if (k == n) {
        REP(i, n) ans[pos[i]] = 1;
        REP(i, on) printf("%.12f ", ans[i]);
        printf("\n");
        return 0;
    }
    d[0] = 1;
    REP(mask, 1 << n) if (pc[mask] < k) {
        double tot = 0;
        REP(i, n) if (!(mask & (1 << i))) {
            tot += p[i];
        }
        tot = d[mask] / tot;
        REP(i, n) if (!(mask & (1 << i))) {
            double prob = p[i] * tot;
            ans[pos[i]] += prob;
            d[mask | (1 << i)] += prob;
        }
    }
    //REP(i, n) ans[pos[i]] -= 2 * p[i];
    REP(i, on) printf("%.12f ", ans[i]);
    printf("\n");
    return 0;
}