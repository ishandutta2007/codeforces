#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, q;
int qt[10000], a[10000], b[10000], c[10000];

int mat[100][100];

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &q);
    REP(i, q) {
        scanf("%d%d", qt + i, a + i);
        if (qt[i] == 3) {
            scanf("%d%d", b + i, c + i);
        }
    }
    REP(i, n) REP(j, m) mat[i][j] = 0;
    for (int i = q - 1; i >= 0; --i) {
        if (qt[i] == 1) {
            int r = a[i] - 1;
            int rem = mat[r][m - 1];
            for (int j = m - 1; j > 0; --j) {
                mat[r][j] = mat[r][j - 1];
            }
            mat[r][0] = rem;
        } else if (qt[i] == 2) {
            int c = a[i] - 1;
            int rem = mat[n - 1][c];
            for (int j = n - 1; j > 0; --j) {
                mat[j][c] = mat[j - 1][c];
            }
            mat[0][c] = rem;
        } else {
            mat[a[i] - 1][b[i] - 1] = c[i];
        }
    }
    REP(i, n) {
        REP(j, m) printf("%d ", mat[i][j]);
        printf("\n");
    }
    return 0;
}