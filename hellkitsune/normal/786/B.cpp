#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, int> PLI;

struct E {
    int l, r, cost;
    E(int l, int r, int cost) : l(l), r(r), cost(cost) {}
};

int n, m, src;
vector<E> g[100000];
int uto[100000], uw[100000], udone[100000] = {};
int ucnt = 0;
vector<int> upd[1 << 18];
const int off = 1 << 17;

void updAdd(int v, int L, int R, int l, int r, int val) {
    if (L == l && R == r) {
        upd[v].pb(val);
        return;
    }
    int mid = (L + R) >> 1;
    if (l <= mid) {
        updAdd(2 * v, L, mid, l, min(r, mid), val);
    }
    if (r > mid) {
        updAdd(2 * v + 1, mid + 1, R, max(l, mid + 1), r, val);
    }
}

const LL INF = LL(1e18);

PLI st[1 << 18];
LL sp[1 << 18];
int er[1 << 18] = {};
bool bad[1 << 18] = {};

void stBuild() {
    forn(i, 2 * off) {
        sp[i] = INF;
    }
    forn(i, off) st[off + i] = mp(INF, i);
    st[off + src] = mp(0, src);
    for (int i = off - 1; i >= 1; --i) {
        st[i] = min(st[2 * i], st[2 * i + 1]);
    }
}

void stPush(int v) {
    for (int i = 2 * v; i <= 2 * v + 1; ++i) if (!bad[i]) {
        st[i].first = min(st[i].first, sp[v]);
        if (i < off) {
            sp[i] = min(sp[i], sp[v]);
        }
    }
    sp[v] = INF;
}

void stUpd(int v, int L, int R, int l, int r, LL val) {
    if (bad[v]) {
        return;
    }
    if (L == l && R == r) {
        st[v].first = min(st[v].first, val);
        if (L != R) {
            sp[v] = min(sp[v], val);
        }
        return;
    }
    if (sp[v] != INF) {
        stPush(v);
    }
    int mid = (L + R) >> 1;
    if (l <= mid) {
        stUpd(2 * v, L, mid, l, min(r, mid), val);
    }
    if (r > mid) {
        stUpd(2 * v + 1, mid + 1, R, max(l, mid + 1), r, val);
    }
    st[v] = min(st[2 * v], st[2 * v + 1]);
}

void stErase(int v, int L, int R, int pos) {
    if (++er[v] == R - L + 1) {
        bad[v] = true;
        st[v] = mp(INF, 12341234);
        sp[v] = INF;
        return;
    }
    if (sp[v]) {
        stPush(v);
    }
    int mid = (L + R) >> 1;
    if (pos <= mid) {
        stErase(2 * v, L, mid, pos);
    } else {
        stErase(2 * v + 1, mid + 1, R, pos);
    }
    st[v] = min(st[2 * v], st[2 * v + 1]);
}

LL dist[100000];

void updGet(int ind) {
    LL d = dist[ind];
    for (ind += off; ind >= 1; ind >>= 1) {
        for (int x : upd[ind]) {
            if (udone[x]) {
                continue;
            }
            stUpd(1, 0, off - 1, uto[x], uto[x], d + uw[x]);
        }
        upd[ind].clear();
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &src), --src;
    forn(i, m) {
        int qt;
        scanf("%d", &qt);
        if (qt == 1) {
            int from, to, w;
            scanf("%d%d%d", &from, &to, &w), --from, --to;
            g[from].pb(E(to, to, w));
        } else {
            int from, l, r, w;
            scanf("%d%d%d%d", &from, &l, &r, &w), --from, --l, --r;
            if (qt == 2) {
                g[from].pb(E(l, r, w));
            } else {
                uto[ucnt] = from;
                uw[ucnt] = w;
                updAdd(1, 0, off - 1, l, r, ucnt);
                ++ucnt;
            }
        }
    }
    stBuild();
    memset(dist, -1, sizeof dist);
    while (true) {
        PLI best = st[1];
        if (best.first == INF) {
            break;
        }
        stErase(1, 0, off - 1, best.second);
        //cerr << best.first << ' ' << best.second << endl;
        int v = best.second;
        dist[v] = best.first;
        for (E e : g[v]) {
            stUpd(1, 0, off - 1, e.l, e.r, best.first + e.cost);
        }
        updGet(v);
    }
    forn(i, n) {
        if (dist[i] == INF) {
            printf("-1 ");
        } else {
            printf("%I64d ", dist[i]);
        }
    }
    puts("");
    return 0;
}