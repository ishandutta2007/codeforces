#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, q, a[maxn], c[4][11][10][maxn];
char s[maxn], t[11];
map<char, int> mp;

void add(int *c, int p, int v) {
    for (; p <= n; p += p & -p) c[p] += v;
}

int sum(int *c, int p) {
    int s = 0;
    for (; p; p -= p & -p) s += c[p];
    return s;
}

int main() {
    mp['A'] = 0, mp['G'] = 1, mp['T'] = 2, mp['C'] = 3;
    scanf("%s", s + 1), n = strlen(s + 1);
    scanf("%d", &q);
    for (int i = 1; i <= n; i++) {
        a[i] = mp[s[i]];
        for (int j = 1; j <= 10; j++) add(c[a[i]][j][i % j], i, 1);
    }
    while (q--) {
        int op; scanf("%d", &op);
        if (op == 1) {
            int x; scanf("%d %s", &x, t);
            for (int j = 1; j <= 10; j++) add(c[a[x]][j][x % j], x, -1);
            a[x] = mp[t[0]];
            for (int j = 1; j <= 10; j++) add(c[a[x]][j][x % j], x, 1);
        } else {
            int l, r; scanf("%d %d %s", &l, &r, t);
            int m = strlen(t), ans = 0;
            for (int i = l; i <= min(r, l + m - 1); i++) {
                int j = i % m, x = mp[t[i - l]];
                ans += sum(c[x][m][j], r) - sum(c[x][m][j], l - 1);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}