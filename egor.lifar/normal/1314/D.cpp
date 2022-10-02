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
const int MAXN = 105;

int n, k;
int d[MAXN][MAXN];
vector<pair<int, int> > st[MAXN][MAXN];
int used[MAXN];
vector<int> cur;
ll res = 10e9;
ll sum = 0;


int get(int a, int b) {
    for (auto x: st[a][b]) {
        if (!used[x.second]) {
            return x.first;
        }
    }
    return 2e9;
}


void get(int need) {
    if (need == 0) {
        sum = 0;
        for (int i = 0; i < sz(cur) - 1; i++) {
            sum += get(cur[i], cur[i + 1]);
        }
        chkmin(res, sum + get(cur.back(), cur[0]));
        return;
    }
    for (int i = 0; i < n; i++) {
        used[i]++;
        cur.pb(i);
        get(need - 1);
        cur.pop_back();
        used[i]--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  //  read(FILENAME); 
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (i == k || j == k) {
                    continue;
                }
                st[i][j].pb({d[i][k] + d[k][j], k});
            }
            sort(all(st[i][j]));
        }
    }
    cur.pb(0);
    used[0] = 1;
    get(k / 2 - 1);
    cout << res << '\n';
    return 0;
}