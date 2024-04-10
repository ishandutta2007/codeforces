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
const int MAXN = 1028;


int n;
ll x[MAXN], y[MAXN];



int fs[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 	//read(FILENAME);
    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> x[i] >> y[i];
    	x[i] += 1000000000;
    	y[i] += 1000000000;
    }
    int k = 2;
    while (true) {
    	for (int i = 0; i < n; i++) {
    		fs[i] = x[i] + y[i];
    	}
	    vector<int> st, st1;
	    for (int i = 0; i < n; i++) {
	    	if (fs[i] % k == fs[0] % k) {
	    		st.pb(i);
	    	} else {
	    		st1.pb(i);
	    	}
	    }
	    if (sz(st) != 0 && sz(st) != n) {
	    	cout << sz(st) << '\n';
	    	for (auto x: st) {
	    		cout << x + 1 << ' ';
	    	}
	    	cout << '\n';
	    	return 0;
	    } 
	 	st.clear();
	 	st1.clear();
	    for (int i = 0; i < n; i++) {
	    	if (x[i] % k == x[0] % k) {
	    		st.pb(i);
	    	} else {
	    		st1.pb(i);
	    	}
	    }
	    if (sz(st) != 0 && sz(st) != n) {
	    	cout << sz(st) << '\n';
	    	for (auto x: st) {
	    		cout << x + 1 << ' ';
	    	}
	    	cout << '\n';
	    	return 0;
	    } 
	    st.clear();
	 	st1.clear();
	    for (int i = 0; i < n; i++) {
	    	if (y[i] % k == y[0] % k) {
	    		st.pb(i);
	    	} else {
	    		st1.pb(i);
	    	}
	    }
	    if (sz(st) != 0 && sz(st) != n) {
	    	cout << sz(st) << '\n';
	    	for (auto x: st) {
	    		cout << x + 1 << ' ';
	    	}
	    	cout << '\n';
	    	return 0;
	    } 
	    for (int i = 0; i < n; i++) {
	    	x[i] /= 2;
	    	y[i] /= 2;
	    }
   	}
}