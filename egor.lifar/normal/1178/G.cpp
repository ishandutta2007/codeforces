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
const int MAXN = 200229;


int n, q;
vector<int> gg[MAXN];
int a[MAXN], b[MAXN];
long long cura[MAXN], curb[MAXN];
vector<int> order;
int in[MAXN], out[MAXN];
int timer = 0;


void dfs(int u) {
    timer++;
    in[u] = timer;
    order.pb(u);
    cura[u] += a[u];
    curb[u] += b[u];
    for (auto h: gg[u]) {
        cura[h] += cura[u];
        curb[h] += curb[u];
        dfs(h);
    }
    out[u] = timer;
}



struct Line {
    long long k, b;
    int id;
    Line(){}
    Line(long long _k, long long _b, int _id) {
        k = _k;
        b = _b;
        id = _id;
    }
    long long value(long long x) {
        return k * x + b;
    }
};


bool operator <(const Line &a, const Line &b) {
    return a.k < b.k || (a.k == b.k && a.b < b.b);
}


struct ConvexHull
{
    vector<Line> st;
    int uks = 0;
    bool better(Line a, Line b, Line c) {
        return (c.b - a.b) * (a.k - b.k) <=  (b.b - a.b) * (a.k - c.k);
    }
    void addLine(Line x) {
        while (sz(st) >= 2 && better(st[sz(st) - 2], st.back(), x)) {
            st.pop_back();
        }
        st.pb(x);
    }
} kek[MAXN], kek1[MAXN], kek2[MAXN], kek3[MAXN];


long long curadd[MAXN];
long long curadd1[MAXN];
vector<Line> g[MAXN], g1[MAXN];


void pushadd(ConvexHull &a, long long value) {
    while (a.uks + 1 < sz(a.st) && a.st[a.uks].value(value) <= a.st[a.uks + 1].value(value)) {
        a.uks++;
    }
}


void pushadd1(ConvexHull &a, long long value) {
    while (a.uks > 0 && a.st[a.uks - 1].value(value) >= a.st[a.uks].value(value)) {
        a.uks--;
    }
}

void upd(int i, int val) {
    curadd[i] += val;
    curadd1[i] -= val;
    pushadd(kek[i], curadd[i]);
    pushadd1(kek1[i], curadd1[i]);
}



void add(vector<Line> &f, ConvexHull &a, int l, int r, long long x, long long val, bool ff = false) {
    a.st.clear();
    a.uks = 0;
    for (auto &z: f) {
        z.b += z.k * val;
        if (in[z.id] >= l && in[z.id] <= r) {
            z.b += z.k * x;
        }
    }
    for (auto z: f) {
        a.addLine(z);
    }
    if (ff) {
        a.uks = sz(a.st) - 1;
        pushadd1(a, 0);
    } else {
        pushadd(a, 0);
    }
}



void add(int l, int r, long long x) {
    for (int i = l >> 8; i <= (r >> 8); i++) {
        if (i == (l >> 8) || i == (r >> 8)) {
            add(g[i], kek[i], l, r, x, curadd[i]);
            add(g1[i], kek1[i], l, r, -x, curadd1[i], true);
            curadd[i] = 0;
            curadd1[i] = 0;
        } else {
            upd(i, x);
        }
    }
}


long long get(int l, int r) {
    long long ans = -4e18;
    for (int i = l >> 8; i <= (r >> 8); i++) {
        if (i == (l >> 8) || i == (r >> 8)) {
            for (auto z: g[i]) {
                if (in[z.id] >= l && in[z.id] <= r) {
                    chkmax(ans, z.value(curadd[i]));
                }
            }
            for (auto z: g1[i]) {
                if (in[z.id] >= l && in[z.id] <= r) {
                    chkmax(ans, z.value(curadd1[i]));
                }
            }
        } else {
            chkmax(ans, kek[i].st[kek[i].uks].value(curadd[i]));
            chkmax(ans, kek1[i].st[kek1[i].uks].value(curadd1[i]));
        }
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        gg[p].pb(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    dfs(0);
    for (int i = 0; i < n; i++) {
        in[i]--;
        out[i]--;
    }
    for (int i = 0; i < n; i++) {
        int u = order[i];
        curb[u] = abs(curb[u]);
        g[i >> 8].pb(Line(curb[u], cura[u] * curb[u], u));
        g1[i >> 8].pb(Line(curb[u], -cura[u] * curb[u], u));
    }
    for (int i = 0; i <= (n - 1) >> 8; i++) {
        sort(all(g[i]));
         sort(all(g1[i]));
        for (auto z: g[i]) {
            kek[i].addLine(z);
        }
        pushadd(kek[i], 0);
        for (auto z: g1[i]) {
            kek1[i].addLine(z);
        }
        pushadd(kek1[i], 0);
    }
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int v, x;
            cin >> v >> x;
            v--;
            add(in[v], out[v], x);
        } else {
            int u;
            cin >> u;
            u--;
            cout << get(in[u], out[u]) << '\n';
        }
    }
    return 0;
}