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
const int MAXN = 8000228;


int h, g;
int n;
int a[MAXN];
vector<int> st;


bool kek(int i) {
    if (a[i * 2] == 0 && a[i * 2 + 1] == 0) {
        if (i < (1 << g)) {
            return false;
        }
        a[i] = 0;
        return true;
    }
    if (a[i * 2] > a[i * 2 + 1]) {
        int c = a[i * 2];
        bool t = kek(i * 2);
        if (t) {
            a[i] = c;
            return true;
        }
        return false;
    } else {
        int c = a[i * 2 + 1];
        bool t = kek(i * 2 + 1);
        if (t) {
            a[i] = c;
            return true;
        }
        return false;
    }
}

void get(int i) {
    if (i >= (1 << g)) {
        return;
    }
    while (kek(i)) {
        st.pb(i);
    }
    get(i * 2);
    get(i * 2 + 1);
}

void solve() {
    cin >> h >> g;
    n = (1 << h) - 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    st.clear();
    get(1);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
    }
    cout << sum << '\n';
    for (auto x: st) {
        cout << x << ' ';
    }
    cout << '\n';
    for (int i = 1; i <= n; i++) {
        a[i] = 0;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}