// 21:13
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

const int N = 300010;

int a1[N], a2[N], a[N];
int p1[N], p2[N], p[N];
int n;

void prepare(int va[], int vp[]) {
    LL cur = 0;
    unordered_map<LL, int> m;
    irep(i, n, 1) {
        m[cur] = i;
        cur += va[i];
        if(m.count(cur)) {
            vp[i] = m[cur];
        } else {
            vp[i] = n + 1;
        }
        if(i < n) setmin(vp[i], vp[i + 1]);
    }
}

int f[N], fp1[N], fp2[N];

void update(int i, int j, int val) {
    if(i > n || j > n) return;
    if(i == j) {
        if(setmax(f[i], val)) {
            fp1[i] = fp2[i] = n + 1;
        }
    } else {
        if(i < j) {
            if(setmax(f[i], val - 1)) {
                fp1[i] = fp2[i] = n + 1;
            }
            if(f[i] == val - 1) {
                setmin(fp2[i], j);
            }
        } else {
            if(setmax(f[j], val - 1)) {
                fp1[j] = fp2[j] = n + 1;
            }
            if(f[j] == val - 1) {
                setmin(fp1[j], i);
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", &a1[i]);
    rep(i, 1, n) scanf("%d", &a2[i]);
    rep(i, 1, n) a[i] = a1[i] + a2[i];
    prepare(a1, p1);
    prepare(a2, p2);
    prepare(a, p);

    fillchar(f, -1);
    update(0, 0, 0);
    rep(i, 0, n - 1) {
        update(i + 1, i + 1, f[i]);
        update(p[i + 1], p[i + 1], f[i] + 1);
        update(p1[i + 1], i, f[i] + 1);
        update(i, p2[i + 1], f[i] + 1);

        update(fp1[i], fp1[i], f[i] + 1);
        update(fp1[i], p2[i + 1], f[i] + 2);

        update(fp2[i], fp2[i], f[i] + 1);
        update(p1[i + 1], fp2[i], f[i] + 2);
    }
    printf("%d\n", f[n]);

    return 0;
}