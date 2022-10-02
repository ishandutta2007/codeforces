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
#define left left228
#define right right228
#define rank rank228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
using ld = long double;
// const int MAXMEM = 200 * 1000 * 1024;
// char _memory[MAXMEM];
// size_t _ptr = 0;
// void* operator new(size_t _x) { _ptr += _x; return _memory + _ptr - _x; }
// void operator delete (void*) noexcept {}
const string FILENAME = "input";
const int MAXN = 300228;


int n;
int x[MAXN], y[MAXN];
vector<int> whox[MAXN], whoy[MAXN];
vector<pair<int, int> > stx[MAXN], sty[MAXN];
vector<int> who[MAXN], who1[MAXN];
vector<int> gx[MAXN], gy[MAXN];
int ukx = 0;
int uky = 0;
unordered_map<int, int> wherex[MAXN], wherey[MAXN];


void add_edgex(int i, int j, int i1, int j1) {
    gx[who[i][j]].pb(who[i1][j1]);
    gx[who[i1][j1]].pb(who[i][j]);
}


void add_edgey(int i, int j, int i1, int j1) {
    gy[who1[i][j]].pb(who1[i1][j1]);
    gy[who1[i1][j1]].pb(who1[i][j]);
}

int res[MAXN];
int posx[MAXN], posy[MAXN];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<int> g[MAXN];
int prcentroidx[MAXN];
int levelx[MAXN];
int prcentroidy[MAXN];
int levely[MAXN];
int sz[MAXN];
int deep[MAXN];
vector<int> str;
int distancesx[20][MAXN];
int distancesy[20][MAXN];
int pz;


void dfsbx(int u, int pr = -1) {
    sz[u] = 1;
    str.pb(u);
    for (auto h: gx[u]) {
        if (!levelx[h] && h != pr) {
            deep[h] = deep[u] + 1;
            dfsbx(h, u);
            sz[u] += sz[h];
        }
    }
}

void dfsdistx(int u, int cur, int pr = -1) {
    distancesx[levelx[pz]][u] = cur;
    for (auto h: gx[u]) {
        if (h != pr && !levelx[h]) {
            dfsdistx(h, cur + 1, u);
        }
    }
}


void buildcentroidsx(int cur, int last = -1) {
    str.clear();
    dfsbx(cur);
    int u = -1;
    for (auto x: str) {
        if (sz[x] >= (sz(str) + 1) / 2) {
            if (u == -1 || deep[u] < deep[x]) {
                u = x;
            }
        }
    }
    prcentroidx[u] = last;
    levelx[u] = 1 + (last != -1 ? levelx[last]: 0);
    pz = u;
    dfsdistx(u, 0);
    for (auto h: gx[u]) {
        if (!levelx[h]) {
            buildcentroidsx(h, u);
        }
    }
}




void dfsby(int u, int pr = -1) {
    sz[u] = 1;
    str.pb(u);
    for (auto h: gy[u]) {
        if (!levely[h] && h != pr) {
            deep[h] = deep[u] + 1;
            dfsby(h, u);
            sz[u] += sz[h];
        }
    }
}


void dfsdisty(int u, int cur, int pr = -1) {
    distancesy[levely[pz]][u] = cur;
    for (auto h: gy[u]) {
        if (h != pr && !levely[h]) {
            dfsdisty(h, cur + 1, u);
        }
    }
}


void buildcentroidsy(int cur, int last = -1) {
    str.clear();
    dfsby(cur);
    int u = -1;
    for (auto x: str) {
        if (sz[x] >= (sz(str) + 1) / 2) {
            if (u == -1 || deep[u] < deep[x]) {
                u = x;
            }
        }
    }
    prcentroidy[u] = last;
    levely[u] = 1 + (last != -1 ? levely[last]: 0);
    pz = u;
    dfsdisty(u, 0);
    for (auto h: gy[u]) {
        if (!levely[h]) {
            buildcentroidsy(h, u);
        }
    }
}


