#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int d[501][501] = {};
int n, a[500];
const int INF = 1e9;

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    REP(i, n) d[i][i] = d[i + 1][i] = 1;
    for (int len = 2; len <= n; ++len) {
        REP(i, n - len + 1) {
            int j = i + len - 1;
            d[i][j] = INF;
            if (a[i] == a[j]) {
                d[i][j] = d[i + 1][j - 1];
            }
            for (int k = i; k < j; ++k) {
                d[i][j] = min(d[i][j], d[i][k] + d[k + 1][j]);
            }
        }
    }
    printf("%d\n", d[0][n - 1]);
    return 0;
}