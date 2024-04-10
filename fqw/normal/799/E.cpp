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
typedef vector<string> VS;
typedef vector<PII> VPI;
typedef vector<PLL> VPL;
template <class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os << "(" << v.first << ", " << v.second << ")"; }
template <class T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; repn(i, sz(v)) { if(i) os << ", "; os << v[i]; } return os << "]"; }
template <class T> bool setmax(T& _a, T _b) { if(_a < _b) { _a = _b; return true; } return false; }
template <class T> bool setmin(T& _a, T _b) { if(_b < _a) { _a = _b; return true; } return false; }
template <class T> T gcd(T _a, T _b) { return _b == 0 ? _a : gcd(_b, _a % _b); }
inline LL powmod(LL a, LL b, LL m) { LL r = 1; for(; b > 0; b >>= 1, a = a * a % m) { if(b & 1) r = r * a % m; } return r; }
// clang-format on
// }}}

class Set {
public:
    Set() { root = nullptr; }
    void insert(LL x) {
        // printf("insert %lld\n",x);
        root = insert(root, x);
    }

    void erase(LL x) {
        // printf("erase %lld\n",x);
        root = erase(root, x);
    }

    int count() { return root ? root->size : 0; }

    LL sum_smallest(int num) { return sum(root, num); }

private:
    struct Node {
        LL val, sum;
        int size, rnd;
        Node *l, *r;
        Node(LL v)
            : val(v), sum(v), size(1), rnd(rand()), l(nullptr), r(nullptr) {}
        void update() {
            size = 1, sum = val;
            if(l) size += l->size, sum += l->sum;
            if(r) size += r->size, sum += r->sum;
        }
    };

    Node* lrotate(Node* x) {
        Node* y = x->l;
        x->l = y->r;
        y->r = x;
        x->update();
        return y;
    }
    Node* rrotate(Node* x) {
        Node* y = x->r;
        x->r = y->l;
        y->l = x;
        x->update();
        return y;
    }

    Node* insert(Node* x, LL v) {
        if(x == nullptr) return new Node(v);
        if(v < x->val) {
            x->l = insert(x->l, v);
            if(x->l->rnd > x->rnd) x = lrotate(x);
        } else {
            x->r = insert(x->r, v);
            if(x->r->rnd > x->rnd) x = rrotate(x);
        }
        x->update();
        return x;
    }

    Node* erase(Node* x, LL v) {
        if(x->val == v) {
            if(x->l == nullptr && x->r == nullptr) {
                delete x;
                return nullptr;
            }
            if(x->l != nullptr && (x->r == nullptr || x->l->rnd > x->r->rnd)) {
                x = lrotate(x);
                x->r = erase(x->r, v);
            } else {
                x = rrotate(x);
                x->l = erase(x->l, v);
            }
        } else {
            if(v < x->val) {
                x->l = erase(x->l, v);
            } else {
                x->r = erase(x->r, v);
            }
        }
        x->update();
        return x;
    }

    LL sum(Node* x, int num) {
        if(num == 0) return 0;
        assert(x && x->size >= num);
        int lsize = 0;
        LL lsum = 0;
        if(x->l) lsize = x->l->size, lsum = x->l->sum;
        if(num <= lsize) {
            return sum(x->l, num);
        } else if(num == lsize + 1) {
            return lsum + x->val;
        } else {
            return lsum + x->val + sum(x->r, num - lsize - 1);
        }
    }

    Node* root;
};

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    VI cost(n), like(n, 0);
    repn(i, n) scanf("%d", &cost[i]);
    rep(b, 1, 2) {
        int tmp;
        scanf("%d", &tmp);
        while(tmp--) {
            int x;
            scanf("%d", &x);
            like[x - 1] |= b;
        }
    }

    VI a, b, c, d;
    repn(i, n) {
        if(like[i] == 3) {
            a.pb(cost[i]);
        } else if(like[i] == 1) {
            b.pb(cost[i]);
        } else if(like[i] == 2) {
            c.pb(cost[i]);
        } else {
            d.pb(cost[i]);
        }
    }
    sort(all(a));
    sort(all(b));
    sort(all(c));
    sort(all(d));

    Set s;
    for(int x : b) s.insert(x);
    for(int x : c) s.insert(x);
    for(int x : d) s.insert(x);
    int bi = 0, ci = 0;
    LL cur = 0, ans = 1ll << 60, inf = ans;
    for(int x : a) cur += x;
    irep(i, sz(a), 0) {
        int need = k - i;
        if(need > sz(b) || need > sz(c)) break;
        while(bi < need) {
            cur += b[bi], s.erase(b[bi]);
            ++bi;
        }
        while(ci < need) {
            cur += c[ci], s.erase(c[ci]);
            ++ci;
        }
        int rest = m - (i + bi + ci);
        if(rest >= 0) {
            setmin(ans, cur + s.sum_smallest(rest));
        }
        if(i > 0) {
            s.insert(a[i - 1]), cur -= a[i - 1];
        }
    }
    if(ans == inf) ans = -1;
    printf("%lld\n", ans);

    return 0;
}