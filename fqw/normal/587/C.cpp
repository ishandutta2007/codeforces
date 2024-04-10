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

const int N = 100000;
const int LOG = 18;

VI es[N], people[N];
int size[N], head[N], pos[N], who[N], dep[N], up[N][LOG], counter;
int n;

void dfs_size(int x, int fa) {
    size[x] = 1;
    for(int y : es[x]) {
        if(y == fa) continue;
        dfs_size(y, x);
        size[x] += size[y];
    }
}

void dfs(int x, int fa, int d, int h) {
    fillchar(up[x], -1);
    up[x][0] = fa;
    for(int i = 0; up[x][i] >= 0; ++i) up[x][i + 1] = up[up[x][i]][i];
    dep[x] = d;

    head[x] = h, who[counter] = x, pos[x] = counter++;
    int my = -1;
    for(int y : es[x]) {
        if(y == fa) continue;
        if(my < 0 || size[y] > size[my]) my = y;
    }
    if(my >= 0) dfs(my, x, d + 1, h);
    for(int y : es[x]) {
        if(y != fa && y != my) dfs(y, x, d + 1, y);
    }
}

VI tr[N * 4];

void reduce(VI* a) {
    if(sz(*a) > 10) {
        nth_element(a->begin(), a->begin() + 10, a->end());
        a->resize(10);
    }
}

VI merge(VI a, VI b) {
    a.insert(a.end(), all(b));
    reduce(&a);
    return a;
}

void build(int x, int l, int r) {
    if(l + 1 == r) {
        reduce(&people[who[l]]);
        tr[x] = people[who[l]];
        return;
    }
    const int m = (l + r) / 2;
    build(x * 2 + 1, l, m);
    build(x * 2 + 2, m, r);
    tr[x] = merge(tr[x * 2 + 1], tr[x * 2 + 2]);
}

VI get(int x, int l, int r, int st, int en) {
    if(st <= l && r <= en) {
        return tr[x];
    }
    const int m = (l + r) / 2;
    VI ret;
    if(st < m) ret = merge(ret, get(x * 2 + 1, l, m, st, en));
    if(m < en) ret = merge(ret, get(x * 2 + 2, m, r, st, en));
    return ret;
}

int go_up(int a, int d) {
    irepn(i, LOG) if(d & (1 << i)) a = up[a][i];
    return a;
}

int lca(int a, int b) {
    int d = dep[a] - dep[b];
    if(d > 0) {
        a = go_up(a, d);
    } else {
        b = go_up(b, -d);
    }
    irepn(i, LOG) {
        if(up[a][i] != up[b][i]) {
            a = up[a][i], b = up[b][i];
        }
    }
    if(a != b) a = up[a][0];
    return a;
}

VI extract_up(int a, int b) {
    VI ret;
    while(1) {
        int h = head[a];
        if(dep[h] < dep[b]) h = b;
        //printf("get %d-%d [%d,%d]\n",h,a,pos[h],pos[a]);
        ret = merge(ret, get(0, 0, n, pos[h], pos[a] + 1));
        if(h == b) break;
        a = up[h][0];
    }
    return ret;
}

VI extract(int a, int b) {
    int c = lca(a, b);
    if(c == a) {
        return extract_up(b, c);
    } else {
        int d = go_up(a, dep[a] - dep[c] - 1);
        return merge(extract_up(a, d), extract(b, c));
    }
}

int main() {
    int m, q;
    scanf("%d%d%d", &n, &m, &q);
    repn(i, n - 1) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        es[a].pb(b), es[b].pb(a);
    }
    repn(i, m) {
        int x;
        scanf("%d", &x);
        --x;
        people[x].pb(i);
    }
    counter = 0;
    dfs_size(0, -1);
    dfs(0, -1, 0, 0);
    build(0, 0, n);

    while(q--) {
        int a, b, k;
        scanf("%d%d%d", &a, &b, &k);
        --a, --b;
        VI ret = extract(a, b);
        sort(all(ret));
        if(sz(ret) > k) ret.resize(k);
        printf("%d", sz(ret));
        for(int i : ret) printf(" %d", i + 1);
        printf("\n");
    }
    return 0;
}