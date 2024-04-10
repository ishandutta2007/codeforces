#include <bits/stdc++.h>
using namespace std;

const int maxn = 210, P = 1000000007;
int n, m, K, len1, len2, a[maxn], b[maxn];
int tot = 1, ch[maxn][20], ed[maxn], fail[maxn];
int ans, f[maxn][maxn][510][2][2];

void red(int &x) {
    x += x >> 31 & P;
}

int main() {
    scanf("%d %d %d %d", &n, &m, &K, &len1);
    for (int i = 1; i <= len1; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &len2);
    for (int i = 1; i <= len2; i++) {
        scanf("%d", &b[i]);
    }
    while (n--) {
        int len, v;
        scanf("%d", &len);
        int cur = 1;
        while (len--) {
            int x; scanf("%d", &x);
            if (!ch[cur][x]) ch[cur][x] = ++tot;
            cur = ch[cur][x];
        }
        scanf("%d", &v), ed[cur] += v;
    }
    fill(ch[0], ch[0] + m, 1), fail[0] = 1;
    queue<int> Q; Q.push(1);
    while (!Q.empty()) {
        int v = Q.front(); Q.pop(), ed[v] += ed[fail[v]];
        for (int i = 0; i < m; i++) {
            if (ch[v][i]) fail[ch[v][i]] = ch[fail[v]][i], Q.push(ch[v][i]);
            else ch[v][i] = ch[fail[v]][i];
        }
    }
    f[1][1][0][0][0] = 1;
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= tot; j++) {
            for (int k = 0; k <= K; k++) {
                for (int p : {0, 1}) for (int q : {0, 1}) if (f[i][j][k][p][q]) {
                    for (int c = 0; c <= (q ? m - 1 : a[i]); c++) {
                        int np = p | (c > 0), nj = np ? ch[j][c] : j;
                        int nk = k + ed[nj];
                        if (nk > K) continue;
                        red(f[i + 1][nj][nk][np][q | (c < a[i])] += f[i][j][k][p][q] - P);
                    }
                }
            }
        }
    }
    for (int i = 1; i <= tot; i++) {
        for (int j = 0; j <= K; j++) for (int p : {0, 1}) {
            red(ans -= f[len1 + 1][i][j][p][1]);
        }
    }
    memset(f, 0, sizeof(f)), f[1][1][0][0][0] = 1;
    for (int i = 1; i <= len2; i++) {
        for (int j = 1; j <= tot; j++) {
            for (int k = 0; k <= K; k++) {
                for (int p : {0, 1}) for (int q : {0, 1}) if (f[i][j][k][p][q]) {
                    for (int c = 0; c <= (q ? m - 1 : b[i]); c++) {
                        int np = p | (c > 0), nj = np ? ch[j][c] : j;
                        int nk = k + ed[nj];
                        if (nk > K) continue;
                        red(f[i + 1][nj][nk][np][q | (c < b[i])] += f[i][j][k][p][q] - P);
                    }
                }
            }
        }
    }
    for (int i = 1; i <= tot; i++) {
        for (int j = 0; j <= K; j++) {
            for (int p : {0, 1}) for (int q : {0, 1}) {
                red(ans += f[len2 + 1][i][j][p][q] - P);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}