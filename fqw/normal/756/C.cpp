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

const int N = 100000;

struct Node {
    int x, y;
} tr[N * 4];
int val[N];
int n;

void go(int x, int l, int r, int ind, int v) {
    if(l + 1 == r) {
        if(v < 0) {
            tr[x].x = 1;
        } else {
            tr[x].y = 1;
        }
        return;
    }
    const int m = (l + r) / 2;
    if(ind < m) {
        go(x * 2 + 1, l, m, ind, v);
    } else {
        go(x * 2 + 2, m, r, ind, v);
    }
    int d = min(tr[x * 2 + 1].y, tr[x * 2 + 2].x);
    tr[x].x = tr[x * 2 + 1].x + tr[x * 2 + 2].x - d;
    tr[x].y = tr[x * 2 + 1].y + tr[x * 2 + 2].y - d;
}

int get(int x, int l, int r, int rank) {
    if(l + 1 == r) {
        assert(tr[x].x == 0 && tr[x].y == 1);
        return l;
    }
    const int m = (l + r) / 2;
    int ly = tr[x * 2 + 1].y;
    int rx = tr[x * 2 + 2].x, ry = tr[x * 2 + 2].y;
    int d = min(ly, rx);
    if(rank < ry) {
        return get(x * 2 + 2, m, r, rank);
    } else {
        return get(x * 2 + 1, l, m, rank - ry + d);
    }
}

int main() {
    scanf("%d", &n);
    fillchar(tr, 0);
    repn(i, n) {
        int ind, t;
        scanf("%d%d", &ind, &t);
        --ind;
        if(t == 0) {
            go(0, 0, n, ind, -1);
        } else {
            go(0, 0, n, ind, 1);
            scanf("%d", &val[ind]);
        }
        if(tr[0].y == 0) {
            printf("-1\n");
        } else {
            int ans = get(0, 0, n, 0);
            printf("%d\n", val[ans]);
        }
    }
    return 0;
}