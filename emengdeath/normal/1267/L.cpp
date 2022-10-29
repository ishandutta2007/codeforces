#include <bits/stdc++.h>
#define N 1007
using namespace std;
int n, l, k, c[26];
char s[N * N], ans[N][N];
void put(int i, int x, int y, int L) {
    for(int u = x; u <= y; ++ u)
        for(int v = i; v <= l; ++ v) ans[u][v] = s[++ L];
}
void solve(int i, int j, int L, int R) {
    if(i > l) return;
    for(int u = j; u <= k; ++ u) ans[u][i] = s[L ++];
    int u = k;
    while(u >= j && ans[u][i] == ans[k][i]) -- u;
    R -= (u - j + 1) * (l - i);
    put(i + 1, j, u, R);
    solve(i + 1, u + 1, L, R);
}
int main() {
    scanf("%d%d%d%s", &n, &l, &k, s + 1);
    sort(s + 1, s + n * l + 1);
    put(1, k + 1, n, k * l);
    solve(1, 1, 1, k * l);
    for(int i = 1; i <= n; puts(""), ++ i)
        for(int j = 1; j <= l; ++ j) putchar(ans[i][j]);
}