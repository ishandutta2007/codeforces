#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
using namespace std;
using ld = long double;
using ll = int64_t;
using pii = pair<int, int>;
using ull = uint64_t;

struct query {
    int tp, x, y;
} qu[500500];

int dsu[100100];
vector<pii> changes;

inline int get(int v) {
    while (dsu[v] >= 0)
        v = dsu[v];
    return v;
}
inline void unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a != b) {
        if (-dsu[a] < -dsu[b])
            swap(a, b);
        changes.emplace_back(a, dsu[a]);
        changes.emplace_back(b, dsu[b]);
        dsu[a] += dsu[b];
        dsu[b] = a;
    }
}

void go(vector<pair<int, pii>>& queries, int tl, int tr) {
    if (queries.empty())
        return;
    size_t rollback = changes.size();
    vector<pair<int, pii>> ql, qr;
    int tm = (tl + tr) >> 1;
    for (const auto& qqq : queries) {
        int idx = qqq.first;
        int l = qqq.second.first;
        int r = qqq.second.second;
        if (l == tl && r == tr) {
            if (qu[idx].tp == 1)
                unite(qu[idx].x, qu[idx].y);
            else
                qu[idx].y = -dsu[get(qu[idx].x)];
        } else {
            if (l <= tm)
                ql.push_back({idx, {l, min(r, tm)}});
            if (r > tm)
                qr.push_back({idx, {max(l, tm + 1), r}});
        }
    }
    go(ql, tl, tm);
    go(qr, tm + 1, tr);
    while (changes.size() > rollback) {
        int a = changes.back().first;
        int b = changes.back().second;
        changes.pop_back();
        dsu[a] = b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q, k;
    cin >> n >> q >> k;
    vector<int> next_day;
    next_day.push_back(-1);
    for (int i = 0; i < q; ++i) {
        cin >> qu[i].tp;
        if (qu[i].tp == 1) {
            cin >> qu[i].x >> qu[i].y;
            --qu[i].x; --qu[i].y;
        } else if (qu[i].tp == 2) {
            cin >> qu[i].x;
            --qu[i].x;
        } else {
            next_day.push_back(i);
        }
    }
    next_day.push_back(q);
    vector<pair<int, pii>> queries;
    int curday = 0;
    for (int i = 0; i < q; ++i) {
        if (qu[i].tp == 1) {
            int end_time = next_day[min(curday + k, (int)next_day.size() - 1)] - 1;
            queries.push_back({i, {i, end_time}});
        } else if (qu[i].tp == 2) {
            queries.push_back({i, {i, i}});
        } else {
            ++curday;
        }
    }

    fill_n(dsu, n, -1);
    go(queries, 0, q - 1);

    for (int i = 0; i < q; ++i) {
        if (qu[i].tp == 2) {
            cout << qu[i].y << '\n';
        }
    }
}