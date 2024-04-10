#ifndef BZ
#pragma GCC optimize -O3
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ld = double;
using ull = uint64_t;

const int N = 500228;
const int INF = 4 * N;
const int NINF = -INF;

int ans[N];

vector<int> touchedIndices;
vector<int> touchedVertices;

void inc(int x) {
    ++ans[x];
    touchedIndices.push_back(x);
}

struct Value {
    int mx = NINF;
    int t = INF;
    int l = 0;
};

class SegTree {
private:
    int k, n;
    vector<Value> a;

public:
    int m;

private:
    void putl() {
        for (int i = 1, sh = k; i <= capacity(); i <<= 1, --sh) {
            for (int j = 0; j < i; ++j) {
                a[i + j].l = j << sh;
            }
        }
    }

    int capacity() {
        return 1 << k;
    }

    void update(int v, int x) {
        a[v].mx = max(a[v].mx, x);
        a[v].t = min(a[v].t, a[v].l - x);
    }

    void push_single(int v) {
        update(v * 2, a[v].mx);
        update(v * 2 + 1,  a[v].mx);
        a[v].mx = NINF;
    }

    void merge(int v) {
        a[v].t = min(a[v * 2].t, a[v * 2 + 1].t);
    }

    void extend() {
        vector<Value> na(1 << (k + 2));
        for (int i = 1; i <= capacity(); i <<= 1) {
            for (int j = i; j < i + i; ++j) {
                na[j + i] = a[j];
            }
        }

        a = move(na);
        ++k;
        putl();
        merge(1);
    }

    void mdf(int v, int l, int r, int lx, int rx, int x) {
        if (l > rx || lx > r) {
            return;
        }

        if (lx <= l && r <= rx) {
            update(v, x);
            return;
        }

        push_single(v);
        int md = (l + r) / 2;
        mdf(v * 2, l, md, lx, rx, x);
        mdf(v * 2 + 1, md + 1, r, lx, rx, x);
        merge(v);
    }

public:
    void clear() {
        a.clear();
    }

    int size() {
        return n;
    }

    void search(int v, int cm) {
        int d = v - capacity();
        if (d >= 0) {
            inc(d);
            a[v].t = INF;
            return;
        }

        touchedVertices.push_back(v);

        push_single(v);

        if (a[v * 2].t < cm) {
            search(v * 2, cm);
        }

        if (a[v * 2 + 1].t < cm) {
            search(v * 2 + 1, cm);
        }

        merge(v);
    }

    void finish(int r) {
        int cm = m + r;

        while (a[1].t < cm) {
            search(1, cm);
        }
    }

    void one() {
        k = 0;
        n = 1;
        m = 0;
        ++ans[0];
        a.resize(2);
        a[1] = {0, 0, 0};
    };

    void up() {
        ++m;
    }

    void modify(int lx, int rx, int x) {
        if (lx >= rx) {
            return;
        }

        n = max(n, rx);
        while (capacity() < n) {
            extend();
        }

        mdf(1, 0, capacity() - 1, lx, rx - 1, x - m);
    }

    Value* data() {
        return a.data() + capacity();
    }

    void pushall() {
        for (int i = 1, j = 2; i < capacity(); ++i, ++j) {
            update(j, a[i].mx);
            update(++j, a[i].mx);
        }
    }

    void push(int r) {
        --r;
        for (int i = 1, j = k; i < capacity(); i <<= 1, --j) {
            int rg = i + (r >> j);
            for (int l = i; l <= rg; ++l) {
                push_single(l);
            }
        }
    }

    void batch_merge(int r) {
        --r;
        for (int i = capacity() >> 1; i > 0; i >>= 1) {
            r /= 2;

            for (int j = i; j <= i + r; ++j) {
                merge(j);
            }
        }
    }

    void mergeup(int v) {
        while (v > 1) {
            v >>= 1;
            merge(v);
        }
    }

    void repush() {
        for (int v: touchedVertices) {
            push_single(v);
        }
    }

    void resetTouched() {
        repush();

        for (int v: touchedIndices) {
            int ind = v + capacity();
            a[ind].mx = -m;
            a[ind].t = v + m;
            mergeup(ind);
        }
    }
};


SegTree f[N];
int best[N];
int secondBest[N];
int depth[N];
int full[N];
int secondFull[N];

vector<int> e[N];

void insertIntoSorted(int& a, int& b, int x) {
    if (x > b) {
        b = x;

        if (x > a) {
            swap(a, b);
        }
    }
}

void dfs(int v, int p) {
    auto e = ::e[v];
    auto it = find(e.begin(), e.end(), p);
    if (it != e.end()) {
        e.erase(it);
    }

    int newSize = 1;
    depth[v] = 0;
    for (int u: e) {
        dfs(u, v);
        newSize += f[u].size();
        depth[v] = max(depth[v], depth[u]);
    }

    ++depth[v];
    touchedIndices.clear();
    touchedVertices.clear();

    if (e.empty()) {
        f[v].one();
        return;
    }

    if (e.size() == 1) {
        f[v] = move(f[e[0]]);
        f[v].modify(f[v].size(), newSize, depth[e[0]]);
        f[v].finish(1);
        f[v].up();
        f[v].resetTouched();
        return;
    }

    std::nth_element(e.begin(), e.begin() + 1, e.end(), [&](int x, int y) {
        return f[x].size() > f[y].size();
    });


    int sz = newSize - f[e[0]].size();

    f[v] = move(f[e[0]]);
    f[v].modify(f[v].size(), newSize, depth[e[0]]);
    f[v].push(sz);
    Value* vd = f[v].data();

    for (int i = 0; i < sz; ++i) {
        best[i] = vd[i].mx + f[v].m;
        vd[i].t = INF;
    }

    f[v].batch_merge(sz);

    fill(secondBest, secondBest + sz, 0);
    fill(full, full + sz, 0);
    fill(secondFull, secondFull + sz, 0);

    int bd = 0;
    for (int i = 1; i < e.size(); ++i) {
        int u = e[i];
        bd = max(bd, depth[u]);
        f[u].pushall();
        Value* ud = f[u].data();
        for (int j = 0; j < min(sz, f[u].size()); ++j) {
            int cur = ud[j].mx + f[u].m;
            insertIntoSorted(best[j], secondBest[j], cur);
        }

        insertIntoSorted(full[f[u].size()], secondFull[f[u].size()], depth[u]);

        f[u].clear();
    }

    f[v].finish(bd + 1);

    f[v].push(sz);
    for (int i = 0; i < sz; ++i) {
        for (int fv: {full[i], secondFull[i]}) {
            insertIntoSorted(best[i], secondBest[i], fv);
            insertIntoSorted(full[i + 1], secondFull[i + 1], fv);
        }

        int cur = best[i] + secondBest[i];

        if (cur >= i) {
            inc(i);
            vd[i].t = INF;
        } else {
            vd[i].mx = -f[v].m + best[i];
            vd[i].t = i - vd[i].mx;
        }
    }

    f[v].batch_merge(sz);
    f[v].modify(sz, f[v].size(), bd);
    f[v].up();
    f[v].resetTouched();
}

int main() {
#ifdef BZ
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    dfs(1, 0);
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << "\n";
    }

    cout << "\n";
}