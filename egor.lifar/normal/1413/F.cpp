/*














 */
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
 
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left224
#define right right224
#define next next224
#define rank rank224
#define prev prev224
#define y1 y1224
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
const string FILENAME = "input";
const int MAXN = 500228;
 
int n, q;
vector<pair<int, int> > g[MAXN];
int c[MAXN];
int dep[MAXN];
int last = 0;
int ft[MAXN];
int sums[MAXN];
unordered_map<int, int> in[MAXN];
vector<int> out[MAXN];
int timer;
vector<int> who[MAXN];
vector<int> score[MAXN][2];
 
 
struct rmq
{
    vector<pair<int, int> > d;
    vector<int> mod;
    int ss = 1;
    void init(int n) {
        while (ss < n) {
            ss <<= 1;
        }
        d.resize(2 * ss);
        mod.resize(2 * ss);
        for (auto &x: d) {
            x  = mp(0, 0);
        }
        for (auto &x: mod) {
            x = 0;
        }
    }
    void relax() {
        for (int v = ss - 1; v >= 0; v--) {
            d[v].first = max(d[v * 2].first, d[v * 2 + 1].first);
            d[v].second = max(d[v * 2].second, d[v * 2 + 1].second);
        }
    }
    void push(int v) {
        if (mod[v] != 0) {
            swap(d[v].first, d[v].second);
            if (v < ss) {
                mod[v * 2] ^= mod[v];
                mod[v * 2 + 1] ^= mod[v];
            }
            mod[v] = 0;
        }
    }
    void add(int v, int vl, int vr, int l, int r, int x) {
        if (vl > r || vr < l) {
            push(v);
            return;
        }
        if (l <= vl && vr <= r) {
            mod[v] ^= x;
            push(v);
            return;
        }
        push(v);
        add(v * 2, vl, (vl + vr) / 2, l, r, x);
        add(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, x);
        d[v].first = max(d[v * 2].first, d[v * 2 + 1].first);
        d[v].second = max(d[v * 2].second, d[v * 2 + 1].second);
    }
    int curadd = 0;
    int getmax(int v, int vl, int vr, int l, int r, int dd) {
        if (vl > r || vr < l) {
            return 0LL;
        }
        if (l <= vl && vr <= r) {
            int need = dd ^ mod[v] ^ curadd;
            return (need == 0 ? d[v].first: d[v].second);
        }
        curadd ^= mod[v];
        auto res = max(getmax(v * 2, vl, (vl + vr) / 2, l, r, dd), getmax(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, dd));
        curadd ^= mod[v];
        return res;
    }
} kek[MAXN];
 
 
 
multiset<int> keks[MAXN][2];
vector<int> deps[MAXN];
int cs[MAXN];
int root;
int deep[MAXN];
 
 
void dfs(int u, int pr = -1) {
    timer++;
    in[root][u] = timer;
    int pos = timer - 1;
    //cout << pos << ' ' << sz(out[root]) << endl;
    for (auto h: g[u]) {
        if (h.first == pr) {
            continue;
        }
        if (deep[h.first]) {
            continue;
        }
        if (u == root) {
            who[root][timer] = timer;
        } else {
            who[root][timer] = who[root][pos];
        }
        deps[root][timer] = deps[root][pos] + 1;
        cs[timer] = cs[pos] ^ c[h.second];
        int gg = timer;
        dfs(h.first, u);
        if (u == root) {
            for (int d = 0; d < 2; d++) {
                if (score[root][d][gg]) {
                    keks[root][d].insert(score[root][d][gg]);
                }
            }   
        }
    }  
    out[root][pos] = timer;
    chkmax(score[root][cs[pos]][who[root][pos]], deps[root][pos]);
    if (cs[pos] == 0) {
        kek[root].d[kek[root].ss + pos].first = deps[root][pos]; 
        kek[root].d[kek[root].ss + pos].second = 0;
    } else {
        kek[root].d[kek[root].ss + pos].second = deps[root][pos]; 
        kek[root].d[kek[root].ss + pos].first = 0;
    }
}
 
 
int ft1[MAXN];
 
 
void updateDistsForRoot(int root, int id, int diff) {
    int x = ft[id];
    int y = ft1[id];
    if (in[root].find(x) == in[root].end() || in[root].find(y) == in[root].end()) {
        return;
    }
    int fts = in[root][x] - 1;
    int fts1 = in[root][y] - 1;
    if (deps[root][fts] < deps[root][fts1]) {
        swap(x, y);
        swap(fts, fts1);
    }
    kek[root].add(1, 1, kek[root].ss, fts + 1, out[root][fts], diff);
    int ff = who[root][fts];
    for (int tt = 0; tt < 2; tt++) {
        auto &value = score[root][tt][ff];
        if (value != 0) {
            keks[root][tt].erase(keks[root][tt].find(value));
        }
        value = kek[root].getmax(1, 1, kek[root].ss, ff + 1, out[root][ff], tt);
        if (value != 0) {
            keks[root][tt].insert(value);
        }
    }
}
 
 
multiset<int> kekr;
 
 
int findAnsForRoot(int root) {
    int res = 0;
    for (int t = 0; t < 2; t++) {
        if (keks[root][t].empty()) {
            continue;
        }
        auto x = keks[root][t].rbegin();
        int ans = 0;
        int cp = 0;
        for (int it = 0; it < 2; it++) {
            if (x == keks[root][t].rend()) {
                break;
            }
            ans += *x;
            cp+= t;
            x++;
        }
        if (cp % 2 == 0) {
            chkmax(res, ans);
        }
    }
    return res;
}
 
 
 
