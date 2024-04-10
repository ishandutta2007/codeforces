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

const LL MOD = LL(1e9) + 7;

LL inv(LL x) {
    LL y = MOD - 2, r = 1;
    for(; y > 0; y >>= 1, x = x * x % MOD) {
        if(y & 1) r = r * x % MOD;
    }
    return r;
}

class Tree {
    struct Node {
        LL buf = 1, sum = 0;
    };
    const int n;
    vector<Node> tr;

    void push(int x, LL buf) {
        (tr[x].buf *= buf) %= MOD;
        (tr[x].sum *= buf) %= MOD;
    }

    void release(int x) {
        if(tr[x].buf != 1) {
            push(x * 2 + 1, tr[x].buf);
            push(x * 2 + 2, tr[x].buf);
            tr[x].buf = 1;
        }
    }

    void update(int x) {
        tr[x].sum = (tr[x * 2 + 1].sum + tr[x * 2 + 2].sum) % MOD;
    }

    void mul(int x, int l, int r, int st, int en, LL val) {
        if(st <= l && r <= en) {
            push(x, val);
            return;
        }
        const int m = (l + r) / 2;
        release(x);
        if(st < m) mul(x * 2 + 1, l, m, st, en, val);
        if(m < en) mul(x * 2 + 2, m, r, st, en, val);
        update(x);
    }

    void set(int x, int l, int r, int ind, LL val) {
        if(l + 1 == r) {
            tr[x].sum = val;
            return;
        }
        const int m = (l + r) / 2;
        release(x);
        if(ind < m) {
            set(x * 2 + 1, l, m, ind, val);
        } else {
            set(x * 2 + 2, m, r, ind, val);
        }
        update(x);
    }

    LL get(int x, int l, int r, int st, int en) {
        if(st <= l && r <= en) {
            return tr[x].sum;
        }
        const int m = (l + r) / 2;
        LL ans = 0;
        release(x);
        if(st < m) (ans += get(x * 2 + 1, l, m, st, en)) %= MOD;
        if(m < en) (ans += get(x * 2 + 2, m, r, st, en)) %= MOD;
        return ans;
    }

public:
    Tree(int _n) : n(_n), tr(n * 4) {}

    void multiply(int st, int en, LL val) { mul(0, 0, n, st, en, val); }

    void set(int ind, LL val) { set(0, 0, n, ind, val); }

    LL getsum(int st, int en) { return get(0, 0, n, st, en); }

    LL get(int ind) { return getsum(ind, ind + 1); }
};

int main() {
    struct Query {
        int type, x, y, v;
        void read() {
            scanf("%d%d", &type, &x);
            --x;
            if(type == 1) scanf("%d", &v);
        }
    };
    int v0, qn;
    scanf("%d%d", &v0, &qn);
    vector<Query> qs(qn);
    int n = 1;
    repn(i, qn) {
        qs[i].read();
        if(qs[i].type == 1) qs[i].y = n++;
    }
    vector<VI> children(n);
    VI fa(n, -1), st(n), en(n);
    for(const auto& q : qs) {
        if(q.type == 1) children[q.x].pb(q.y);
    }
    int counter = 0;
    const function<void(int)> dfs = [&](int x) {
        st[x] = counter++;
        for(int y : children[x]) {
            fa[y] = x;
            dfs(y);
        }
        en[x] = counter;
    };
    dfs(0);

    VI c(n);
    Tree t(n), tv(n);
    c[0] = 1;
    t.set(st[0], 1);
    tv.set(st[0], v0);
    for(const auto& q : qs) {
        if(q.type == 1) {
            int x = q.x, y = q.y;
            LL tmp = (c[x] + 1) * inv(c[x]) % MOD;
            t.multiply(st[x], en[x], tmp);
            tv.multiply(st[x], en[x], tmp);
            ++c[x];

            c[y] = 1;
            t.set(st[y], t.get(st[x]));
            tv.set(st[y], t.get(st[x]) * q.v % MOD);
        } else {
            int x = q.x;
            LL ans = tv.getsum(st[x], en[x]);
            if(fa[x] >= 0) (ans *= inv(t.get(st[fa[x]]))) %= MOD;
            printf("%lld\n", ans);
        }
    }

    return 0;
}