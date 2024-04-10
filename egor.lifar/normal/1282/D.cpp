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
   // read(FILENAME);
    int cntb;
    {
        string s;
        for (int i = 0; i < 300; i++) {
            s += 'b';
        }
        cout << s << endl;
        int res;
        cin >> res;
        if (res == 0) {
            exit(0);
        }
        cntb = -res + 300;
    }
    string s;
    for (int i = 0; i < 300; i++) {
        s += 'a';
    }
    cout << s << endl;
    int res;
    cin >> res;
    if (res == 0) {
        exit(0);
    }
    int cnta = -res + 300;
    string s1;
    for (int i = 0; i < cnta + cntb; i++) {
        s1 += s[i];
    }
    s = s1;
    res = cntb;
    int last = res;
    if (cntb == 0) {
        for (int i = 0; i < cnta; i++) {
            cout << 'a';
        }
        cout << endl;
        int res;
        cin >> res;
        assert(res == 0);
        return 0;
    }
    if (cnta == 0) {
        for (int i = 0; i < cntb; i++) {
            cout << 'b';
        }
        cout << endl;
        int res;
        cin >> res;
        assert(res == 0);
        return 0;
    }
    //cout << cntb << endl;
    for (int i = 0; i < cnta + cntb; i++) {
        s[i] = 'b';
        cout << s << endl;
        cin >> res;
        if (res == 0) {
            exit(0);
        }
        if (res < last) {
            last = res;
        } else {
            s[i] = 'a';
        }
    }
}