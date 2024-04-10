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
    //read(FILENAME);
    int n, k;
    cin >> n >> k;
    map<int, int> cnt;
    for (int i = 0; i < k + 1; i++) {
    	vector<int> st;
    	for (int j = 0; j <= k; j++) {
    		if (j != i) {
    			st.pb(j);
    		}
    	}
    	cout << '?';
    	for (auto x: st) {
    		cout << ' ' << x + 1;
    	}
    	cout << endl;
    	int pos, val;
    	cin >> pos >> val;
    	cnt[val]++;
    }
 	for (auto x: cnt) {
 		cout << "!" << ' ' << k + 1 - x.second << endl;
 		break;	
 	}
}