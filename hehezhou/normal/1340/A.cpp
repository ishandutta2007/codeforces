#include <bits/stdc++.h>
using namespace std;
int t;
int n, a[100010];
int sze[100010], fa[100010], now, vis[100010];
inline int gf(int a) {
    return fa[a] == a ? a : fa[a] = gf(fa[a]);
}
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        multiset < int > now;
        for (int i = 1; i <= n; i++) {
            int p;
            scanf("%d", &p);
            a[p] = i;
            fa[i] = i, sze[i] = 1;
            vis[i] = 0;
            now.insert(1);
        }
        int ans = 1, r = n;
        for (int i = 1; i <= n; i++) {
            vis[a[i]] = 1;
            if (sze[gf(a[i])] != *--now.end()) {
                ans = 0;
                break;
            }
            if (a[i] < r) {
                now.erase(now.lower_bound(sze[gf(a[i])]));
                now.erase(now.lower_bound(sze[gf(a[i] + 1)]));
                sze[gf(a[i] + 1)] += sze[gf(a[i])];
                now.insert(sze[gf(a[i] + 1)]);
                fa[gf(a[i])] = gf(a[i] + 1);
            }
            else {
                now.erase(now.lower_bound(sze[gf(a[i])]));
            }
            while (r && vis[r]) r--;
        }
        puts(ans ? "Yes" : "No");
    }
}