#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
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
#ifndef H_ALGO_HEADER
#define H_ALGO_HEADER

#define all(a) (a).begin(), (a).end()
template <class T> int len(const T& a) { return static_cast<int>(a.size()); }
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
typedef vector<bool> VB;
typedef vector<string> VS;
typedef vector<PII> VPI;
typedef vector<PLL> VPL;
typedef vector<PDD> VPD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef vector<VB> VVB;
typedef vector<VS> VVS;
typedef vector<VPI> VVPI;
typedef vector<VPL> VVPL;

template <class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os << "(" << v.first << ", " << v.second << ")"; }
template <class T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; repn(i, len(v)) { if(i) os << ", "; os << v[i]; } return os << "]"; }
int read_int() { int x; scanf("%d", &x); return x; }
LL read_ll() { LL x; scanf("%lld", &x); return x; }
string read_string() { string s; cin >> s; return s; }
VI read_vi(int n = -1) { if (n < 0) scanf("%d", &n); VI a(n); repn(i, n) scanf("%d", &a[i]); return a; }
VL read_vl(int n = -1) { if (n < 0) scanf("%d", &n); VL a(n); repn(i, n) scanf("%lld", &a[i]); return a; }
VD read_vd(int n = -1) { if (n < 0) scanf("%d", &n); VD a(n); repn(i, n) scanf("%lf", &a[i]); return a; }
VPI read_vpi(int n = -1) { if (n < 0) scanf("%d", &n); VPI a(n); repn(i, n) scanf("%d%d", &a[i].fi,&a[i].se); return a; }
VPL read_vpl(int n = -1) { if (n < 0) scanf("%d", &n); VPL a(n); repn(i, n) scanf("%lld%lld", &a[i].fi,&a[i].se); return a; }
VPD read_vpd(int n = -1) { if (n < 0) scanf("%d", &n); VPD a(n); repn(i, n) scanf("%lf%lf", &a[i].fi,&a[i].se); return a; }
#define IN read_int()

template <class T> T sorted(T x) { sort(x.begin(), x.end()); return x; }
template <class T> T reversed(T x) { reverse(x.begin(), x.end()); return x; }

template <class T> bool setmax(T& _a, T _b) { if(_a < _b) { _a = _b; return true; } return false; }
template <class T> bool setmin(T& _a, T _b) { if(_b < _a) { _a = _b; return true; } return false; }
template <class T> T gcd(T _a, T _b) { return _b == 0 ? _a : gcd(_b, _a % _b); }
inline LL powmod(LL a, LL b, LL m) { LL r = 1; for(; b > 0; b >>= 1, a = a * a % m) { if(b & 1) r = r * a % m; } return r; }

#endif
// clang-format on
// }}}

template <class T> class SAM {
  public:
    static constexpr int MAX_C = 26;
    struct State {
        const int len;
        const bool is_end;
        State *succ[MAX_C] = {nullptr}, *f = nullptr;
        vector<State*> children;
        T info;

        State(int len, bool is_end, State* copy = nullptr)
            : len(len), is_end(is_end) {
            if (copy) {
                memcpy(succ, copy->succ, sizeof(succ));
                f = copy->f;
            } else {
                assert(succ[20] == nullptr);
            }
        }
    };

    SAM() {
        last_ = root_ = new State(0, false);
        states_.pb(root_);
    }

    State* extend(int ch) {
        assert(ch >= 0 && ch < MAX_C);
        State *p = last_, *np = new State(p->len + 1, true);
        states_.pb(np);
        for (; p && !p->succ[ch]; p = p->f) {
            p->succ[ch] = np;
        }
        if (!p) {
            np->f = root_;
        } else {
            State* q = p->succ[ch];
            if (q->len == p->len + 1) {
                np->f = q;
            } else {
                State* nq = new State(p->len + 1, false, q);
                states_.pb(nq);
                np->f = q->f = nq;
                for (; p && p->succ[ch] == q; p = p->f) {
                    p->succ[ch] = nq;
                }
            }
        }
        return last_ = np;
    }

    void finish() {
        sort(all(states_),
             [](const State* p, const State* q) { return p->len < q->len; });
        states_rev_ = states_;
        reverse(all(states_rev_));
        for (State* p : states_rev_) {
            if (p->f) p->f->children.pb(p);
        }
    }

    State* root() const { return root_; }
    const vector<State*> states_top_down() const { return states_; }
    const vector<State*> states_bottom_up() const { return states_rev_; }

  private:
    State *last_, *root_;
    vector<State*> states_, states_rev_;
};

struct Info {
    int ind;
    vector<pair<int, int*>> queries;
};

VI seq;

void dfs(SAM<Info>::State* p) {
    int cur = len(seq);
    if (p->is_end) {
        seq.pb(p->info.ind);
    }
    for (auto* q : p->children) {
        dfs(q);
    }
    if (len(p->info.queries) > 0) {
        VI is(seq.begin() + cur, seq.end());
        sort(all(is));
        for (const auto& q : p->info.queries) {
            if (q.fi > len(is)) {
                (*q.se) = -1;
            } else {
                int r = 1 << 30;
                repn(i, len(is) - q.fi + 1) setmin(r, is[i + q.fi - 1] - is[i]);
                (*q.se) += r;
            }
        }
    }
}

int main() {
    string s = read_string();
    SAM<Info> sam;
    repn(i, len(s)) {
        auto* x = sam.extend(s[i] - 'a');
        x->info.ind = i;
    }
    sam.finish();

    VI ans(IN, -1);
    repn(i, len(ans)) {
        int k = IN;
        string m = read_string();
        auto* p = sam.root();
        for (char c : m) {
            p = p->succ[c - 'a'];
            if (!p) break;
        }
        if (p) {
            ans[i] = len(m);
            p->info.queries.pb(mp(k, &ans[i]));
        }
    }
    dfs(sam.root());
    for (int x : ans) printf("%d\n", x);

    return 0;
}