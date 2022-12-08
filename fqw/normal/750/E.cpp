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

struct Node {
    int f[6][6];

    Node() {
        fillchar(f, 50);
        repn(i, 6) f[i][i] = 0;
    }

    void init(char ch) {
        fillchar(f, 50);
        repn(i, 5) f[i][i] = 0;
        if(ch == '2') {
            f[0][0] = 1, f[0][1] = 0;
        } else if(ch == '0') {
            f[1][1] = 1, f[1][2] = 0;
        } else if(ch == '1') {
            f[2][2] = 1, f[2][3] = 0;
        } else if(ch == '7') {
            f[3][3] = 1, f[3][4] = 0;
        } else if(ch == '6') {
            f[3][3] = f[4][4] = 1, f[3][5] = f[4][5] = 0;
        }
    }

    friend Node merge(const Node& a, const Node& b) {
        Node c;
        fillchar(c.f, 50);
        repn(i, 6) replr(j, i, 6) replr(k, j, 6) {
            setmin(c.f[i][k], a.f[i][j] + b.f[j][k]);
        }
        return c;
    }
} tr[200020 * 4];

void build(int x, int l, int r, const char s[]) {
    if(l + 1 == r) {
        tr[x].init(s[l]);
        return;
    }
    const int m = (l + r) / 2;
    build(x * 2 + 1, l, m, s);
    build(x * 2 + 2, m, r, s);
    tr[x] = merge(tr[x * 2 + 1], tr[x * 2 + 2]);
}

Node query(int x, int l, int r, int st, int en) {
    if(st <= l && r <= en) {
        return tr[x];
    }
    const int m = (l + r) / 2;
    Node ans;
    if(st < m) ans = merge(ans, query(x * 2 + 1, l, m, st, en));
    if(m < en) ans = merge(ans, query(x * 2 + 2, m, r, st, en));
    return ans;
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    static char buf[200020];
    scanf("%s", buf);
    build(0, 0, n, buf);
    while(q--) {
        int st, en;
        scanf("%d%d", &st, &en);
        --st;
        Node cur = query(0, 0, n, st, en);
        int ans = cur.f[0][4];
        if(ans > n) ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}