#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, q;
int a[200000];
vector<int> st[1 << 19];
int sp[1 << 19] = {};
const int off = 1 << 18;

void gauss(vector<int> &x) {
    int pos = 0, sz = (int)x.size();
    REP(i, 31) {
        for (int j = pos; j < sz; ++j) if (x[j] & (1 << i)) {
            swap(x[j], x[pos]);
            for (int k = j + 1; k < sz; ++k) if (x[k] & (1 << i)) {
                x[k] ^= x[pos];
            }
            ++pos;
            break;
        }
    }
    x.erase(x.begin() + pos, x.end());
}

void gauss(vector<int> &x, vector<int> &a, vector<int> &b) {
    x.clear();
    for (int y : a) x.pb(y);
    for (int y : b) x.pb(y);
    gauss(x);
}

void stBuild() {
    REP(i, n) st[off + i].pb(a[i] | (1 << 30));
    for (int i = off - 1; i >= 1; --i) {
        gauss(st[i], st[i << 1], st[(i << 1) | 1]);
    }
}

void rebuild(int vv, int val) {
    vector<int> &v = st[vv];
    vector<int> nv;
    bool ok = false;
    for (int x : v) {
        if (x == (1 << 30)) {
            ok = true;
        }
        if (x & (1 << 30)) {
            x ^= val;
        }
        nv.pb(x);
    }
    v = nv;
    /*if (ok) {
        for (int x : nv) {
            v.pb(x ^ val ^ (1 << 30));
        }
    }*/
    //for (int &x : v) x |= 1 << 30;
    gauss(v);
}

void stPush(int v, bool pp) {
    if (pp) {
        sp[v << 1] ^= sp[v];
        sp[(v << 1) | 1] ^= sp[v];
    }
    rebuild(v << 1, sp[v]);
    rebuild((v << 1) | 1, sp[v]);
    sp[v] = 0;
}

int updVal;
void stUpdate(int v, int L, int R, int l, int r) {
    if (l == L && r == R) {
        if (L != R) sp[v] ^= updVal;
        rebuild(v, updVal);
        return;
    }
    int mid = (L + R) >> 1;
    if (sp[v]) stPush(v, L != mid);
    if (l <= mid) stUpdate(v << 1, L, mid, l, min(r, mid));
    if (r > mid) stUpdate((v << 1) | 1, mid + 1, R, max(l, mid + 1), r);
    gauss(st[v], st[v << 1], st[(v << 1) | 1]);
}

vector<int> res, tmp;

void stGet(int v, int L, int R, int l, int r) {
    if (l == L && r == R) {
        gauss(tmp, res, st[v]);
        res = tmp;
        return;
    }
    int mid = (L + R) >> 1;
    if (sp[v]) stPush(v, L != mid);
    if (l <= mid) stGet(v << 1, L, mid, l, min(r, mid));
    if (r > mid) stGet((v << 1) | 1, mid + 1, R, max(l, mid + 1), r);
}

set<int> se;

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &q);
    REP(i, n) scanf("%d", a + i);
    stBuild();
    REP(i, q) {
        int qt, from, to;
        scanf("%d%d%d", &qt, &from, &to), --from, --to;
        if (qt == 1) {
            scanf("%d", &updVal);
            stUpdate(1, 0, off - 1, from, to);
        } else {
            res.clear(), se.clear();
            stGet(1, 0, off - 1, from, to);
            for (int x : res) se.insert(x & ~(1 << 30));
            se.erase(0);
            printf("%d\n", 1 << (int)se.size());
        }
    }
    return 0;
}