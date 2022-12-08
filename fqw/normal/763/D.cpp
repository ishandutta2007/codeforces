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

class Hash {
public:
    static void init(int n) {
        const auto pow = [](LL a, LL b, LL mod) {
            LL r = 1;
            for(; b > 0; b >>= 1, a = a * a % mod) {
                if(b & 1) r = r * a % mod;
            }
            return r;
        };
        p1.resize(n + 1), ip1.resize(n + 1);
        p2.resize(n + 1), ip2.resize(n + 1);
        p1[0] = p2[0] = 1;
        rep(i, 1, n) {
            p1[i] = p1[i - 1] * P1 % M1;
            p2[i] = p2[i - 1] * P2 % M2;
        }
        ip1[n] = pow(p1[n], M1 - 2, M1);
        ip2[n] = pow(p2[n], M2 - 2, M2);
        irep(i, n, 1) {
            ip1[i - 1] = ip1[i] * P1 % M1;
            ip2[i - 1] = ip2[i] * P2 % M2;
        }
    }

    Hash() : Hash(0, 0, 0) {}
    explicit Hash(int ch) : Hash(ch + 1, ch + 1, 1) {}

    bool operator==(const Hash& b) const { return h1 == b.h1 && h2 == b.h2; }
    bool operator<(const Hash& b) const {
        return h1 < b.h1 || (h1 == b.h1 && h2 < b.h2);
    }
    Hash operator+(const Hash& b) const {
        return Hash(h1 * p1[b.size] + b.h1, h2 * p2[b.size] + b.h2,
                    size + b.size);
    }
    Hash remove_l(const Hash& b) const {
        return Hash(h1 - b.h1 * p1[size - b.size],
                    h2 - b.h2 * p2[size - b.size], size - b.size);
    }
    Hash remove_r(const Hash& b) const {
        return Hash((h1 - b.h1) * ip1[b.size], (h2 - b.h2) * ip2[b.size],
                    size - b.size);
    }

private:
    friend struct hash<Hash>;
    static constexpr LL P1 = 911, M1 = LL(1e9) + 7;
    static constexpr LL P2 = 127, M2 = LL(1e9) + 9;

    Hash(LL h1, LL h2, int size)
        : h1((h1 % M1 + M1) % M1), h2((h2 % M2 + M2) % M2), size(size) {}

    static VL p1, p2, ip1, ip2;
    LL h1, h2;
    int size;
};
VL Hash::p1, Hash::p2, Hash::ip1, Hash::ip2;
namespace std {
template <> struct hash<Hash> {
    size_t operator()(const Hash& h) const { return h.h1 ^ h.h2; }
};
}

const int N = 100000;

VI es[N];
int n;
VI children[N];
vector<Hash> hval[N], psum[N];
Hash f[N];

Hash sum(int x, int l, int r) { return psum[x][r].remove_l(psum[x][l]); }

void prepare(int x, int fa) {
    vector<pair<Hash, int>> v;
    for(int y : es[x]) {
        if(y != fa) {
            prepare(y, x);
            v.pb(mp(f[y], y));
        }
    }
    sort(all(v));
    children[x].resize(sz(v));
    hval[x].resize(sz(v));
    psum[x].resize(sz(v) + 1);
    repn(i, sz(v)) {
        children[x][i] = v[i].se;
        hval[x][i] = v[i].fi;
        psum[x][i + 1] = psum[x][i] + hval[x][i];
    }
    f[x] = Hash(1) + psum[x][sz(v)] + Hash(2);
}

unordered_map<Hash, int> m;
void add_m(Hash h, int delta) {
    if((m[h] += delta) <= 0) {
        m.erase(h);
    }
}

void solve(PII* ans, int x, Hash up) {
    add_m(f[x], -1);
    setmax(*ans, mp(sz(m), x));
    int i = int(lower_bound(all(hval[x]), up) - hval[x].begin());
    repn(j, sz(children[x])) {
        Hash cur;
        if(j < i) {
            cur = sum(x, 0, j) + sum(x, j + 1, i) + up +
                  sum(x, i, sz(children[x]));
        } else {
            cur = sum(x, 0, i) + up + sum(x, i, j) +
                  sum(x, j + 1, sz(children[x]));
        }
        cur = Hash(1) + cur + Hash(2);
        add_m(cur, 1);
        solve(ans, children[x][j], cur);
        add_m(cur, -1);
    }
    add_m(f[x], 1);
}

int main() {
    Hash::init(N * 2);
    scanf("%d", &n);
    repn(i, n - 1) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        es[a].pb(b), es[b].pb(a);
    }
    prepare(0, -1);

    repn(x, n) add_m(f[x], 1);
    PII ans{-1, -1};
    solve(&ans, 0, Hash());
    printf("%d\n", ans.se + 1);

    return 0;
}