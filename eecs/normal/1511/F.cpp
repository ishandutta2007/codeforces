#include <bits/stdc++.h>
using namespace std;

const int maxn = 250, P = 998244353;
int n, m, V = 1, tot, mp[maxn][maxn], ed[maxn], ch[maxn][26];
struct mat { int a[maxn][maxn]; } A, B;

mat operator * (const mat &A, const mat &B) {
    mat C; memset(C.a, 0, sizeof(C.a));
    for (int i = 1; i <= tot; i++) {
        for (int j = 1; j <= tot; j++) if (A.a[i][j]) {
            for (int k = 1; k <= tot; k++) if (B.a[j][k]) {
                C.a[i][k] = (C.a[i][k] + 1LL * A.a[i][j] * B.a[j][k]) % P;
            }
        }
    }
    return C;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    while (n--) {
        string s; cin >> s;
        int cur = 1;
        for (char $ : s) {
            int c = $ - 'a';
            if (!ch[cur][c]) ch[cur][c] = ++V;
            cur = ch[cur][c];
        }
        ed[cur] = 1;
    }
    queue<pair<int, int>> Q;
    Q.emplace(1, 1), mp[1][1] = ++tot;
    while (!Q.empty()) {
        int u = Q.front().first, v = Q.front().second; Q.pop();
        for (int c = 0; c < 26; c++) if (ch[u][c] && ch[v][c]) {
            int x = ch[u][c], y = ch[v][c];
            for (int a : {0, 1}) for (int b : {0, 1}) {
                if (!ed[x] && a || !ed[y] && b) continue;
                int nx = a ? 1 : x, ny = b ? 1 : y;
                if (!mp[nx][ny]) Q.emplace(nx, ny), mp[nx][ny] = ++tot;
                A.a[mp[u][v]][mp[nx][ny]]++;
            }
        }
    }
    B.a[1][1] = 1;
    for (; m; m >>= 1, A = A * A) {
        if (m & 1) B = B * A;
    }
    printf("%d\n", B.a[1][1]);
    return 0;
}