unordered_map<int, int> kek[MAXN];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; i++) {
        whox[x[i]].pb(y[i]);
        whoy[y[i]].pb(x[i]);
    }
    bool ok = true;
    for (int i = 0; i <= 300000; i++) {
        sort(all(whox[i]));
        int last = -1;
        int prev;
        vector<pair<int, int> > fg;
        for (auto x: whox[i]) {
            if (last == -1) {
                last = x;
                prev = x;
            } else {
                if (prev + 1 == x) {
                    prev = x;
                } else {
                    fg.pb({last, prev});
                    last = x;
                    prev = x;
                }
            }
        }
        
        if (last != -1) {
            fg.pb({last, prev});
        }
        if (sz(fg) > 1) {
            ok = false;
        }
        stx[i] = fg;
    }   
    for (int i = 0; i <= 300000; i++) {
        sort(all(whoy[i]));
        int last = -1;
        int prev;
        vector<pair<int, int> > fg;
        for (auto x: whoy[i]) {
            if (last == -1) {
                last = x;
                prev = x;
            } else {
                if (prev + 1 == x) {
                    prev = x;
                } else {
                    fg.pb({last, prev});
                    last = x;
                    prev = x;
                }
            }
        }
        if (last != -1) {
            fg.pb({last, prev});
        }
        if (sz(fg) > 1) {
            ok = false;
        }
        sty[i] = fg;
    }  
    for (int i = 0; i <= 300000; i++) {
        int it = 0;
        for (auto x: stx[i]) {
            who[i].pb(ukx);
            for (int j = x.first; j <= x.second; j++) {
                wherex[i][j] = ukx;
            }
            ukx++;
            it++;       
        }
    }
    for (int i = 0; i <= 300000; i++) {
        int it = 0;
        for (auto x: sty[i]) {
            who1[i].pb(uky);
            for (int j = x.first; j <= x.second; j++) {
                wherey[j][i] = uky;
            }
            uky++;
            it++;       
        }
    }
    for (int i = 0; i < 300000; i++) {
        int it = 0;
        for (auto x: stx[i]) {
            int pos = lower_bound(all(stx[i + 1]), mp(x.first, 0)) - stx[i + 1].begin();
            pos--;
            if (pos < 0) {
                pos++;
            }
            while (pos < sz(stx[i + 1])) {
                if (stx[i + 1][pos].first > x.second) {
                    break;
                }
                if (stx[i + 1][pos].second >= x.first) {
                    add_edgex(i, it, i + 1, pos);
                }
                pos++;
            }
            it++;
        }
    } 
    for (int i = 0; i < 300000; i++) {
        int it = 0;
        for (auto x: sty[i]) {
            int pos = lower_bound(all(sty[i + 1]), mp(x.first, 0)) - sty[i + 1].begin();
            pos--;
            if (pos < 0) {
                pos++;
            }
            while (pos < sz(sty[i + 1])) {
                if (sty[i + 1][pos].first > x.second) {
                    break;
                }
                if (sty[i + 1][pos].second >= x.first) {
                    add_edgey(i, it, i + 1, pos);
                }
                pos++;
            }
            it++;
        }
    } 
    int q;
    cin >> q;
    int cur =0;
    vector<pair<int, pair<int, int> > > st;
    for (int it = 0; it < q; it++) {
        int t;
        cin >> t;
        int x, y;
        cin >> x >> y;
        st.pb({t, {wherex[x][y], wherey[x][y]}});
        if (t == 1) {
            res[it] = -1;
        } else {
            res[it] = 1e9;
        }
    }
    for (int lvl = 1; lvl <= 19; lvl++) {
        for (int i = 0; i < n; i++) {
            distancesx[lvl][i] = 1e8;
            distancesy[lvl][i] = 1e8;
        }
    }
    buildcentroidsx(0);
    buildcentroidsy(0);
    for (int lvl = 1; lvl <= 19; lvl++) {
        for (int it = 0; it < n; it++) {
            kek[it].clear();
        }
        for (int it = 0; it < q; it++) {
            int t = st[it].first;
            int pos = st[it].second.first;
            int pos1 = st[it].second.second;
            if (t == 1) {   
                if (levelx[pos] < lvl) {
                    continue;
                }
                int f = pos;
                while (levelx[f] != lvl) {
                    f = prcentroidx[f];
                }
                int g = pos1;
                while (g != -1) {
                    if (kek[f].find(g) == kek[f].end()) {
                        kek[f][g] = distancesx[lvl][pos] + distancesy[levely[g]][pos1];
                    } else {
                        chkmin(kek[f][g], distancesx[lvl][pos] + distancesy[levely[g]][pos1]);
                    }
                    g = prcentroidy[g];
                }
            } else {
                if (levelx[pos] < lvl) {
                    continue;
                }
                int f = pos;
                while (levelx[f] != lvl) {
                    f = prcentroidx[f];
                }
                int g = pos1;
                if (distancesx[lvl][pos] < res[it]) {
                    while (g != -1) {
                        if (kek[f].find(g) != kek[f].end()) {
                            chkmin(res[it], kek[f][g] + distancesx[lvl][pos] + distancesy[levely[g]][pos1]);
                        }
                        g = prcentroidy[g];
                    }
                }
            }
        }
    }
    for (int it = 0; it < q; it++) {
        if (res[it] != -1) {
            if (res[it] > 1e7) {
                res[it] = -1;
            }
            cout << res[it] << '\n';
        }
    }
}