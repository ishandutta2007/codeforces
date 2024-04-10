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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    int n;
    cin >> n;
    for (int it = 0; it < n; it++) {
        string s;
        cin >> s;
        int f = 0;
        for (auto x: s) {
            f += x - '0';
        }
        sort(all(s));
        if (s[0] == '0') {
            bool was = false;
            for (int i = 1; i < sz(s); i++) {
                if ((s[i] - '0') % 2 == 0) {
                    was = true;
                }
            }
            if (was && f % 3 == 0) {
                cout << "red\n";
                continue;
            }
        }
        cout << "cyan\n";
    }
}