#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[151];
char s[155];
int d[151][151][151];
int best[151];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i + 1);
    a[0] = -1;
    scanf("%s", s);
    memset(d, -1, sizeof d);
    REP(i, n) d[i][i][0] = 0;
    for (int len = 1; len <= n; ++len) {
        REP(i, n - len + 1) {
            int j = i + len;
            REP(skip, len + 1) {
                int &val = d[i][j][skip];
                if (skip >= 2 && len > 1 && s[i] == s[j - 1]) {
                    val = d[i + 1][j - 1][skip - 2];
                }
                if (skip == 1 && len == 1) {
                    val = 0;
                }
                for (int mid = i + 1; mid < j; ++mid) {
                    if (d[i][mid][skip] >= 0 && d[mid][j][0] >= 0) {
                        val = max(val, d[i][mid][skip] + d[mid][j][0]);
                    }
                    if (d[i][mid][0] >= 0 && d[mid][j][skip] >= 0) {
                        val = max(val, d[i][mid][0] + d[mid][j][skip]);
                    }
                }
                if (a[skip] >= 0 && val >= 0) {
                    d[i][j][0] = max(d[i][j][0], val + a[skip]);
                }
            }
        }
    }
    best[0] = 0;
    for (int i = 1; i <= n; ++i) {
        best[i] = best[i - 1];
        REP(j, i) if (d[j][i][0] >= 0) best[i] = max(best[i], best[j] + d[j][i][0]);
    }
    printf("%d\n", best[n]);
    return 0;
}