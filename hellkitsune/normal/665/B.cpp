#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, k;
int ord[100];
int a[100][100];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    REP(i, k) scanf("%d", ord + i), --ord[i];
    REP(i, n) REP(j, m) scanf("%d", a[i] + j), --a[i][j];
    int ans = 0;
    REP(i, n) REP(j, m) {
        int need = a[i][j];
        REP(z, k) if (ord[z] == need) {
            for (int zz = z; zz > 0; --zz) {
                ord[zz] = ord[zz - 1];
            }
            ord[0] = need;
            ans += z + 1;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}