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

struct Node {
    int child[26];
    Node() { fillchar(child, -1); }
};

int main() {
    int n;
    scanf("%d", &n);
    vector<Node> tr(n * 2);
    repn(i, n - 1) {
        int x, y;
        char s[9];
        scanf("%d%d%s", &x, &y, s);
        --x, --y;
        tr[x].child[int(s[0] - 'a')] = y;
    }
    vector<int> reduction(n);
    const function<int(int, int)> dfs = [&](int x, int dep) {
        int cur = n;
        const function<int(int, int)> merge = [&cur, &merge, &tr](int x,
                                                                  int y) {
            if(x < 0) return y;
            if(y < 0) return x;
            int z = cur++;
            tr[z] = Node();
            repn(ch, 26) {
                tr[z].child[ch] = merge(tr[x].child[ch], tr[y].child[ch]);
            }
            return z;
        };
        int size = 1;
        repn(ch, 26) if(tr[x].child[ch] >= 0) {
            int y = tr[x].child[ch];
            size += dfs(y, dep + 1);
        }
        if(size > 1) {
            int z = -1;
            repn(ch, 26) if(tr[x].child[ch] >= 0) {
                int y = tr[x].child[ch];
                z = merge(z, y);
            }
            reduction[dep] += cur - n + 1;
        }
        return size;
    };
    dfs(0, 0);

    int k = 0;
    repn(i, n) if(reduction[i] > reduction[k]) k = i;
    printf("%d\n%d\n", n - reduction[k], k + 1);

    return 0;
}