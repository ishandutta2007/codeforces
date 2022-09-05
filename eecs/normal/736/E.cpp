#include <bits/stdc++.h>
using namespace std;

const int maxn = 3010;
int m, n, a[maxn], sufl[maxn], sufr[maxn], id[maxn];
char ans[maxn][maxn];

int main() {
    scanf("%d %d", &m, &n);
    int rem = m * (m - 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), rem -= a[i];
    }
    if (rem < 0) puts("no"), exit(0);
    for (int i = n + 1; i <= m; i++) {
        a[i] = min(a[i - 1], rem / (m - i + 1) + (rem % (m - i + 1) > 0));
        rem -= a[i];
    }
    if (rem) puts("no"), exit(0);
    for (int i = 1, s = 0; i <= m; i++) {
        s += a[i];
        int t = s - i * (i - 1), tmp = 2 * (m - i - 1);
        for (int j = i + 1; j <= m; j++) {
            t -= 2 * i - max(0, a[j] - tmp);
        }
        if (t > 0) puts("no"), exit(0);
    }
    puts("yes");
    iota(id + 1, id + m + 1, 1);
    for (int i = m; i; i--) {
        sort(id + 1, id + i + 1, [&](int x, int y) { return a[x] > a[y]; });
        sufl[i] = sufr[i] = 0;
        for (int j = i - 1; j; j--) {
            sufl[j] = sufl[j + 1], sufr[j] = sufr[j + 1];
            sufl[j] += !a[id[j]] ? 2 : a[id[j]] <= 1 ? 1 : 0, sufr[j] += 2;
        }
        auto in = [&](int x, int l, int r) { return x >= l && x <= r; };
        for (int j = 1; j < i; j++) {
            if (a[id[j]] >= 2 && in(a[id[i]], sufl[j + 1], sufr[j + 1])) {
                a[id[j]] -= 2, ans[id[i]][id[j]] = 'L';
            } else if (a[id[j]] && a[id[i]] && in(a[id[i]] - 1, sufl[j + 1], sufr[j + 1])) {
                a[id[i]]--, a[id[j]]--, ans[id[i]][id[j]] = 'D';
            } else {
                a[id[i]] -= 2, ans[id[i]][id[j]] = 'W';
            }
        }
        assert(!a[id[i]]);
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == j) ans[i][j] = 'X';
            else if (ans[j][i] == 'D') ans[i][j] = 'D';
            else if (ans[j][i] == 'W') ans[i][j] = 'L';
            else if (ans[j][i] == 'L') ans[i][j] = 'W';
        }
        printf("%s\n", ans[i] + 1);
    }
    return 0;
}