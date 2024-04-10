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
const int MAXN = 200228;


int n;
int p[MAXN];
int where[MAXN];
int f[MAXN];


void inc(int i, int x) {
    for (; i < n; i |= (i + 1)) {
        f[i] += x;
    }
}


int get(int i) {
    int res = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) {
        res += f[i];
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  //  read(FILENAME);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        where[p[i]] = i;
    }
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        res += get(n - 1) - get(where[i]);
        inc(where[i], 1);
        res -= min(get(where[i] - 1), get(n - 1) - get(where[i]));
        int l = where[i];
        int r = n - 1;
        while (l != r) {
            int mid = (l + r + 1) >> 1;
            int s = get(mid);
            if (min(s - 1, i - s) != min(s, i - s)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        int fg = l;
        l = 0;
        r = where[i];
        while (l != r) {
            int mid = (l + r) >> 1;
            int s = get(mid - 1);
            if (min(s, i - s - 1) != min(s, i - s)) {
                r = mid;
            } else {
                l = mid  + 1;
            }
        }
        if (l <= fg) {
            res += fg - l + 1 - (get(fg) - get(l - 1));
        }
        cout << res << ' ';
    }
    cout << '\n';
}