#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, a, b;
int ans[100][100] = {};

int main() {
    scanf("%d%d%d", &n, &a, &b);
    int o = 1, e = 2;
    REP(i, a) REP(j, b) if ((i ^ j) & 1) {
        if (e <= n) {
            ans[i][j] = e;
            e += 2;
        }
    } else {
        if (o <= n) {
            ans[i][j] = o;
            o += 2;
        }
    }
    if (o <= n || e <= n) {
        printf("-1\n");
        return 0;
    }
    REP(i, a) {
        REP(j, b) printf("%d ", ans[i][j]);
        printf("\n");
    }
    return 0;
}