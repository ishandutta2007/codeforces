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

const int B = 300;
typedef pair<LL, int> PLI;

struct E2 {
    int x, y1, y2, w;
    void read1() {
        scanf("%d%d%d", &x, &y1, &w);
        --x, --y1;
        y2 = y1 + 1;
    }
    void read() {
        scanf("%d%d%d%d", &x, &y1, &y2, &w);
        --x, --y1;
    }
};

struct E3 {
    int x1, x2, y, w;
    void read() {
        scanf("%d%d%d%d", &y, &x1, &x2, &w);
        --x1, --y;
    }
    bool operator<(const E3& e) const { return x2 < e.x2; }
};

int main() {
    int n, m, start;
    scanf("%d%d%d", &n, &m, &start);
    --start;
    vector<E2> es;
    vector<vector<E2>> e2(n);
    vector<vector<E3>> e3(n);
    repn(k, m) {
        int t;
        scanf("%d", &t);
        if(t == 1) {
            E2 e;
            e.read1();
            e2[e.x].pb(e);
        } else if(t == 2) {
            E2 e;
            e.read();
            e2[e.x].pb(e);
        } else if(t == 3) {
            E3 e;
            e.read();
            const int b = e.x1 / B * B;
            e3[b].pb(e);
        }
    }
    for(int b = 0; b < n; b += B) {
        sort(all(e3[b]));
    }

    VI next(n + 1);
    repn(i, n + 1) next[i] = i;
    const function<int(int)> get_next = [&](int x) {
        return next[x] == x ? x : next[x] = get_next(next[x]);
    };

    const LL INF = 1ll << 60;
    priority_queue<PLI, vector<PLI>, std::greater<PLI>> que;
    vector<bool> visited(n + m, false);
    vector<LL> dist(n + m, INF);
    const auto update = [&](int x, LL val) {
        if(val < dist[x]) {
            dist[x] = val;
            que.push(mp(val, x));
        }
    };
    update(start, 0);
    while(!que.empty()) {
        const int x = que.top().se;
        que.pop();
        if(visited[x]) continue;
        visited[x] = true;
        if(x < n) {
            for(const auto& e : e2[x]) {
                es.pb(e);
                update(n + sz(es) - 1, dist[x] + e.w);
            }
            const int cb = x / B * B;
            for(int b = 0; b < cb; b += B) {
                while(!e3[b].empty() && e3[b].back().x2 > x) {
                    update(e3[b].back().y, dist[x] + e3[b].back().w);
                    e3[b].pop_back();
                }
            }
            for(int i = 0; i < sz(e3[cb]);) {
                if(e3[cb][i].x1 <= x && e3[cb][i].x2 > x) {
                    update(e3[cb][i].y, dist[x] + e3[cb][i].w);
                    e3[cb][i] = e3[cb].back();
                    e3[cb].pop_back();
                } else {
                    ++i;
                }
            }
            sort(all(e3[cb]));
        } else {
            const auto e = es[x - n];
            for(int y = get_next(e.y1); y < e.y2; y = get_next(y)) {
                update(y, dist[x]);
                next[y] = y + 1;
            }
        }
    }
    repn(i, n) {
        if(dist[i] == INF) dist[i] = -1;
        printf("%lld ", dist[i]);
    }
    printf("\n");

    return 0;
}