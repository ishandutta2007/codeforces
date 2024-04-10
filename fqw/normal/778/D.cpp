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

struct Config {
    void read(int _n, int _m) {
        n = _n, m = _m;
        a.resize(n);
        repn(i, n) cin >> a[i];
        if((swapped = (m % 2 != 0))) {
            VS b = a;
            swap(n, m);
            a.clear();
            a.resize(n, string(m, '*'));
            repn(i, n) repn(j, m) {
                char ch = b[j][i];
                if(ch == 'L')
                    ch = 'U';
                else if(ch == 'R')
                    ch = 'D';
                else if(ch == 'U')
                    ch = 'L';
                else
                    ch = 'R';
                a[i][j] = ch;
            }
        }
    }

    void rotate(int i, int j) {
        // cout<<"rotate "<<i<<" "<<j<<endl;
        // repn(k, n) cout<<"  "<<a[i]<<endl;

        ans.pb(mp(i, j));
        //assert(a[i][j] == 'L' || a[i][j] == 'U');
        if(a[i][j] == 'L') {
            a[i][j] = a[i][j + 1] = 'U', a[i + 1][j] = a[i + 1][j + 1] = 'D';
        } else {
            a[i][j] = a[i + 1][j] = 'L', a[i][j + 1] = a[i + 1][j + 1] = 'R';
        }
    }

    void make_horizontal(int i, int j) {
        // cout<<"horizon "<<i<<" "<<j<<endl;
        if(a[i][j] == 'L') return;
        //assert(a[i][j] == 'U' && i + 1 < n && j + 1 < m);
        make_vertical(i, j + 1);
        rotate(i, j);
    }

    void make_vertical(int i, int j) {
        // cout<<"vertical "<<i<<" "<<j<<endl;
        if(a[i][j] == 'U') return;
        //assert(a[i][j] == 'L' && i + 1 < n && j + 1 < m);
        make_horizontal(i + 1, j);
        rotate(i, j);
    }

    VPI make() {
        ans.clear();
        repn(i, n) {
            for(int j = 0; j < m; j += 2) {
                make_horizontal(i, j);
            }
        }
        if(swapped) {
            for(auto& p : ans) swap(p.fi, p.se);
        }
        return ans;
    }

    VS a;
    int n, m;
    bool swapped;
    VPI ans;
};

int main() {
    Config a, b;
    int n, m;
    cin >> n >> m;
    a.read(n, m);
    b.read(n, m);

    VPI x = a.make();
    VPI y = b.make();
    reverse(all(y)), x.insert(x.end(), all(y));
    cout << sz(x) << endl;
    if(sz(x) > 100000) {
        for(;;)
            ;
    }
    for(const auto& p : x) cout << p.fi + 1 << " " << p.se + 1 << endl;

    return 0;
}