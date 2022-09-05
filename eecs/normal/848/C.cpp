#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, SZ = 200;
int n, m, a[maxn], chk[maxn], lst[maxn], b[maxn];
set<int> S[maxn], T[maxn];
long long ans[maxn], c[maxn], cb[maxn];
vector<pair<int, int>> Q[maxn];
struct query { int op, x, y; } q[maxn];

void add(int p, long long v) {
    p = n - p + 1;
    c[p] += v, cb[p / SZ] += v;
}

long long sum(int p) {
    p = n - p + 1;
    long long s = 0;
    for (int i = 0; (i + 1) * SZ <= p; i++) s += cb[i];
    for (int i = p / SZ * SZ; i <= p; i++) s += c[i];
    return s;
}

int main() {
    scanf("%d %d", &n, &m);
    // mt19937 rnd(time(0)); n = m = 100000;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), T[a[i]].insert(i);
        // a[i] = rnd() % n + 1;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &q[i].op, &q[i].x, &q[i].y);
        // q[i].op = 2, q[i].x = rnd() % n + 1, q[i].y = rnd() % n + 1;
        // if (q[i].x > q[i].y) swap(q[i].x, q[i].y);
    }
    for (int l = 1; l <= m; l += SZ) {
        copy(a + 1, a + n + 1, b + 1);
        int r = min(m, l + SZ - 1);
        for (int i = 1; i <= n; i++) {
            S[i] = T[i], Q[i].clear();
        }
        auto calc1 = [&](int x, int l = 1, int r = n) {
            auto it1 = S[x].lower_bound(l);
            auto it2 = S[x].upper_bound(r);
            if (it1 == S[x].end() || it2 == S[x].begin()) return 0;
            return max(0, *prev(it2) - *it1);
        };
        auto calc2 = [&](int x, int l = 1, int r = n) {
            auto it1 = T[x].lower_bound(l);
            auto it2 = T[x].upper_bound(r);
            if (it1 == T[x].end() || it2 == T[x].begin()) return 0;
            return max(0, *prev(it2) - *it1);
        };
        for (int i = l; i <= r; i++) {
            if (q[i].op == 1) {
                T[a[q[i].x]].erase(q[i].x);
                T[a[q[i].x] = q[i].y].insert(q[i].x);
            } else {
                Q[q[i].y].emplace_back(q[i].x, i);
                for (int j = l; j <= i; j++) chk[q[j].y] = chk[b[q[j].x]] = 0;
                for (int j = l; j <= i; j++) if (q[j].op == 1) {
                    if (!chk[b[q[j].x]]) {
                        chk[b[q[j].x]] = 1;
                        ans[i] -= calc1(b[q[j].x], q[i].x, q[i].y);
                        ans[i] += calc2(b[q[j].x], q[i].x, q[i].y);
                    }
                    if (!chk[q[j].y]) {
                        chk[q[j].y] = 1;
                        ans[i] -= calc1(q[j].y, q[i].x, q[i].y);
                        ans[i] += calc2(q[j].y, q[i].x, q[i].y);
                    }
                }
            }
        }
        fill(c, c + n + 1, 0);
        fill(cb, cb + n + 1, 0);
        fill(lst, lst + n + 1, 0);
        long long cur = 0;
        for (int i = 1; i <= n; i++) {
            if (lst[b[i]]) add(lst[b[i]], i - lst[b[i]]);
            lst[b[i]] = i;
            for (auto p : Q[i]) ans[p.second] += sum(p.first);
        }
    }
    for (int i = 1; i <= m; i++) {
        if (q[i].op == 2) printf("%lld\n", ans[i]);
    }
    return 0;
}