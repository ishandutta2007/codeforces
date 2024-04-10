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
const int MAXN = 1000229;


int n;
int a[MAXN];
double d[MAXN];
// double mod[MAXN * 4];
// double sum[MAXN * 4];
// int ss = 1;


// void push(int v, int len) {
//     if (mod[v] > 0) {
//         sum[v] = mod[v] * len;
//         if (v < ss) {
//             mod[v * 2] = mod[v];
//             mod[v * 2 + 1] = mod[v];
//         }
//         mod[v] = 0;
//     }
// }


// void set(int v, int vl, int vr, int l, int r, double x) {
//     if (vl > r || vr < l) {
//          push(v, vr - vl + 1);
//         return;
//     }
//     if (l <= vl && vr <= r) {
//         mod[v] = x;
//         push(v, vr - vl + 1);
//         return;
//     }
//     push(v, vr - vl + 1);
//     set(v * 2, vl, (vl + vr) / 2, l, r, x);
//     set(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, x);
//     sum[v] = sum[v * 2] + sum[v * 2 + 1];
// }


// double getsum(int v, int vl, int vr, int l, int r) {
//     if (l > vr || vr < l) {
//         return 0;
//     }
//     if (l <= vl && vr <= r) {
//         push(v, vr - vl + 1);
//         return sum[v];
//     }
//     push(v, vr - vl + 1);
//     return getsum(v * 2, vl, (vl + vr) / 2, l, r) + getsum(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r);
// }


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  	//read(FILENAME); 
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        d[i] = a[i];
    }
    vector<pair<double, pair<int, int> > > st;
    for (int i = 0; i < n; i++) {
        int last = i;
        int len = 1;
        while (!st.empty() && st.back().first > d[i]) {
            last = st.back().second.first;
            int vlen = st.back().second.second - st.back().second.first + 1;
            d[i] = (st.back().first * vlen + d[i] * len) / (vlen + len);
            len += vlen;
            st.pop_back(); 
        }
        st.pb({d[i], {last, i}});
    }
    for (auto x: st) {
        for (int j = 0; j < x.second.second - x.second.first + 1; j++) {
            cout.precision(10);
            cout << fixed << x.first << '\n';
        }
    }
    return 0;
}