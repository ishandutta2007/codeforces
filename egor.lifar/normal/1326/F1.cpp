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



int n;
string b[20];
vector<ll> dp[270000][20];
ll res[270000];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME); 
    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    }
    for (int mask = 1; mask < (1 << n); mask++) {
    	vector<int> st;
    	for (int j = 0; j < n; j++) {
    		if (mask & (1 << j)) {
    			st.pb(j);
    		}
    	}
    	if (sz(st) < 2) {
    		continue;
    	}
    	for (int last = 0; last < sz(st); last++) {
    		int pos = sz(st) - 2;
    		dp[mask][st[last]].resize((1 << (sz(st) - 1)));
    		for (int j = 0; j < (1 << (sz(st) - 1)); j++) {
    			for (int ps = 0; ps < sz(st); ps++) {
    				if (ps == last) {
    					continue;
    				}
    				int c = b[st[last]][st[ps]] - '0';
    				int f = (j & (1 << pos));
    				if (f == 0 && c != 0) {
    					continue;
    				}
    				if (f && c != 1) {
    					continue;
    				}
    				int j1 = j ^ f;
    				if (pos == 0) {
    					dp[mask][st[last]][j]++;
    				} else {
    					dp[mask][st[last]][j] += dp[mask ^ (1 << st[last])][st[ps]][j1];
    				}
    			}
    		}
    	}
    }
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < (1 << (n - 1)); j++) {
    		res[j] += dp[(1 << n) - 1][i][j];
    	}
    }
    for (int i = 0; i < (1 << (n - 1)); i++) {
    	cout << res[i] << ' ';
    }
    cout << '\n';
    return 0;       
}