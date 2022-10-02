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
const int MAXN = 100229;


int n;
int x[MAXN], y[MAXN];


ll dist(int i, int j) {
    return (ll)(x[i] - x[j]) * (x[i] - x[j]) + (ll)(y[i] - y[j]) * (y[i] - y[j]);
}

ll vec(ll x1, ll y1, ll x2, ll y2) {
    return x1 * y2 - x2 * y1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  	//read(FILENAME); 
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    if (n % 2 == 0) {
        for (int i = 0; i < n; i++) {
            int g = i + n / 2;
            g %= n;
            if (dist(i, (i + 1) % n) != dist(g, (g + 1) % n) || vec(x[(i + 1) % n] - x[i], y[(i + 1) % n] - y[i], x[(g + 1) % n] - x[g], y[(g + 1) % n] - y[g]) != 0) {
                cout << "NO\n";
                exit(0);
            }
        }
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}