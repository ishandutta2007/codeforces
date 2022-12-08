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

int main() {
    int n, m;
    cin >> n >> m;

    struct Var {
        int type;
        VI x;
        int y1, y2;
        char yop;
    };
    map<string, int> n2v;
    vector<Var> vs(n);
    n2v["?"] = -1;
    repn(i, n) {
        string name, eq, op1, op2, t;
        cin >> name >> eq >> op1;
        n2v[name] = i;
        if(n2v.count(op1)) {
            cin >> t >> op2;
            vs[i].type = 2;
            vs[i].y1 = n2v[op1], vs[i].y2 = n2v[op2];
            vs[i].yop = t[0];
        } else {
            vs[i].type = 1;
            for(char c : op1) vs[i].x.pb(int(c - '0'));
        }
    }
    VI ans1, ans2;
    repn(cur, m) {
        int r[2] = {0, 0};
        VI val(n);
        repn(petr, 2) {
            repn(i, n) {
                if(vs[i].type == 1) {
                    val[i] = vs[i].x[cur];
                } else {
                    int v1 = (vs[i].y1 >= 0 ? val[vs[i].y1] : petr);
                    int v2 = (vs[i].y2 >= 0 ? val[vs[i].y2] : petr);
                    if(vs[i].yop == 'A') {
                        val[i] = v1 & v2;
                    } else if(vs[i].yop == 'O') {
                        val[i] = v1 | v2;
                    } else {
                        val[i] = v1 ^ v2;
                    }
                }
                r[petr] += val[i];
            }
            //cout << cur << " " << petr << " " << val << endl;
        }
        if(r[0] == r[1]) {
            ans1.pb(0), ans2.pb(0);
        } else if(r[0] < r[1]) {
            ans1.pb(0), ans2.pb(1);
        } else {
            ans1.pb(1), ans2.pb(0);
        }
    }
    repn(i, m) cout << ans1[i];
    cout << endl;
    repn(i, m) cout << ans2[i];
    cout << endl;

    return 0;
}