void change(int root, int id, int diff) {
    kekr.erase(kekr.find(findAnsForRoot(root)));
    updateDistsForRoot(root, id, diff);
    kekr.insert(findAnsForRoot(root));
}
 
 
 
int sz[MAXN];
int cng;
int PRcentroid[MAXN];
vector<int> v[MAXN];
vector<int> sts;
int d[MAXN];
 
 
void dfs2(int u, int pr = -1) {
    sz[u] = 1;
    sts.push_back(u);
    for (auto h: g[u]) {
        if (!deep[h.first] && h.first != pr) {
            d[h.first] = d[u] + 1;
            dfs2(h.first, u);
            sz[u] += sz[h.first];
        }
    } 
}
 
 
int curcentre;
vector<int> st[MAXN];
 
 
void dfs1(int u, int pr = -1) {
    st[curcentre].push_back(u);
    for (auto h: g[u]) {
        if (!deep[h.first] && h.first != pr) {
            dfs1(h.first, u);
        }
    }
}
 
 
inline int find_centroid() {
    int ans = -1;
    for (auto u: sts) {
        if (sz[u] >= cng / 2) {
            if (ans == -1 || d[u] > d[ans]) {
                ans = u;
            }
        }
    }
    return ans;
}
 
 
void centroid_decomposition(int s) {
    curcentre = s;
    cng = n;
    dfs1(s);
    root = s;
    kek[root].init(cng);
    timer = 0;
    deps[root].resize(cng);
    out[root].resize(cng);
    who[root].resize(cng);
    score[root][1].resize(cng);
    score[root][0].resize(cng);
    cs[root] = 0;
    dfs(root);
    kek[root].relax();
    kekr.insert(findAnsForRoot(root));
}
 

int roots, root1;
 
 
void trys(int u, int id, int diff) {
    change(roots, id, diff);
    change(root1, id, diff);
}
      
int dist[MAXN];

      void dfsk(int u, int pr = -1) {
        for (auto h: g[u]) {
            if (h.first != pr) {
                dist[h.first] = dist[u] + 1;
                dfsk(h.first, u);
            }
        }
      }
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME); 
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b >> c[i];
        a--, b--;
        g[a].pb({b, i});
        g[b].pb({a, i});
        if (a > b) {
            swap(a, b);
        } 
        ft[i] = b;
        ft1[i] = a;
    }   
    dfsk(0);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] > dist[cur]) {
            cur = i;
        }
    }
    roots = cur;
    dist[roots] = 0;
    dfsk(roots);
    cur = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] > dist[cur]) {
            cur = i;
        }
    }
    root1 = cur;
    centroid_decomposition(roots);
    centroid_decomposition(root1);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int d;
        cin >> d;
        d--;
        c[d] ^= 1;
        trys(ft[d], d, 1);
       // cout << sz(kekr) << endl;
        if (kekr.empty()) {
            cout << 0 << '\n';
        } else {
            cout << *kekr.rbegin() << '\n';
        }
    }
    return 0; 
}