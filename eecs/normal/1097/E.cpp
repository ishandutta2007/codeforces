#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, n, vis[maxn], a[maxn], f[maxn], pre[maxn];
vector<vector<int>> ans;
vector<int> foo, V[maxn];

int main() {
    scanf("%d", &T), V[0] = {0};
    function<void(int)> solve = [&](int k) {
        int mx = 0, id;
        for (int i = 1; i <= n; i++) if (!vis[i]) {
            int l = 1, r = mx + 1, p;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (!V[mid].empty() && a[i] > a[V[mid].back()]) l = mid + 1;
                else r = (p = mid) - 1;
            }
            f[i] = p, pre[i] = V[p - 1].back();
            if (p > mx) V[mx = p].clear(), id = i;
            V[p].push_back(i);
        }
        if (!mx) return;
        if (mx >= k) {
            foo.clear();
            while (id) {
                foo.push_back(a[id]);
                vis[id] = 1, id = pre[id];
            }
            reverse(foo.begin(), foo.end());
            for (int i = 1; i <= mx; i++) V[i].clear();
            ans.push_back(foo), solve(k - 1);
        } else {
            for (int i = 1; i <= mx; i++) {
                foo.clear();
                for (int x : V[i]) foo.push_back(a[x]);
                ans.push_back(foo);
            }
            for (int i = 1; i <= mx; i++) V[i].clear();
        }
    };
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]), vis[i] = 0;
        }
        ans.clear();
        int k = 1;
        while (k * (k + 1) / 2 <= n) k++;
        solve(k);
        printf("%d\n", ans.size());
        for (auto &V : ans) {
            printf("%d", V.size());
            for (int x : V) printf(" %d", x);
            putchar('\n');
        }
    }
    return 0;
}