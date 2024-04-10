#include <bits/stdc++.h>
using namespace std;

const int maxn = 8010;
int n, sz, ind[maxn], del[maxn];
char s[maxn];
long long ans;
bitset<maxn> e[maxn];

int main() {
    scanf("%d", &n), sz = n;
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for (int j = 1, $ = 0; j <= n; j++) {
            int x = isdigit(s[++$]) ? s[$] - '0' : s[$] - 'A' + 10;
            e[i][j] = x >> 3 & 1, e[i][++j] = x >> 2 & 1;
            e[i][++j] = x >> 1 & 1, e[i][++j] = x & 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (e[i][j]) ind[j]++;
        }
    }
    while (1) {
        int id = -1;
        for (int i = 1; i <= n; i++) {
            if (!del[i] && !ind[i]) { id = i; break; }
        }
        if (!~id) break;
        del[id] = 1, sz--;
        ans += 1LL * sz * (614 * n + 1);
        for (int i = 1; i <= n; i++) {
            if (e[id][i]) ind[i]--;
        }
    }
    ans += sz * (sz - 1) / 2;
    for (int i = 1; i <= n; i++) if (!del[i]) {
        int id = -1;
        for (int j = 1; j <= n; j++) if (e[i][j]) {
            if (!~id || e[id][j]) id = j;
        }
        for (int j = 1; j <= n; j++) if (!del[j]) {
            if (i ^ j && !e[i][j]) ans += e[id][j] ? 2 : 3;
        }
    }
    printf("%lld\n", ans);
    return 0;
}