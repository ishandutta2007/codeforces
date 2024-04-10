#include <bits/stdc++.h>
using namespace std;
int n, f[55][55][55][55];
inline int dfs(int a, int b, int c, int d) {
    if(~f[a][b][c][d]) return f[a][b][c][d];
    f[a][b][c][d] = max(b - a + 1, d - c + 1);
    for(int i = a; i < b; i++) f[a][b][c][d] = min(f[a][b][c][d], dfs(a, i, c, d) + dfs(i + 1, b, c, d));
    for(int i = c; i < d; i++) f[a][b][c][d] = min(f[a][b][c][d], dfs(a, b, c, i) + dfs(a, b, i + 1, d));
    // cerr << a << ' ' << b << ' ' << c << ' ' << d << ' ' << f[a][b][c][d] << endl;
    return f[a][b][c][d];
}
char s[60];
int main() {
    memset(f, -1, sizeof f);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for(int j = 1; j <= n; j++) f[i][i][j][j] = s[j] == '#';
    }
    return cout << dfs(1, n, 1, n) << endl, 0;
}