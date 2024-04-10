// test
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1 << 19;
int n, p[maxn], ans;

struct BIT {
    int tr[maxn];
    BIT() { memset(tr, 0, sizeof tr); }
    void upd(int p) {
        for (; p <= n; p += p & -p)
            ++tr[p];
    }
    int qry(int p) {
        int s = 0;
        for (; p; p -= p & -p)
            s += tr[p];
        return s;
    }
};

struct SEG {
    int y[maxn], suf[maxn], tg[maxn << 1];
    BIT sx, sy;
    pair<int, int> sg1[maxn << 1], sg2[maxn << 1];
    SEG() {
        memset(y, 0x3f, sizeof y);
        memset(tg, 0, sizeof tg);
    }

    void build(int x, int L, int R) {
        if (L == R) {
            sg1[x] = {y[L], L};
            sg2[x] = {y[L] == suf[L] ? y[L] - L : 1e9, L};
            return;
        }
        int md = L + R >> 1;
        build(x << 1, L, md);
        build(x << 1 | 1, md + 1, R);
        sg1[x] = min(sg1[x << 1], sg1[x << 1 | 1]);
        sg2[x] = min(sg2[x << 1], sg2[x << 1 | 1]);
    }
    void build() {
        suf[n + 1] = 1e9;
        for (int i = n; i; --i)
            suf[i] = min(suf[i + 1], y[i]);
        build(1, 1, n);
    }
    void ptag(int x, int v) {
        sg2[x].first += v;
        tg[x] += v;
    }
    void pdown(int x) {
        if (tg[x]) {
            ptag(x << 1, tg[x]);
            ptag(x << 1 | 1, tg[x]);
            tg[x] = 0;
        }
    }
    void upd(int l, int r, int x = 1, int L = 1, int R = n) {
        if (l <= L && R <= r) {
            ptag(x, -1);
            return;
        }
        int md = L + R >> 1;
        pdown(x);
        if (l <= md)
            upd(l, r, x << 1, L, md);
        if (md < r)
            upd(l, r, x << 1 | 1, md + 1, R);
        sg2[x] = min(sg2[x << 1], sg2[x << 1 | 1]);
    }
    void del(int p, int x = 1, int L = 1, int R = n) {
        if (L == R) {
            sg1[x].first = sg2[x].first = 1e9;
            return;
        }
        int md = L + R >> 1;
        pdown(x);
        if (p <= md)
            del(p, x << 1, L, md);
        else
            del(p, x << 1 | 1, md + 1, R);
        sg1[x] = min(sg1[x << 1], sg1[x << 1 | 1]);
        sg2[x] = min(sg2[x << 1], sg2[x << 1 | 1]);
    }
    void add(int p, int x = 1, int L = 1, int R = n) {
        if (L == R) {
            sg2[x].first = y[L] - L + sx.qry(L) - sy.qry(y[L]);
            return;
        }
        int md = L + R >> 1;
        pdown(x);
        if (p <= md)
            add(p, x << 1, L, md);
        else
            add(p, x << 1 | 1, md + 1, R);
        sg2[x] = min(sg2[x << 1], sg2[x << 1 | 1]);
    }
    pair<int, int> qry(int p, int x = 1, int L = 1, int R = n) {
        if (p <= L)
            return sg1[x];
        int md = L + R >> 1;
        if (p <= md)
            return min(qry(p, x << 1, L, md), sg1[x << 1 | 1]);
        return qry(p, x << 1 | 1, md + 1, R);
    }
    int findl(int p, int x = 1, int L = 1, int R = n) {
        if (sg2[x].first > n)
            return -1;
        if (L == R)
            return L;
        int md = L + R >> 1, ans = -1;
        if (p > md)
            ans = findl(p, x << 1 | 1, md + 1, R);
        if (ans == -1)
            ans = findl(p, x << 1, L, md);
        return ans;
    }
    int findr(int p, int x = 1, int L = 1, int R = n) {
        if (sg2[x].first > n)
            return -1;
        if (L == R)
            return L;
        int md = L + R >> 1, ans = -1;
        if (p <= md)
            ans = findr(p, x << 1, L, md);
        if (ans == -1)
            ans = findr(p, x << 1 | 1, md + 1, R);
        return ans;
    }
    int findy(int p, int x = 1, int L = 1, int R = n) {
        if (L == R) return L + (sg1[x].first < p);
        int md = L + R >> 1;
        if (sg1[x << 1 | 1].first > p) return findy(p, x << 1, L, md);
        return findy(p, x << 1 | 1, md + 1, R);
    }
    pair<int, int> work() {
        int x = sg2[1].second;
        sx.upd(x);
        sy.upd(y[x]);
        del(x);
        int l = findl(x) + 1, r = findr(x);
        if (!l) l = 1;
        if (r == -1) r = n + 1;
        while (l < r) {
            pair<int, int> o = qry(l);
            if (o.first > n || o.second >= r) break;
            add(o.second);
            l = o.second + 1;
        }
        return {x, y[x]};
    }
    void work2(int x, int y) {
        sx.upd(x);
        sy.upd(y);
        int l = findy(y);
        if (l <= x) upd(l, x);
    }
} dsl, dsr;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        if (i <= p[i]) dsl.y[i] = p[i];
        else dsr.y[p[i]] = i;
    }
    dsl.build(), dsr.build();
    while (true) {
        int a = dsl.sg2[1].first, b = dsr.sg2[1].first;
        if (a > n && b > n) break;
        if (a < b) {
            ans = max(ans, a);
            pair<int, int> o = dsl.work();
            dsr.work2(o.second, o.first);
        } else {
            ans = max(ans, b);
            pair<int, int> o = dsr.work();
            dsl.work2(o.second, o.first);
        }
    }
    cout << ans << "\n";
    return 0;
}