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





int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);     
    ll x0, y0, ax, ay, bx, by;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    ll xs, ys, t;
    cin >> xs >> ys >> t;
    vector<pair<ll, ll> > st;
    while (true) {
        st.pb({x0, y0});
        x0 = (x0 * ax + bx);
        y0 = (y0 * ay + by);
        if (x0 > xs + t || y0 > ys + t) {
            break;
        }
    }
    int res = 0;
    for (int i = 0; i < sz(st); i++) {
        for (int j = i; j < sz(st); j++) {
            for (int k = i; k <= j; k++) {
                ll ts = abs(xs - st[k].first) + abs(ys - st[k].second);
                ll cx = st[k].first;
                ll cy = st[k].second;
                for (int g = k - 1; g >= i; g--) {
                    ts += abs(cx - st[g].first) + abs(cy - st[g].second);
                    cx = st[g].first;
                    cy = st[g].second;
                }
                for (int g = k + 1; g <= j; g++) {
                    ts += abs(cx - st[g].first) + abs(cy - st[g].second);
                    cx = st[g].first;
                    cy = st[g].second;
                }
                if (ts <= t) {
                    chkmax(res, j - i + 1);
                }
            }
        }
    }
    for (int i = 0; i < sz(st); i++) {
        for (int j = i; j < sz(st); j++) {
            for (int k = i; k <= j; k++) {
                ll ts = abs(xs - st[k].first) + abs(ys - st[k].second);
                ll cx = st[k].first;
                ll cy = st[k].second;
                for (int g = k + 1; g <= j; g++) {
                    ts += abs(cx - st[g].first) + abs(cy - st[g].second);
                    cx = st[g].first;
                    cy = st[g].second;
                }
                for (int g = k - 1; g >= i; g--) {
                    ts += abs(cx - st[g].first) + abs(cy - st[g].second);
                    cx = st[g].first;
                    cy = st[g].second;
                }
                if (ts <= t) {
                    chkmax(res, j - i + 1);
                }
            }
        }
    }
    cout << res << '\n';
    return 0;
}