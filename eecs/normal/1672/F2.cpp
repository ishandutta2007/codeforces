#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, a[maxn], b[maxn], cnt[maxn], ind[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        fill(cnt + 1, cnt + n + 1, 0);
        fill(ind + 1, ind + n + 1, 0);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            cnt[a[i]]++, G[i].clear();
        }
        int mx = max_element(cnt + 1, cnt + n + 1) - cnt;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &b[i]);
            if (a[i] ^ mx) G[a[i]].push_back(b[i]), ind[b[i]]++;
        }
        queue<int> Q;
        for (int i = 1; i <= n; i++) {
            if (!ind[i]) Q.push(i);
        }
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for (int v : G[u]) if (!--ind[v]) Q.push(v);
        }
        bool flag = 1;
        for (int i = 1; i <= n; i++) {
            if (ind[i]) { flag = 0; break; }
        }
        puts(flag ? "AC" : "WA");
    }
    return 0;
}