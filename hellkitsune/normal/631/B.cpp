#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, k;
int t[100000], x[100000], a[100000];
bool used[2][5000] = {};
bool g[100000];
vector<int> v[5000];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    REP(i, n) v[i].resize(m);
    REP(i, k) scanf("%d%d%d", t + i, x + i, a + i), --t[i], --x[i];
    for (int i = k - 1; i >= 0; --i) {
        g[i] = !used[t[i]][x[i]];
        used[t[i]][x[i]] = true;
    }
    REP(i, k) if (g[i]) {
        if (t[i] == 0) {
            int r = x[i], col = a[i];
            REP(j, m) v[r][j] = col;
        } else {
            int c = x[i], col = a[i];
            REP(j, n) v[j][c] = col;
        }
    }
    REP(i, n) {
        REP(j, m) printf("%d ", v[i][j]);
        printf("\n");
    }
    return 0;
}