#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;
typedef long long ll;

ll expo(ll a, ll b) {
    if(!b) return 1;
    a %= MOD;
    if(b & 1) return a * expo(a * a, b >> 1) % MOD;
    return expo(a * a, b >> 1);
}

ll inv_mod(ll x) {return expo(x, MOD - 2);}

ll dist(ll x1, ll y1, ll x2, ll y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int r, a[4], val[4], cont, id[103][103], mat[7850][7850], ans[7850];
pair<int, int> cell[7900];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void gauss(int a[7850][7850], int n, int m, int *ans) {
    int margin = 0;
    for(int row = 0; row < n; row++) {
        int x = cell[row].first, y = cell[row].second;
        margin = max(margin, id[x+1][y]);

        for(int i = row + 1; i <= margin; i++) {
            int coef = 1LL * a[i][row] * inv_mod(a[row][row]) % MOD;
            for(int j = row; coef && j <= margin; j++) {
                a[i][j] -= 1LL * a[row][j] * coef % MOD;
                if(a[i][j] < 0) a[i][j] += MOD;
            }
            a[i][m] -= 1LL * a[row][m] * coef % MOD;
            if(a[i][m] < 0) a[i][m] += MOD;
        }
    }

    for(int row = n - 1; ~row; row--) {
        for(int col = n - 1; col > row; col--) {
            a[row][m] -= 1LL * a[row][col] * ans[col] % MOD;
            if(a[row][m] < 0) a[row][m] += MOD;
        }
        ans[row] = a[row][m] * inv_mod(a[row][row]) % MOD;
    }
}

int main() {
    scanf("%d %d %d %d %d", &r, &a[0], &a[1], &a[2], &a[3]);

    r *= r;
    for(int d = 0; d < 4; d++) {
        val[d] = 1LL * a[d] * inv_mod(a[0] + a[1] + a[2] + a[3]) % MOD;
    }

    memset(id, -1, sizeof id);

    for(int i = 0; i <= 102; i++) {
        for(int j = 0; j <= 102; j++) {
            if(dist(51, 51, i, j) <= r) {
                id[i][j] = cont;
                cell[cont++] = {i, j};
            }
        }
    }

    for(int i = 0; i < cont; i++) {
        mat[i][i] = 1; mat[i][cont] = 1;
        for(int d = 0; d < 4; d++) {
            int nx = cell[i].first + dx[d], ny = cell[i].second + dy[d];
            if(id[nx][ny] == -1) continue;
            mat[i][id[nx][ny]] -= val[d];
            if(mat[i][id[nx][ny]] < 0) mat[i][id[nx][ny]] += MOD;
        }
    }

    gauss(mat, cont, cont, ans);

    printf("%d\n", ans[id[51][51]]);
    return 0;
}