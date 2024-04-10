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
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()   
    
struct point {
    int x, y;
    point(){}
    point(int _x, int _y) {
        x = _x;
        y = _y;
    }
};


point a[4];
point c[4];

    int tests;

void solve() {
    for (int i = 0; i < 4; i++) {
        cin >> a[i].x >> a[i].y;    
    }
    int res = 1e9;
    
    vector<int> stx, sty, stx1, sty1;
    vector<int> d;
    for (int i = 0; i < 4; i++) {
        stx.pb(a[i].x);
        sty.pb(a[i].y);
        d.pb(a[i].y);
        d.pb(a[i].x);
    }
    sort(all(stx));
    stx.resize(distance(stx.begin(), unique(all(stx))));
    sort(all(sty));
    sty.resize(distance(sty.begin(), unique(all(sty))));
    for (int i = 0; i < sz(stx); i++) {
        for (int  j = i; j < sz(stx); j++) {
            d.pb(stx[j] - stx[i]);
        }
    }
    for (int i = 0; i < sz(sty); i++) {
        for (int  j = i; j < sz(sty); j++) {
            d.pb(sty[j] - sty[i]);
        }
    }
    sort(all(d));
    d.resize(distance(d.begin(), unique(all(d))));
    for (auto x: d) {
        vector<int> vx;
        for (int i = 0; i < 4; i++) {
            vx.pb(a[i].x - x);
            vx.pb(a[i].x);
            vx.pb(a[i].x + x);
        }
        vector<int> vy;
        for (int i = 0; i < 4; i++) {
            vy.pb(a[i].y - x);
            vy.pb(a[i].y);
            vy.pb(a[i].y + x);
        }
        sort(all(vx));
        vx.resize(distance(vx.begin(), unique(all(vx))));
        sort(all(vy));
        vy.resize(distance(vy.begin(), unique(all(vy))));
        vector<int> id;
        for (int i = 0; i < 4; i++) {
            id.pb(i);   
        }
        vector<point> s = {point(0, 0), point(0, x), point(x, 0), point(x, x)};
        do {
            vector<point> kek;
            int maxx = -2e9, minx = 2e9, maxy = -2e9, miny = 2e9;
            for (int i = 0; i < 4; i++) {
                kek.pb(point(a[id[i]].x - s[i].x, a[id[i]].y - s[i].y));
                chkmax(maxx, kek.back().x);
                chkmax(maxy, kek.back().y);
                chkmin(minx, kek.back().x);
                chkmin(miny, kek.back().y);
            }
            bool bad = false;
            bool bad1 = false;
            for (int i = 1; i < 4; i++) {
                if (kek[i].x != kek[0].x) {
                    bad = true;
                }
                if (kek[i].y != kek[0].y) {
                    bad1 = true;
                }
            }
            if (!bad) {
                int gy = (miny + maxy) / 2;
                int gx = kek[0].x;
                int tx = 0;
                vector<point> gg;
                for (auto x: s) {
                    gg.pb(point(gx + x.x, gy + x.y));
                }
                for (int i = 0; i < 4; i++) {
                    chkmax(tx, max(abs(a[id[i]].x - gg[i].x), abs(a[id[i]].y - gg[i].y)));
                }
                if (res > tx) {
                    res = tx;
                    for (int is = 0; is < sz(gg); is++) {
                        c[id[is]] = gg[is]; 
                    }
                }
            }
            if (!bad1) {
                int gx = (minx + maxx) / 2;
                int gy = kek[0].y;
                int tx = 0;
                vector<point> gg;
                for (auto x: s) {
                    gg.pb(point(gx + x.x, gy + x.y));
                }
                for (int i = 0; i < 4; i++) {
                    chkmax(tx, max(abs(a[id[i]].x - gg[i].x), abs(a[id[i]].y - gg[i].y)));
                }
                if (res > tx) {
                    res = tx;
                    for (int is = 0; is < sz(gg); is++) {
                        c[id[is]] = gg[is]; 
                    }
                }
            }
        } while (next_permutation(all(id)));
        for (int i = 0; i < sz(vx); i++) {
            for (int i1 = 0; i1 < sz(vy); i1++) {
                vector<int> id;
                for (int i = 0; i < 4; i++) {
                    id.pb(i);   
                }
                vector<point> gg;
                gg.pb(point(vx[i], vy[i1]));
                gg.pb(point(vx[i] + x, vy[i1]));
                gg.pb(point(vx[i], vy[i1] + x));
                gg.pb(point(vx[i] + x, vy[i1] + x));
                do {
                    bool bad = false;
                    int tx = 0;
                    for (int is = 0; is < sz(gg); is++) {
                        if (gg[is].x != a[id[is]].x && gg[is].y != a[id[is]].y) {
                            bad = true;
                            break;
                        }
                        int val = max(abs(gg[is].x - a[id[is]].x),  abs(gg[is].y - a[id[is]].y));
                        tx = max(tx, val);
                        if (tx >= res) {
                            break;
                        }
                    }
                    if (res > tx && !bad) {
                        res = tx;
                        for (int is = 0; is < sz(gg); is++) {
                            c[id[is]] = gg[is]; 
                        }
                    }
                } while (next_permutation(id.begin(), id.end()));
            }
        }               
    }
    if (res > 1e8) {
        cout << -1 << '\n';
        return;
    }
    cout << res << '\n';
    for (int i = 0; i < 4; i++) {
        cout << c[i].x << ' ' << c[i].y << '\n';
    }
}

signed main(signed argc, char *argv[]) {
    //freopen("input.in", "r", stdin);
    cin >> tests;
    for (int test = 0; test < tests; test++) {
        solve();
    }
}