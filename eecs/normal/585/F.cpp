#include <bits/stdc++.h>
using namespace std;

const int maxn = 30010, P = 1000000007;
int tot = 1, ans, ch[maxn][10], ed[maxn], fail[maxn], f[55][maxn][2][2][2];
char s[maxn], L[maxn], R[maxn];

void red(int &x) {
    x += x >> 31 & P;
}

int main() {
    scanf("%s %s %s", s, L, R);
    int n = strlen(s), D = strlen(L), d = D >> 1;
    for (int i = 0; i + d <= n; i++) {
        int cur = 1;
        for (int j = i; j < i + d; j++) {
            int c = s[j] - '0';
            if (!ch[cur][c]) ch[cur][c] = ++tot;
            cur = ch[cur][c];
        }
        ed[cur] = 1;
    }
    fill(ch[0], ch[0] + 10, 1);
    queue<int> Q; Q.push(1);
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        ed[v] |= ed[fail[v]];
        for (int c = 0; c < 10; c++) {
            if (ch[v][c]) fail[ch[v][c]] = ch[fail[v]][c], Q.push(ch[v][c]);
            else ch[v][c] = ch[fail[v]][c];
        }
    }
    f[0][1][1][1][0] = 1;
    for (int i = 0; i < D; i++) {
        int l = L[i] - '0', r = R[i] - '0';
        for (int j = 1; j <= tot; j++) {
            for (int lb : {0, 1}) for (int rb : {0, 1}) for (int t : {0, 1}) {
                if (!f[i][j][lb][rb][t]) continue;
                for (int c = 0; c < 10; c++) {
                    if (lb && c < l || rb && c > r) continue;
                    red(f[i + 1][ch[j][c]][lb & (c == l)][rb & (c == r)][t |
                        ed[ch[j][c]]] += f[i][j][lb][rb][t] - P);
                }
            }
        }
    }
    for (int i = 1; i <= tot; i++) {
        for (int lb : {0, 1}) for (int rb : {0, 1}) {
            red(ans += f[D][i][lb][rb][1] - P);
        }
    }
    printf("%d\n", ans);
    return 0;
}