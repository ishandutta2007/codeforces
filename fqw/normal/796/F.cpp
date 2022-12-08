// 21:41
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

const int INF = int(1e9);

class Tree1 {
    const int n;
    VI tr;

    void setmin(int x, int l, int r, int st, int en, int val) {
        if(st <= l && r <= en) {
            tr[x] = min(tr[x], val);
            return;
        }
        tr[x * 2 + 1] = min(tr[x * 2 + 1], tr[x]);
        tr[x * 2 + 2] = min(tr[x * 2 + 2], tr[x]);
        const int m = (l + r) / 2;
        if(st < m) setmin(x * 2 + 1, l, m, st, en, val);
        if(m < en) setmin(x * 2 + 2, m, r, st, en, val);
    }

    int get(int x, int l, int r, int ind) {
        if(l + 1 == r) {
            return tr[x];
        }
        tr[x * 2 + 1] = min(tr[x * 2 + 1], tr[x]);
        tr[x * 2 + 2] = min(tr[x * 2 + 2], tr[x]);
        const int m = (l + r) / 2;
        if(ind < m) {
            return get(x * 2 + 1, l, m, ind);
        } else {
            return get(x * 2 + 2, m, r, ind);
        }
    }

public:
    Tree1(int n) : n(n), tr(n * 4, INF + 1) {}
    void setmin(int l, int r, int val) { setmin(0, 0, n, l, r, val); }
    int get(int ind) { return get(0, 0, n, ind); }
};

class Tree2 {
    const int n;
    VI tr;

    void set(int x, int l, int r, int ind, int val) {
        if(l + 1 == r) {
            tr[x] = val;
            return;
        }
        const int m = (l + r) / 2;
        if(ind < m) {
            set(x * 2 + 1, l, m, ind, val);
        } else {
            set(x * 2 + 2, m, r, ind, val);
        }
        tr[x] = max(tr[x * 2 + 1], tr[x * 2 + 2]);
    }

    int getmax(int x, int l, int r, int st, int en) {
        if(st <= l && r <= en) {
            return tr[x];
        }
        const int m = (l + r) / 2;
        int ans = -1;
        if(st < m) setmax(ans, getmax(x * 2 + 1, l, m, st, en));
        if(m < en) setmax(ans, getmax(x * 2 + 2, m, r, st, en));
        return ans;
    }

public:
    Tree2(int n) : n(n), tr(n * 4, -1) {}
    void set(int ind, int val) { return set(0, 0, n, ind, val); }
    int getmax(int l, int r) { return getmax(0, 0, n, l, r); }
};

struct Query {
    int t;
    int l, r, val;
    void read() {
        scanf("%d", &t);
        if(t == 1) {
            scanf("%d%d%d", &l, &r, &val), --l;
        } else {
            scanf("%d%d", &l, &val), --l;
        }
    }
};

VI solve(int n, vector<Query> qs) {
    Tree1 tr1(n);
    Tree2 tr2(n);
    VI needs;
    VI ub(n, -1);
    for(const auto& q : qs) {
        if(q.t == 1) {
            int tmp = tr2.getmax(q.l, q.r);
            if(tmp > q.val) return VI();
            if(tmp < q.val) needs.pb(q.val);
            tr1.setmin(q.l, q.r, q.val);
        } else {
            if(ub[q.l] < 0) ub[q.l] = tr1.get(q.l);
            tr2.set(q.l, q.val);
        }
    }
    repn(i, n) if(ub[i] < 0) ub[i] = tr1.get(i);

    VI ans(n, -1);
    unordered_map<int, int> v2i;
    repn(i, n) v2i[ub[i]] = i;
    for(int need : needs) {
        if(v2i.count(need) == 0) return VI();
        ans[v2i[need]] = need;
    }
    int cur = 0;
    for(int x : ans) {
        if(x >= 0) cur ^= x;
    }
    repn(i, n) if(ans[i] < 0) {
        setmin(ub[i], INF);
        ans[i] = 0;
        for(int b = 1 << 30; b >= 1; b >>= 1) {
            if((cur & b) == 0 && (ans[i] ^ b) <= ub[i]) {
                ans[i] ^= b;
            }
        }
        cur ^= ans[i];
    }
    return ans;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<Query> qs(m);
    for(auto& q : qs) q.read();

    VI ans = solve(n, qs);
    if(ans.empty()) {
        printf("NO\n");
    } else {
        printf("YES\n");
        for(int x : ans) printf("%d ", x);
        printf("\n");
    }
    return 0;
}