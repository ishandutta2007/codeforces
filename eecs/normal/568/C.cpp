#include <bits/stdc++.h>
using namespace std;

const int maxn = 410;
int n, m, ok, ans[maxn], chk[2];
bitset<maxn> b[maxn];
char type[30], s[maxn], res[maxn];
vector<int> V;

void dfs(int v) {
    if (!ans[v]) ok = 0;
    if (!ok || ~ans[v]) return;
    ans[v] = 1, ans[v <= n ? v + n : (v - n)] = 0;
    V.push_back(v), V.push_back(v <= n ? v + n : (v - n));
    for (int i = 1; i <= 2 * n; i++) if (b[v][i]) dfs(i);
}

int main() {
    scanf("%s", type);
    int l = strlen(type);
    int mn1 = l, mn2 = l;
    for (int i = l - 1; ~i; i--) {
        if (type[i] == 'V') mn1 = i;
        if (type[i] == 'C') mn2 = i;
    }
    scanf("%d %d", &n, &m);
    for (int i = 1, p1, p2; i <= m; i++) {
        char s[2], t[2];
        scanf("%d %s %d %s", &p1, s, &p2, t);
        if (s[0] == 'C') p1 += n;
        if (t[0] == 'C') p2 += n;
        b[p1][p2] = 1;
        p1 = p1 <= n ? p1 + n : (p1 - n);
        p2 = p2 <= n ? p2 + n : (p2 - n);
        b[p2][p1] = 1;
    }
    scanf("%s", s + 1);
    for (int i = n; i; i--) {
        memset(chk, 0, sizeof(chk));
        for (int j = s[i] - 'a' + (i < n); j < l; j++) {
            int t = type[j] == 'C';
            if (chk[t]) continue;
            memset(ans, -1, sizeof(ans));
            ok = chk[t] = 1;
            for (int k = 1; k <= i; k++) {
                int c = k < i ? s[k] - 'a' : j;
                res[k] = c + 'a';
                dfs(type[c] == 'V' ? k : (k + n));
            }
            if (!ok) continue;
            for (int k = i + 1; k <= n && ok; k++) {
                V.clear();
                if (mn1 < mn2) {
                    res[k] = mn1 + 'a', dfs(k);
                    if (!ok) {
                        ok = 1;
                        if (mn2 == l) ok = 0;
                        for (int v : V) ans[v] = -1;
                        res[k] = mn2 + 'a', dfs(k + n);
                    }
                } else {
                    res[k] = mn2 + 'a', dfs(k + n);
                    if (!ok) {
                        ok = 1;
                        if (mn1 == l) ok = 0;
                        for (int v : V) ans[v] = -1;
                        res[k] = mn1 + 'a', dfs(k);
                    }
                }
            }
            if (ok) printf("%s\n", res + 1), exit(0);
        }
    }
    puts("-1");
    return 0;
}