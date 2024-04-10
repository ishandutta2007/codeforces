#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, a[maxn], b[maxn], c[maxn], d[maxn], k[maxn];
int id1[maxn], id2[maxn], ans[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i], &b[i]), id1[i] = i;
    }
    sort(id1 + 1, id1 + n + 1, [&](int x, int y) { return b[x] < b[y]; });
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &c[i], &d[i], &k[i]), id2[i] = i;
    }
    sort(id2 + 1, id2 + m + 1, [&](int x, int y) { return d[x] < d[y]; });
    set<pair<int, int>> S;
    int cur = 1;
    for (int $ = 1; $ <= m; $++) {
        int i = id2[$];
        for (; cur <= n && b[id1[cur]] <= d[i]; cur++) {
            S.emplace(a[id1[cur]], id1[cur]);
        }
        while (k[i]--) {
            auto it = S.lower_bound(make_pair(c[i], 0));
            if (it == S.end()) break;
            ans[it->second] = i, S.erase(it);
        }
    }
    if (cur <= n || !S.empty()) puts("NO"), exit(0);
    puts("YES");
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}