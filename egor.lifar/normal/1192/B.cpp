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
const int MAXN = 150228;

int n, q;
long long w;
vector<pair<int, int> > g[MAXN];
long long c[MAXN];
long long dep[MAXN];
long long last = 0;
multiset<long long> alls;
int ft[MAXN];
long long sums[MAXN];
unordered_map<int, int> in[MAXN];
vector<int> out[MAXN];
int timer;
vector<int> who[MAXN];
vector<long long> score[MAXN];


struct rmq
{
    vector<long long> d;
    vector<long long> mod;
    int ss = 1;
    void init(int n) {
        while (ss < n) {
            ss <<= 1;
        }
        d.resize(2 * ss);
        mod.resize(2 * ss);
        for (auto &x: d) {
            x = 0;
        }
        for (auto &x: mod) {
            x = 0;
        }
    }
    void push(int v) {
        if (mod[v] != 0) {
            d[v] += mod[v];
            if (v < ss) {
                mod[v * 2] += mod[v];
                mod[v * 2 + 1] += mod[v];
            }
            mod[v] = 0;
        }
    }
    void add(int v, int vl, int vr, int l, int r, long long x) {
        if (vl > r || vr < l) {
            push(v);
            return;
        }
        if (l <= vl && vr <= r) {
            mod[v] += x;
            push(v);
            return;
        }
        push(v);
        add(v * 2, vl, (vl + vr) / 2, l, r, x);
        add(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, x);
        d[v] = max(d[v * 2], d[v * 2 + 1]);
    }
    long long curadd = 0;
    long long getmax(int v, int vl, int vr, int l, int r) {
        if (vl > r || vr < l) {
            return 0LL;
        }
        if (l <= vl && vr <= r) {
            return d[v] + mod[v] + curadd;
        }
        curadd += mod[v];
        auto res = max(getmax(v * 2, vl, (vl + vr) / 2, l, r), getmax(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r));
        curadd -= mod[v];
        return res;
    }
} kek[MAXN];



multiset<long long> keks[MAXN];
vector<long long> deps[MAXN];
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
      //  cerr << timer << ' ' << sz(out[root]) << endl;
        if (u == root) {
            who[root][timer] = timer;

        } else {
            who[root][timer] = who[root][pos];
        }
        deps[root][timer] = deps[root][pos] + c[h.second];
        int gg = timer;
        dfs(h.first, u);
        if (u == root) {
            keks[root].insert(score[root][gg]);
        }
    }  
    out[root][pos] = timer;
    chkmax(score[root][who[root][pos]], deps[root][pos]);
    kek[root].add(1, 1, kek[root].ss, pos + 1, pos + 1, deps[root][pos]);
}


int ft1[MAXN];


void updateDistsForRoot(int root, int id, long long diff) {
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
    auto &value = score[root][ff];
    keks[root].erase(keks[root].find(value));
    value = kek[root].getmax(1, 1, kek[root].ss, ff + 1, out[root][ff]);
    keks[root].insert(value);
}


multiset<long long> kekr;


long long findAnsForRoot(int root) {
    if (keks[root].empty()) {
        return 0LL;
    }
    long long res = 0;
    auto x = keks[root].rbegin();
    for (int it = 0; it < 2; it++) {
        if (x == keks[root].rend()) {
            break;
        }
        res += *x;
        x++;
    }
    return res;
}



void change(int root, int id, long long diff) {
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


void centroid_decomposition(int s, int last = -1) {
    //cout << s << endl;
    sts.clear();
    d[s] = 0;
    dfs2(s);
    cng = sz[s];
    //cout << cng << endl;
    if (cng == 1) {
        deep[s] = (last == -1 ? 1: deep[last + 1]);
        root = s;
        kek[root].init(cng);
        timer = 0;
        deps[root].resize(cng);
        out[root].resize(cng);
        who[root].resize(cng);
        score[root].resize(cng);
        dfs(root);
        kekr.insert(findAnsForRoot(root));
        PRcentroid[s] = last;
        return;
    }
    s = find_centroid();
    deep[s] = (last == -1 ? 1: deep[last] + 1);
    PRcentroid[s] = last;
    curcentre = s;
    dfs1(s);
    root = s;
    kek[root].init(cng);
    timer = 0;
    deps[root].resize(cng);
    out[root].resize(cng);
    who[root].resize(cng);
    score[root].resize(cng);
    dfs(root);
    kekr.insert(findAnsForRoot(root));
    for (auto h: g[s]) {
        if (!deep[h.first]) {
            centroid_decomposition(h.first, s);
        }
    }
}




void trys(int u, int id, long long diff) {
    while (u != -1) {
        change(u, id, diff);
        u = PRcentroid[u];
    }
}
      

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME); 
    cin >> n >> q >> w;
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
    centroid_decomposition(0);
    for (int i = 0; i < q; i++) {
        int d;
        long long e;
        cin >> d >> e;
        d = (d + last) % (n - 1);
        e = (e + last) % w;
        long long pc = c[d];
        c[d] = e;
        long long diff = e - pc;
        //cout << *kekr.rbegin() << endl;
        trys(ft[d], d, diff);
        last = *kekr.rbegin();
        cout << last << '\n';
    }
    return 0; 
}