#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, SZ = 500;
int n, m, a[maxn], b[maxn], cnt[maxn], num[maxn];
long long ans[maxn];
struct query { int l, r, id; } q[maxn];
vector<int> V;
priority_queue<int, vector<int>, greater<int>> Q;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), cnt[a[i]]++;
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &q[i].l, &q[i].r), q[i].id = i;
    }
    sort(q + 1, q + m + 1, [&](query x, query y) { return make_pair(x.l / SZ,
        x.r) < make_pair(y.l / SZ, y.r); });
    for (int i = 1; i <= 100000; i++) {
        if (cnt[i] > SZ) V.push_back(i);
    }
    auto solve = [&]() {
        if (!Q.empty()) Q.pop();
        for (int x : V) {
            if (cnt[x] > SZ) Q.push(cnt[x]);
        }
        copy(num + 1, num + SZ + 1, b + 1);
        fill(b + SZ + 1, b + (SZ << 1 | 1), 0);
        int ans = 0, j = 0;
        for (int i = 1; i <= SZ; i++) if (b[i]) {
            if (j) b[i]--, b[i + j]++, ans += i + j, j = 0;
            if (b[i] & 1) b[i]--, j = i;
            ans += b[i] * i, b[i << 1] += b[i] >> 1;
        }
        for (int i = SZ + 1; i <= SZ << 1; i++) {
            while (b[i]--) Q.push(i);
        }
        if (j) Q.push(j);
        while (Q.size() > 1) {
            int x = Q.top(); Q.pop();
            int y = Q.top(); Q.pop();
            Q.push(x += y), ans += x;
        }
        return ans;  
    };
    memset(cnt, 0, sizeof(cnt));
    auto ins = [&](int x) { num[cnt[x]]--, num[++cnt[x]]++; };
    auto del = [&](int x) { num[cnt[x]]--, num[--cnt[x]]++; };
    int l = 1, r = 0;
    for (int i = 1; i <= m; i++) {
        while (l > q[i].l) ins(a[--l]);
        while (r < q[i].r) ins(a[++r]);
        while (l < q[i].l) del(a[l++]);
        while (r > q[i].r) del(a[r--]);
        ans[q[i].id] = solve();
    }
    for (int i = 1; i <= m; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}