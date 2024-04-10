#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int x[222];
double p[222222] = {}, q[222222] = {}, sums[222222] = {};
int from = 0, to = 0;
const double EPS = 1e-17;

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%d", x + i), --x[i];
    if (n == 1) {
        printf("%d\n", x[0] + 1);
        return 0;
    } else if (m == 1) {
        printf("%d\n", 1);
        return 0;
    }
    int sum = 0;
    REP(i, n) sum += x[i];
    double mul = 1.0 / (m - 1);
    p[0] = 1;
    sums[0] = 1;
    REP(i, n) {
        int tto = min(n * (m - 1), to + m - 1);
        for (int z = to + 1; z <= tto; ++z) p[z] = 0;
        sums[from] = p[from];
        for (int z = from + 1; z <= tto; ++z) sums[z] = sums[z - 1] + p[z];
        for (int z = from; z <= tto; ++z) q[z] = 0;
        for (int j = from; j <= tto; ++j) {
            //q[j] = sums[j] - sums[j - x[i]] + sums[j - x[i] - 1] - sums[j - m];
            q[j] = sums[j];
            if (j - x[i] >= from) {
                q[j] -= sums[j - x[i]];
                if (j - x[i] - 1 >= from) {
                    q[j] += sums[j - x[i] - 1];
                    if (j - m >= from) {
                        q[j] -= sums[j - m];
                    }
                }
            }
        }
        while (q[from] < EPS) p[from] = 0, ++from;
        while (q[tto] < EPS) p[tto] = 0, --tto;
        to = tto;
        for (int z = from; z <= to; ++z) p[z] = q[z] * mul;
        //printf("%d %d\n", from, to);
    }
    double ans = 0;
    for (int i = from; i <= min(to, sum - 1); ++i) ans += p[i];
    ans = 1 + ans * (m - 1);
    printf("%.15f\n", ans);
    return 0;
}