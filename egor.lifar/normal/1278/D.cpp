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
const int MAXN = 1000228;


int n;
int parent[MAXN];
int st[MAXN];
int en[MAXN];


int findset(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = findset(parent[v]);
}


int merge(int a, int b) {
    a = findset(a);
    b = findset(b);
    if (a == b) {
        return false;
    }
    parent[a] = b;
    return true;
}


int rev[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        st[l] = i + 1;
        en[r] = i + 1;
        rev[i] = r;
    }
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    set<int> s;
    for (int i = 1; i <= 2 * n; i++) {
        if (st[i]) {
            for (auto x: s) {
                if (x > rev[st[i] - 1]) {
                    break;
                }
                if (!merge(en[x], st[i])) {
                    cout << "NO\n";
                    return 0;
                }
            }
            s.insert(rev[st[i] - 1]);
        } else {
            s.erase(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (findset(i) != findset(1)) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}