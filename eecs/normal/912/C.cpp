#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define x first
#define y second
using namespace std;

const int maxn = 100010;
int n, m, a, b, c, pre[500010], mx[maxn], inc[maxn];
long long ans;
set<int> S, T;
map<int, int> mp;
set<pair<int, int> > V[maxn];

void add(int l, int r) {
    T.insert(l), T.insert(r + 1);
    S.insert(l), S.insert(r + 1);
}

void upd(int l, int r) {
    pre[mp[l]]++, pre[mp[r + 1]]--;
}

int main() {
    S.insert(0), T.insert(0);
    scanf("%d %d %d %d %d", &n, &m, &a, &b, &c);
    for (int i = 1, st; i <= n; i++) {
        scanf("%d %d %d", &mx[i], &st, &inc[i]);
        V[i].insert({0, st});
    }
    for (int i = 1, x, y, z; i <= m; i++) {
        scanf("%d %d %d", &x, &y, &z);
        V[y].insert({x, z});
    }
    for (int i = 1; i <= n; i++) {
        for (auto it = V[i].begin(); it != V[i].end(); it++) {
            auto p = *it;
            if (p.y <= c) {
                auto it2 = it; it2++;
                if (it2 == V[i].end() && b && (!inc[i] || mx[i] <= c)) {
                    printf("-1\n"), exit(0);
                }
                if (!inc[i]) {
                    if (it2 == V[i].end()) add(p.x, 2e9 + 10);
                    else add(p.x, (*it2).x - 1);
                } else {
                    if (it2 == V[i].end()) add(p.x, (c - p.y) / inc[i] + p.x);
                    else add(p.x, min((*it2).x - 1, (c - p.y) / inc[i] + p.x));
                }
            }
        }
    }
    int cnt = 0;
    for (int x : T) {
        mp[x] = ++cnt;
    }
    for (int i = 1; i <= n; i++) {
        for (auto it = V[i].begin(); it != V[i].end(); it++) {
            auto p = *it;
            if (p.y <= c) {
                auto it2 = it; it2++;
                if (!inc[i]) {
                    if (it2 == V[i].end()) upd(p.x, 2e9 + 10);
                    else upd(p.x, (*it2).x - 1);
                } else {
                    if (it2 == V[i].end()) upd(p.x, (c - p.y) / inc[i] + p.x);
                    else upd(p.x, min((*it2).x - 1, (c - p.y) / inc[i] + p.x));
                }
            }
        }
    }
    for (int i = 1; i <= cnt; i++) {
        pre[i] += pre[i - 1];
    }
    for (auto it = ++S.begin(); it != S.end(); it++) {
        int t = (*it) - 1;
        auto it2 = it; it2--;
        ans = max(ans, 1LL * pre[mp[*it2]] * (a + 1LL * t * b));
    }
    printf("%lld\n", ans);
    return 0;
}