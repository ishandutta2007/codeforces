#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int a[4][111];
int p[4] = {1, 0, 2, 3};
int n, m;

int main() {
    memset(a, -1, sizeof a);
    cin >> n >> m;
    int cur = 1;
    REP(i, n) {
        if (cur <= m) a[0][i] = cur++;
        if (cur <= m) a[3][i] = cur++;
    }
    REP(i, n) {
        if (cur <= m) a[1][i] = cur++;
        if (cur <= m) a[2][i] = cur++;
    }
    REP(i, n) REP(jj, 4) {
        int j = p[jj];
        if (a[j][i] > 0) {
            printf("%d ", a[j][i]);
        }
    }
    printf("\n");
    return 0;
}