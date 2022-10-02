/*














 */
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
const int MAXN = 300228;
 
 
int n;
int p[MAXN];
int q[MAXN];
vector<int> g[MAXN];
int where[MAXN];
int ss = 1;
bool bad[MAXN];
int d[MAXN * 4], mod[MAXN * 4];
 
 
void add(int v, int vl, int vr, const int l, const int r, const int x) {
	if (vl > r || vr < l) {
		return;
	}
	if (l <= vl && vr <= r) {
		mod[v] += x;
		return;
	}
	add(v *2 , vl, (vl + vr) / 2, l, r, x);
	add(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, x);
	d[v] = max(d[v * 2] + mod[v * 2], d[v * 2 + 1] + mod[v * 2 + 1]);
}
 
void add(int x, int val) {
	add(1, 1, ss, 1, x + 1, val);
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME); 
    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> p[i];
    	where[p[i]] = i;
    }
    for (int i = 0; i < n; i++) {
    	cin >> q[i];
    }
	ss = 1;
	while (ss < n) {
		ss <<= 1;
	}
	for (int i = 0; i < 2 * ss; i++) {
		d[i] = 0;
		mod[i] = 0;
	}
    int last = n;
    for (int i = 0; i < n; i++) {
        while (last >= 1) {
            add(where[last], 1);
            if (d[1] + mod[1] > 0) {
                add(where[last], -1);
                break;
            }
            last--;
        }
        cout << last << ' ';
        add(q[i] - 1, -1);
    }
    cout << '\n';
    return 0;       
}