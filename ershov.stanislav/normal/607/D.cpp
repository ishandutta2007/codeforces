#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int maxn = 3e5 + 100;
const int MOD = (int) 1e9 + 7;

int add(int a, int b) {
    int ans = (a + b);
    if (ans >= MOD) {
        ans -= MOD;
    }
    return ans;
}

int mult(int a, int b) {
    return (ll) a * b % MOD;
}

int power(int a, int p) {
    int ans = 1;
    while (p) {
        if (p & 1) {
            ans = mult(ans, a);
        }
        a = mult(a, a);
        p >>= 1;
    }
    return ans;
}

int inv(int a) {
    return power(a, MOD - 2);
}

int treen;
int segmtree[maxn * 4], tomult[maxn * 4];
int treesum[maxn * 4];
int pushmult[maxn * 4];

void push(int v) {
    if (pushmult[v] == 1) {
        return;
    }
    treesum[v * 2] = mult(treesum[v * 2], pushmult[v]);
    treesum[v * 2 + 1] = mult(treesum[v * 2 + 1], pushmult[v]);
    pushmult[v * 2] = mult(pushmult[v * 2], pushmult[v]);
    pushmult[v * 2 + 1] = mult(pushmult[v * 2 + 1], pushmult[v]);
    pushmult[v] = 1;
}

void setsum(int v, int vl, int vr, int i, int val) {
    if (vr == vl + 1) {
        treesum[v] = val;
    } else {
        push(v);
        int mid = (vl + vr) / 2;
        if (i < mid) {
            setsum(v * 2, vl, mid, i, val);
        } else {
            setsum(v * 2 + 1, mid, vr, i, val);
        }
        treesum[v] = add(treesum[v * 2], treesum[v * 2 + 1]);
    }
}

int getsum(int v, int vl, int vr, int l, int r) {
    if (vr <= l || r <= vl) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        return treesum[v];
    } else {
        push(v);
        int mid = (vl + vr) / 2;
        return add(getsum(v * 2, vl, mid, l, r), getsum(v * 2 + 1, mid, vr, l, r));
    }
}

void setsum(int i, int val) {
    setsum(1, 0, treen, i, val);
}

int getsum(int l, int r) {
    return getsum(1, 0, treen, l, r);
}

void multtree(int v, int vl, int vr, int l, int r, int m) {
    if (r <= vl || vr <= l) {
        return;
    }
    if (l <= vl && vr <= r) {
        tomult[v] = mult(tomult[v], m);
        pushmult[v] = mult(m, pushmult[v]);
        treesum[v] = mult(treesum[v], m);
    } else {
        push(v);
        int mid = (vl + vr) / 2;
        multtree(v * 2, vl, mid, l, r, m);
        multtree(v * 2 + 1, mid, vr, l, r, m);
        segmtree[v] = add(mult(segmtree[v * 2], tomult[v * 2]), mult(segmtree[v * 2 + 1], tomult[v * 2 + 1]));
        treesum[v] = add(treesum[v * 2], treesum[v * 2 + 1]);
    }
}

int get(int v, int vl, int vr, int i, int m) {
    if (vr == vl + 1) {
        return mult(segmtree[v], mult(tomult[v], m));
    } else {
        int mid = (vl + vr) / 2;
        if (i < mid) {
            return get(v * 2, vl, mid, i, mult(m, tomult[v]));
        } else {
            return get(v * 2 + 1, mid, vr, i, mult(m, tomult[v]));
        }
    }
}

void settree(int v, int vl, int vr, int i, int m, int val) {
    if (vr == vl + 1) {
        segmtree[v] = mult(inv(mult(m, tomult[v])), val);
    } else {
        int mid = (vl + vr) / 2;
        if (i < mid) {
            return settree(v * 2, vl, mid, i, mult(m, tomult[v]), val);
        } else {
            return settree(v * 2 + 1, mid, vr, i, mult(m, tomult[v]), val);
        }
    }
}

void multtree(int l, int r, int m) {
    multtree(1, 0, treen, l, r, m);
}

int get(int i) {
    return get(1, 0, treen, i, 1);
}

void settree(int i, int val) {
    return settree(1, 0, treen, i, 1, val);
}

int curcnt = 1, q;
int v[maxn];
int curdeg[maxn];
int tin[maxn], tout[maxn], curt = 0;
pair<int, pair<int, int>> qs[maxn];
vector<int> tree[maxn];

void dfs(int v, int par) {
    tin[v] = curt++;
    for (int i = 0; i < sz(tree[v]); i++) {
        if (tree[v][i] == par) {
            continue;
        }
        dfs(tree[v][i], v);
    }
    tout[v] = curt;
}

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    for (int i = 0; i < maxn * 4; i++) {
        tomult[i] = 1;
        segmtree[i] = 1;
        pushmult[i] = 1;
    }
    for (int i = 0; i < maxn; i++) {
        curdeg[i] = 1;
    }
    scanf("%d%d", &v[0], &q);
    for (int i = 0; i < q; i++) {
        scanf("%d%d", &qs[i].fs, &qs[i].sc.fs);
        qs[i].sc.fs--;
        if (qs[i].fs == 1) {
            scanf("%d", &qs[i].sc.sc);
            tree[qs[i].sc.fs].pb(curcnt);
            v[curcnt] = qs[i].sc.sc;
            curcnt++;
        }
    }
    dfs(0, -1);
    treen = curcnt;
    curcnt = 1;
    setsum(0, v[0]);
    /*for (int i = 0; i < treen; i++) {
        cout << tin[i] << ' ' << tout[i] << endl;
    }*/
    for (int i = 0; i < q; i++) {
        if (qs[i].fs == 2) {
            int curv = qs[i].sc.fs;
            int ans = getsum(tin[curv], tout[curv]);
            ans = mult(ans, inv(get(tin[curv])));
            ans = mult(ans, curdeg[curv]);
            printf("%d\n", ans);
        } else {
            int curv = curcnt++;
            int p = qs[i].sc.fs;
            multtree(tin[p], tout[p], mult(curdeg[p] + 1, inv(curdeg[p])));
            curdeg[p]++;
            setsum(tin[curv], mult(v[curv], get(tin[curv])));
            /*for (int i = 0; i < treen; i++) {
                cout << get(i) << ' ';
            }
            cout << endl;
            for (int i = 0; i < treen; i++) {
                cout << getsum(i, i + 1) << ' ';
            }
            cout << endl;
            cout << endl;*/
        }
    }
    return 0;
}