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
#define next next228
#define rank rank228
#define prev prev228
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
const int MAXN = 100228;


int n;
int a[MAXN * 2];
map<int, int> mcnt;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int t;
    cin >> t;
    for (int it = 0; it < t; it++) {
        cin >> n;
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
        }
        mcnt.clear();
        int cur = 0;
        for (int i = 0; i <= n; i++) {
            if (mcnt.find(cur) != mcnt.end()) {
                chkmin(mcnt[cur], n - i);
            } else {
                mcnt[cur] = n - i;
            }
            if (a[i] == 1) {
                cur++;
            } else {
                cur--;
            }
        }
        int res = 2 * n;
        cur = 0;
        for (int i = 2 * n - 1; i >= n - 1; i--) {
            if (mcnt.find(cur) != mcnt.end()) {
                chkmin(res, i - n + 1 + mcnt[cur]);
            }
            if (a[i] == 2) {
                cur++;
            } else {
                cur--;
            }
        }   
        cout << res << '\n';
    }
    
}