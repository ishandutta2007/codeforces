#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
bool used[51] = {};
int a[51][51];
int p[51];

int main() {
    scanf("%d", &n);
    REP(i, n) REP(j, n) scanf("%d", a[i] + j);
    for (int i = 1; i <= n; ++i) {
        REP(j, n) if (!used[j]) {
            bool ok = true;
            REP(k, n) if (k != j && !used[k] && (a[j][k] != i || a[k][j] != i)) {
                ok = false;
                break;
            }
            if (ok) {
                p[j] = i;
                used[j] = true;
                break;
            }
        }
    }
    REP(i, n) if (p[i] == 0) p[i] = n;
    REP(i, n) printf("%d ", p[i]);
    printf("\n");
    return 0;
}