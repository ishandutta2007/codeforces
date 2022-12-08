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

const int L = 18;

struct Node {
    int lcnt = 0;
    Node *l = nullptr, *r = nullptr;
};

int kth(Node* x, int k, int level) {
    if(level < 0) return 0;
    assert(x != nullptr);
    if(k <= x->lcnt) {
        return kth(x->l, k, level - 1);
    } else {
        return kth(x->r, k - x->lcnt, level - 1) + (1 << level);
    }
}

Node* insert(Node* x, int level, int key, int val) {
    if(level < 0) return nullptr;
    {
        Node* tmp = new Node();
        if(x) *tmp = *x;
        x = tmp;
    }
    if(key & (1 << level)) {
        x->r = insert(x->r, level - 1, key, val);
    } else {
        x->lcnt += val;
        x->l = insert(x->l, level - 1, key, val);
    }
    return x;
}

int main() {
    int n;
    scanf("%d", &n);
    VI a(n);
    for(int& x : a) scanf("%d", &x), --x;

    VI first(n, n), next(n);
    irepn(i, n) {
        next[i] = first[a[i]];
        first[a[i]] = i;
    }

    vector<Node*> tr(n + 1);
    tr[0] = nullptr;
    repn(i, n) tr[0] = insert(tr[0], L, first[i], 1);
    repn(i, n) {
        tr[i + 1] = tr[i];
        tr[i + 1] = insert(tr[i + 1], L, i, -1);
        tr[i + 1] = insert(tr[i + 1], L, next[i], 1);
    }

    VI ans(n + 1);
    ans[n] = 1;
    rep(k, 1, n - 1) {
        int cur = 0, cnt = 0;
        while(cur < n) {
            ++cnt;
            cur = kth(tr[cur], k + 1, L);
        }
        ans[k] = cnt;
    }
    rep(k, 1, n) printf("%d ", ans[k]);
    printf("\n");

    return 0;
}