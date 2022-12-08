#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// {{{
// clang-format off
#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define fillchar(a, x) memset(a, x, sizeof(a))
#define rep(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define irep(i, a, b) for (int i = int(a); i >= int(b); --i)
#define replr(i, a, b) rep(i, a, (b)-1)
#define reprl(i, a, b) irep(i, (b)-1, a)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define popcount __builtin_popcount
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<PII> VPI;
typedef vector<PLL> VPL;
template <class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os << "(" << v.first << ", " << v.second << ")"; }
template <class T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; repn(i, sz(v)) { if(i) os << ", "; os << v[i]; } return os << "]"; }
template <class T> bool setmax(T& _a, T _b) { if(_a < _b) { _a = _b; return true; } return false; }
template <class T> bool setmin(T& _a, T _b) { if(_b < _a) { _a = _b; return true; } return false; }
template <class T> T gcd(T _a, T _b) { return _b == 0 ? _a : gcd(_b, _a % _b); }
// clang-format on
// }}}

VPL cal_lr(VI a) {
    const int n = sz(a);
    const int LIM = 1000000000;
    VPL ans(n);
    {
        unordered_map<int, int> tr;
        repn(i, n) {
            for(int x = a[i]; x >= 1; x -= x & -x) ans[i].fi += tr[x];
            for(int x = a[i]; x <= LIM; x += x & -x) tr[x]++;
        }
    }
    {
        unordered_map<int, int> tr;
        irepn(i, n) {
            for(int x = a[i]; x >= 1; x -= x & -x) ans[i].se += tr[x];
            for(int x = a[i]; x <= LIM; x += x & -x) tr[x]++;
        }
    }
    return ans;
}

const int MOD = LL(1e9) + 7;

struct Value {
    LL cnt = 0, suml = 0, sumr = 0, superl = 0, superr = 0;

    friend Value operator+(const Value& l, const Value& r) {
        Value a;
        a.cnt = l.cnt + r.cnt;
        a.suml = (l.suml + r.suml) % MOD;
        a.sumr = (l.sumr + r.sumr) % MOD;
        a.superl = (l.superl + r.superl + l.suml * r.cnt) % MOD;
        a.superr = (l.superr + r.superr + l.cnt * r.sumr) % MOD;
        return a;
    }
};

struct Tree {
    vector<Value> tr;
    VPL vs;
    int n;

    void update(int x) { tr[x] = tr[x * 2 + 1] + tr[x * 2 + 2]; }

    void set_to_val(int x, int i) {
        tr[x].cnt = 1;
        tr[x].suml = vs[i].fi;
        tr[x].sumr = vs[i].se;
        tr[x].superl = tr[x].superr = 0;
    }
    void set_to_zero(int x) { tr[x] = Value(); }

    void init(int x, int l, int r) {
        if(l + 1 == r) {
            set_to_val(x, l);
            return;
        }
        const int m = (l + r) / 2;
        init(x * 2 + 1, l, m);
        init(x * 2 + 2, m, r);
        update(x);
    }

    Value get(int x, int l, int r, int st, int en) {
        if(st >= en) return Value();
        if(st <= l && r <= en) {
            return tr[x];
        }
        const int m = (l + r) / 2;
        Value res;
        if(st < m) res = res + get(x * 2 + 1, l, m, st, en);
        if(m < en) res = res + get(x * 2 + 2, m, r, st, en);
        return res;
    }

    void enable(int x, int l, int r, int ind, bool flag) {
        if(l + 1 == r) {
            if(flag) {
                set_to_val(x, l);
            } else {
                set_to_zero(x);
            }
            return;
        }
        const int m = (l + r) / 2;
        if(ind < m) {
            enable(x * 2 + 1, l, m, ind, flag);
        } else {
            enable(x * 2 + 2, m, r, ind, flag);
        }
        update(x);
    }
};

LL ans = 0;

Tree build(VPL vs) {
    //cout << "build: " << vs << endl;
    Tree tr;
    tr.vs = vs;
    tr.n = sz(vs);
    tr.tr.resize(tr.n * 4);

    tr.init(0, 0, tr.n);
    //cout << "iinit" << endl;

    repn(i, sz(vs)) {
        Value l = tr.get(0, 0, tr.n, 0, i);
        Value r = tr.get(0, 0, tr.n, i + 1, tr.n);
        (ans += l.suml * r.sumr) %= MOD;
    }
    //cout << "finish" << endl;
    return tr;
}

void enable(Tree* tr, int i, bool flag) {
    Value l = tr->get(0, 0, tr->n, 0, i);
    Value r = tr->get(0, 0, tr->n, i + 1, tr->n);
    tr->enable(0, 0, tr->n, i, flag);
    LL delta = (l.suml * r.sumr) % MOD;
    (delta += tr->vs[i].fi * r.superr) %= MOD;
    (delta += l.superl * tr->vs[i].se) %= MOD;
    if(!flag) delta = -delta;
    (ans += delta) %= MOD;
}

int main() {
    int n;
    scanf("%d", &n);
    VI a(n);
    repn(i, n) scanf("%d", &a[i]);
    VPL b = cal_lr(a);

    map<int, VI> m;
    repn(i, n) m[a[i]].pb(i);
    const int gn = sz(m);
    vector<Tree> trees(gn);
    VI gindex(n), goffset(n);
    int cur = 0;
    for(const auto& kv : m) {
        VPL vs;
        repn(k, sz(kv.se)) {
            const int i = kv.se[k];
            gindex[i] = cur;
            goffset[i] = k;
            vs.pb(b[i]);
        }
        trees[cur] = build(vs);
        ++cur;
    }

    //cout << ans << endl;

    int ops;
    scanf("%d", &ops);
    while(ops--) {
        int t, x;
        scanf("%d%d", &t, &x), --x;
        if(t == 1) {
            enable(&trees[gindex[x]], goffset[x], false);
        } else {
            enable(&trees[gindex[x]], goffset[x], true);
        }
        LL r = (ans % MOD + MOD) % MOD;
        printf("%lld\n", r);
    }

    return 0;
}