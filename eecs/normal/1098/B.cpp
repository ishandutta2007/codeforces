#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, m, mn = INT_MAX, a[maxn], b[maxn], ans[maxn];
int cnt[3][maxn][4], f[maxn][4][4];
pair<int, int> pre[maxn][4][4];
char t[maxn];
map<char, int> mp;
bool flag;

inline int id(int x, int y) {
    return (x - 1) * m + y;
}

int main() {
    scanf("%d %d", &n, &m);
    mp['A'] = 0, mp['G'] = 1, mp['C'] = 2, mp['T'] = 3;
    for (int i = 1; i <= n; i++) {
        scanf("%s", t + 1);
        for (int j = 1; j <= m; j++) {
            a[id(i, j)] = mp[t[j]];
            if (i & 1) cnt[1][j][mp[t[j]]]++;
            else cnt[2][j][mp[t[j]]]++;
        }
    }
    auto solve = [&]() {
        memset(f, -1, sizeof(f));
        for (int i : {0, 1, 2, 3}) for (int j : {0, 1, 2, 3}) if (i ^ j) {
            f[1][i][j] = cnt[1][1][i] + cnt[2][1][j];
        }
        for (int i = 1; i < m; i++) for (int a : {0, 1, 2, 3}) {
            for (int b : {0, 1, 2, 3}) if (~f[i][a][b]) {
                for (int c : {0, 1, 2, 3}) if (a ^ c && b ^ c) {
                    for (int d : {0, 1, 2, 3}) if (a ^ d && b ^ d && c ^ d) {
                        int num = f[i][a][b] + cnt[1][i + 1][c] + cnt[2][i + 1][d];
                        if (num > f[i + 1][c][d]) f[i + 1][c][d] = num, pre[i + 1][c][d] = make_pair(a, b);
                    }
                }
            }
        }
    };
    solve();
    int mx1 = 0, ta, tb;
    for (int a : {0, 1, 2, 3}) for (int b : {0, 1, 2, 3}) {
        if (f[m][a][b] > mx1) mx1 = f[m][a][b], ta = a, tb = b;
    }
    function<void(int, int, int)> print = [&](int i, int a, int b) {
        for (int j = 1; j <= n; j++) {
            if (j & 1) ans[id(j, i)] = a;
            else ans[id(j, i)] = b;
        }
        if (i > 1) print(i - 1, pre[i][a][b].first, pre[i][a][b].second);
    };
    print(m, ta, tb);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            b[(j - 1) * n + i] = a[id(i, j)];
        }
    }
    swap(n, m), flag = 1;
    memcpy(a, b, sizeof(a));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i & 1) cnt[1][j][a[id(i, j)]]++;
            else cnt[2][j][a[id(i, j)]]++;
        }
    }
    solve();

    int mx2 = 0;
    for (int a : {0, 1, 2, 3}) for (int b : {0, 1, 2, 3}) {
        if (f[m][a][b] > mx2) mx2 = f[m][a][b], ta = a, tb = b;
    }
    if (mx1 > mx2) {
        swap(n, m), flag = 0;
    } else {
        print(m, ta, tb);
    }
    if (!flag) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                putchar("AGCT"[ans[id(i, j)]]);
            }
            putchar('\n');
        }
    } else {
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                putchar("AGCT"[ans[id(j, i)]]);
            }
            putchar('\n');
        }
    }
    return 0;
}