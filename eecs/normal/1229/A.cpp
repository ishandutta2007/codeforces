#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 7010;
int n, id[maxn], vis[maxn];
ll ans, a[maxn], b[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &b[i]);
    }
    iota(id + 1, id + n + 1, 1);
    sort(id + 1, id + n + 1, [&](int x, int y) { return a[x] > a[y]; });
    for (int i = 1, j; i <= n; i = j) {
        for (j = i; j <= n && a[id[i]] == a[id[j]]; j++);
        if (j - i > 1) {
            for (int k = 1; k <= n; k++) {
                if ((a[id[i]] & a[id[k]]) == a[id[k]]) vis[id[k]] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (vis[id[i]]) ans += b[id[i]];
    }
    printf("%lld\n", ans);
    return 0;
}