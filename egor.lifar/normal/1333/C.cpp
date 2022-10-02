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
const int MAXN = 400228;


int n;
int a[MAXN];
map<ll, int> last;
int kek[MAXN];
int d[20][MAXN];


int getmax(int l, int r) {
    int t = 31 - __builtin_clz(r - l + 1);
    return max(d[t][l], d[t][(r - (1 << t) + 1)]);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }    
    last[0] = -1;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        int pos = 0;
        if (last.find(sum) != last.end()) {
            chkmax(pos, last[sum] + 2);
        }
        kek[i] = pos;
        last[sum] = i;
        d[0][i] = kek[i];
    }
    for (int k = 1; k <= 19; k++) {
        for (int i = 0; i < n; i++) {
            d[k][i] = max(d[k - 1][i], d[k - 1][min(n - 1, i + (1 << (k - 1)))]);
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            int l = 0;
            int r = i;
            while (l < r) {
                int mid= ( l + r) >> 1;
                int k = getmax(mid, i);
                if (k > mid) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            ans += i - l + 1;
        }
    }
    cout << ans << '\n';
    return 0;   
}