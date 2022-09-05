#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int k, n, m, mx[maxn], id[maxn];
long long a[maxn];
vector<int> ans;
vector<pair<int, int>> mul, V[maxn];
struct node { int t, i, b; } c[maxn];

struct state {
    int i, p;
    bool operator < (const state &o) const {
        auto p1 = V[i][p], p2 = V[o.i][o.p];
        // p1.first / a[i] > p2.first / a[o.i]
        return (__int128)p1.first * a[o.i] < (__int128)p2.first * a[i];
    }
};
priority_queue<state> Q;

int main() {
    scanf("%d %d %d", &k, &n, &m);
    for (int i = 1; i <= k; i++) {
        scanf("%lld", &a[i]);
    }
    for (int $ = 1; $ <= n; $++) {
        int t, i, b;
        scanf("%d %d %d", &t, &i, &b);
        c[$] = (node){t, i, b};
        if (t == 1) {
            if (b > mx[i]) mx[i] = b, id[i] = $;
            c[$].b = b - a[i];
        } else if (t == 2) {
            V[i].emplace_back(b, $);
        } else {
            if (b > 1) mul.emplace_back(b, $);
        }
    }
    sort(mul.begin(), mul.end(), greater<pair<int, int>>());
    for (int i = 1; i <= k; i++) {
        if (mx[i] > a[i]) V[i].emplace_back(mx[i] - a[i], id[i]);
        sort(V[i].begin(), V[i].end(), greater<pair<int, int>>());
        if (!V[i].empty()) Q.push((state){i, 0});
    }
    while (!Q.empty()) {
        int i = Q.top().i, p = Q.top().p; Q.pop();
        a[i] += V[i][p].first, ans.push_back(V[i][p++].second);
        if (p < V[i].size()) Q.push((state){i, p});
    }
    while (ans.size() > m) {
        a[c[ans.back()].i] -= c[ans.back()].b, ans.pop_back();
    }
    int ed = (int)ans.size() - 1, cur = 0;
    while (ans.size() < m && cur < mul.size()) {
        ans.push_back(mul[cur++].second);
    }
    while (~ed && cur < mul.size() && mul[cur].first > 1) {
        int i = c[ans[ed]].i, x = c[ans[ed]].b;
        if (a[i] - x < x && (a[i] - x) * (mul[cur].first - 1) < x) break;
        a[i] -= x, ans[ed--] = 0;
        ans.push_back(mul[cur++].second);
    }
    vector<int> _ans;
    for (int x : ans) if (x) _ans.push_back(x);
    sort(_ans.begin(), _ans.end(), [&](int x, int y) { return c[x].t < c[y].t; });
    assert(_ans.size() <= m);
    printf("%d\n", _ans.size());
    for (int x : _ans) printf("%d ", x);
    return 0;
}