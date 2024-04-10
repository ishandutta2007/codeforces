#include <bits/stdc++.h>
using namespace std;

const int maxn = 310;
int T, m, a[maxn], id[maxn], ord[maxn], cnt[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%*d %d", &m);
        for (int i = 1; i <= m; i++) {
            scanf("%d", &a[i]);
        }
        iota(id + 1, id + m + 1, 1);
        sort(id + 1, id + m + 1, [&](int x, int y) {
            return make_pair(a[x], -x) < make_pair(a[y], -y);
        });
        for (int i = 1; i <= m; i++) {
            ord[id[i]] = i;
        }
        int ans = 0;
        fill(cnt + 1, cnt + m + 1, 0);
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j < ord[i]; j++) ans += cnt[j];
            cnt[ord[i]]++;
        }
        printf("%d\n", ans);
    }
    return 0;
}