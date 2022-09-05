#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;
int n, m, tot = 1, ch[maxn][2], fail[maxn];
int f[maxn][maxn], g[maxn][maxn];
char s[maxn], t[maxn];

void chk(int &x, int y) {
    if (x > y) x = y;
}

int main() {
    scanf("%d %d %s %s", &n, &m, s + 1, t + 1);
    for (int i = 1; i <= m; i++) {
        ch[i][t[i] - '0'] = i + 1;
    }
    fill(ch[0], ch[0] + 2, 1), fail[0] = 1;
    queue<int> Q; Q.push(1);
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        for (int c : {0, 1}) {
            if (ch[v][c]) fail[ch[v][c]] = ch[fail[v]][c], Q.push(ch[v][c]);
            else ch[v][c] = ch[fail[v]][c];
        }
    }
    memset(f, 0x3f, sizeof(f)), f[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        memset(g, 0x3f, sizeof(g));
        for (int j = 0; j <= n - m + 1; j++) {
            for (int k = 1; k <= m + 1; k++) for (int c : {0, 1}) {
                chk(g[j + (ch[k][c] == m + 1)][ch[k][c]], f[j][k] + (s[i] != c + '0'));
            }
        }
        swap(f, g);
    }
    for (int i = 0; i <= n - m + 1; i++) {
        int ans = INT_MAX;
        for (int j = 1; j <= m + 1; j++) chk(ans, f[i][j]);
        printf("%d ", ans > 1e9 ? -1 : ans);
    }
    return 0;
}