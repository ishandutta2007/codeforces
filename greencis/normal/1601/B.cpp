#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

constexpr int inf = 0x3F3F3F3F;

int a[300300];
int b[300300];
int dist[300300];
int pred[300300];
int where_jumped[300300];

int t[1 << 20];

void build(int v, int tl, int tr) {
    if (tl == tr)
        t[v] = tl;
    else {
        int tm = (tl + tr) >> 1;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        t[v] = tl;
    }
}

int get_first(int v, int tl, int tr, int l, int r) {
    if (l > r) return inf;
    if (tl == l && tr == r) return t[v];
    int tm = (tl + tr) >> 1;
    return min(get_first(2 * v, tl, tm, l, min(r, tm)), get_first(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

void update(int v, int tl, int tr, int idx) {
    if (tl == tr)
        t[v] = inf;
    else {
        int tm = (tl + tr) >> 1;
        if (idx <= tm)
            update(2 * v, tl, tm, idx);
        else
            update(2 * v + 1, tm + 1, tr, idx);
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }

    fill_n(dist, n + 1, inf);
    build(1, 0, n);

    queue<tuple<int, int, int, int>> q;
    q.emplace(0, n, -1, -1);
    while (!q.empty()) {
        auto [curd, curv, pr, where] = q.front();
        q.pop();
        if (dist[curv] <= curd) continue;
        dist[curv] = curd++;
        pred[curv] = pr;
        where_jumped[curv] = where;
        int nxt;
        while ((nxt = get_first(1, 0, n, curv - a[curv], curv)) != inf) {
            update(1, 0, n, nxt);
            int to = nxt + b[nxt];
            q.emplace(curd, to, curv, nxt);
        }
    }

    if (dist[0] == inf) {
        cout << "-1\n";
    } else {
        int cur = 0;
        vector<int> ans;
        while (cur != n) {
            ans.push_back(where_jumped[cur]);
            cur = pred[cur];
        }
        reverse(all(ans));
        cout << ans.size() << '\n';
        for (int x: ans) cout << x << ' ';
    }
}