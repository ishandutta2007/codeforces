// 13:20
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
template <class T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; repn(i, sz(v)) { if(i) os << ", "; os << v[i]; } return os << "]"; }
template <class T> bool setmax(T& _a, T _b) { if(_a < _b) { _a = _b; return true; } return false; }
template <class T> bool setmin(T& _a, T _b) { if(_b < _a) { _a = _b; return true; } return false; }
template <class T> T gcd(T _a, T _b) { return _b == 0 ? _a : gcd(_b, _a % _b); }
VI read_vi(int n = -1) { if (n < 0) scanf("%d", &n); VI a(n); repn(i, n) scanf("%d", &a[i]); return a; }
VL read_vl(int n = -1) { if (n < 0) scanf("%d", &n); VL a(n); repn(i, n) scanf("%lld", &a[i]); return a; }
VD read_vd(int n = -1) { if (n < 0) scanf("%d", &n); VD a(n); repn(i, n) scanf("%lf", &a[i]); return a; }
VPI read_vpi(int n = -1) { if (n < 0) scanf("%d", &n); VPI a(n); repn(i, n) scanf("%d%d", &a[i].fi,&a[i].se); return a; }
VPL read_vpl(int n = -1) { if (n < 0) scanf("%d", &n); VPL a(n); repn(i, n) scanf("%lld%lld", &a[i].fi,&a[i].se); return a; }
VPD read_vpd(int n = -1) { if (n < 0) scanf("%d", &n); VPD a(n); repn(i, n) scanf("%lf%lf", &a[i].fi,&a[i].se); return a; }
inline LL powmod(LL a, LL b, LL m) { LL r = 1; for(; b > 0; b >>= 1, a = a * a % m) { if(b & 1) r = r * a % m; } return r; }
// clang-format on
// }}}

struct ACAutomaton {
    struct Node {
        int child[26];
        LL cnt = 0;
        Node() { fillchar(child, -1); }
    };
    vector<Node> tr;

    ACAutomaton(const VS& ss) {
        tr.resize(1);
        for(const auto& s : ss) {
            int x = 0;
            for(char c : s) {
                int ch = int(c - 'a');
                if(tr[x].child[ch] < 0) {
                    tr[x].child[ch] = sz(tr);
                    tr.pb(Node());
                }
                x = tr[x].child[ch];
            }
            ++tr[x].cnt;
        }
        VI suffix(sz(tr), 0);
        queue<int> que;
        repn(ch, 26) {
            if(tr[0].child[ch] >= 0) {
                que.push(tr[0].child[ch]);
            } else {
                tr[0].child[ch] = 0;
            }
        }
        while(!que.empty()) {
            int x = que.front();
            if(x == 0) exit(0);
            que.pop();
            tr[x].cnt += tr[suffix[x]].cnt;
            repn(ch, 26) {
                int y = tr[x].child[ch];
                int z = tr[suffix[x]].child[ch];
                if(y >= 0) {
                    suffix[y] = z;
                    que.push(y);
                } else {
                    tr[x].child[ch] = z;
                }
            }
        }
    }

    LL occurrences_in(const string& s) {
        int x = 0;
        LL ans = 0;
        for(char c : s) {
            int ch = int(c - 'a');
            x = tr[x].child[ch];
            ans += tr[x].cnt;
        }
        return ans;
    }
};

struct Solver {
    void add(const string& s) {
        VS ss = {s};
        while(!a.empty() && a.back().fi.size() == ss.size()) {
            ss.insert(ss.end(), all(a.back().fi));
            a.pop_back();
        }
        a.pb({ss, unique_ptr<ACAutomaton>(new ACAutomaton(ss))});
    }

    LL solve(const string& s) {
        LL ans = 0;
        for(const auto& kv : a) {
            ans += kv.se->occurrences_in(s);
        }
        return ans;
    }

    vector<pair<VS, unique_ptr<ACAutomaton>>> a;
};

int main() {
    Solver a, b;
    int m;
    scanf("%d", &m);
    while(m--) {
        int op;
        static char buf[300030];
        scanf("%d%s", &op, buf);
        string s(buf);
        if(op == 1) {
            a.add(s);
        } else if(op == 2) {
            b.add(s);
        } else {
            LL ans = a.solve(s) - b.solve(s);
            printf("%lld\n", ans);
            fflush(stdout);
        }
    }
    return 0;
}