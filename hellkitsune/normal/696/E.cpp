#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const LL INF = 1e18;

int c[100005];

struct Path {
    vector<vector<int> > who;
    vector<pair<LL, int> > st;
    vector<LL> sp;
    int off, sz;

    Path(int sz) {
        this->sz = sz;
        who.resize(sz);
        off = 1;
        while (off < sz) {
            off *= 2;
        }
        st.resize(2 * off);
        sp.resize(off);
    }

    Path() {}

    void stPush(int v) {
        for (int i = 2 * v; i <= 2 * v + 1; ++i) {
            st[i].first += sp[v];
            if (i < off) {
                sp[i] += sp[v];
            }
        }
        sp[v] = 0;
    }

    pair<LL, int> stGet(int v, int L, int R, int l, int r) {
        if (l > r) return mp(INF, -1);
        if (L == l && R == r) {
            return st[v];
        }
        if (sp[v]) {
            stPush(v);
        }
        int mid = (L + R) >> 1;
        return min(stGet(2 * v, L, mid, l, min(r, mid)),
            stGet(2 * v + 1, mid + 1, R, max(l, mid + 1), r));
    }

    int stUpd;
    void stUpdate(int v, int L, int R, int l, int r) {
        if (l > r) return;
        if (L == l && R == r) {
            st[v].first += stUpd;
            if (v < off) {
                sp[v] += stUpd;
            }
            return;
        }
        if (sp[v]) {
            stPush(v);
        }
        int mid = (L + R) >> 1;
        if (l <= mid) stUpdate(2 * v, L, mid, l, min(r, mid));
        if (r > mid) stUpdate(2 * v + 1, mid + 1, R, max(l, mid + 1), r);
        st[v] = min(st[2 * v], st[2 * v + 1]);
    }

    int stNode;
    void stUpdateNode(int v, int L, int R) {
        if (L == R) {
            if ((int)who[L].size() == 1) {
                st[v] = mp(INF, -1);
            } else {
                st[v] = mp(st[v].first - who[L].back() + who[L][(int)who[L].size() - 2], c[who[L][(int)who[L].size() - 2]]);
            }
            who[L].pop_back();
            return;
        }
        if (sp[v]) {
            stPush(v);
        }
        int mid = (L + R) >> 1;
        if (stNode <= mid) stUpdateNode(2 * v, L, mid);
        else stUpdateNode(2 * v + 1, mid + 1, R);
        st[v] = min(st[2 * v], st[2 * v + 1]);
    }

    void stBuild() {
        for (int i = 0; i < sz; ++i) {
            st[off + i] = who[i].empty() ? mp(INF, -1) : mp((LL)who[i].back(), c[who[i].back()]);
        }
        for (int i = sz; i < off; ++i) {
            st[off + i] = mp(INF, -1);
        }
        for (int i = off - 1; i >= 1; --i) {
            st[i] = min(st[2 * i], st[2 * i + 1]);
        }
    }
};

int n, m, q;
vector<int> g[100005];
vector<int> p[100005];
int pnum[100005], pind[100005], sz[100005];
int dep[100005] = {}, uv[100005];
int pc = 1;
Path paths[100005];

int tin[100005], tout[100005], timer = -1;
LL fen[100005] = {};

void fenAdd(int pos, int val) {
    for (; pos < n; pos |= pos + 1) {
        fen[pos] += val;
    }
}

LL fenGet(int pos) {
    LL res = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        res += fen[pos];
    }
    return res;
}

void euler(int v, int p) {
    tin[v] = ++timer;
    for (int to : g[v]) if (to != p) {
        euler(to, v);
    }
    tout[v] = timer;
}

void calcSize(int v, int par) {
    sz[v] = 1;
    for (int to : g[v]) if (to != par) {
        calcSize(to, v);
        sz[v] += sz[to];
    }
}

void dfs(int v, int par, int path) {
    pnum[v] = path;
    pind[v] = (int)p[path].size();
    p[path].pb(v);
    for (int to : g[v]) if (to != par) {
        if (sz[to] * 2 >= sz[v]) {
            dfs(to, v, path);
        } else {
            dep[pc] = dep[path] + 1;
            uv[pc] = v;
            dfs(to, v, pc++);
        }
    }
}

int hldRes;
LL hldValue;
void query(int path, int from, int to) {
    int v = paths[path].stGet(1, 0, paths[path].off - 1, from, to).second;
    if (v != -1) {
        int girl = paths[path].who[pind[v]].back();
        LL curValue = girl + fenGet(tin[v]);
        if (curValue < hldValue || (curValue == hldValue && c[girl] < c[hldRes])) {
            hldValue = curValue;
            hldRes = girl;
        }
    }
}

int hldQuery(int u, int v) {
    hldRes = -1;
    hldValue = INF;
    int pu = pnum[u], pv = pnum[v];
    while (pu != pv) {
        if (dep[pu] > dep[pv]) {
            query(pu, 0, pind[u]);
            u = uv[pu];
            pu = pnum[u];
        } else {
            query(pv, 0, pind[v]);
            v = uv[pv];
            pv = pnum[v];
        }
    }
    int from = pind[u], to = pind[v];
    if (from > to) swap(from, to);
    query(pu, from, to);
    return hldRes;
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &q);
    REP(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    calcSize(0, -1);
    dfs(0, -1, 0);
    euler(0, -1);
    REP(i, pc) {
        paths[i] = Path(p[i].size());
    }
    REP(i, m) scanf("%d", c + i), --c[i];
    for (int i = m - 1; i >= 0; --i) {
        int v = c[i];
        paths[pnum[v]].who[pind[v]].pb(i);
    }
    REP(i, pc) {
        paths[i].stBuild();
    }
    REP(qq, q) {
        int qt;
        scanf("%d", &qt);
        if (qt == 1) {
            int u, v, k;
            scanf("%d%d%d", &u, &v, &k), --u, --v;
            vector<int> ans;
            REP(times, k) {
                int res = hldQuery(u, v);
                if (res == -1) {
                    break;
                }
                ans.pb(res);
                paths[pnum[c[res]]].stNode = pind[c[res]];
                paths[pnum[c[res]]].stUpdateNode(1, 0, paths[pnum[c[res]]].off - 1);
            }
            printf("%d", (int)ans.size());
            for (int x : ans) printf(" %d", x + 1);
            printf("\n");
        } else {
            int v, k;
            scanf("%d%d", &v, &k), --v;
            fenAdd(tin[v], k);
            fenAdd(tout[v] + 1, -k);
            paths[pnum[v]].stUpd = k;
            paths[pnum[v]].stUpdate(1, 0, paths[pnum[v]].off - 1, pind[v], (int)p[pnum[v]].size() - 1);
        }
    }
	return 0;
}