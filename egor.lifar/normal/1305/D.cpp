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
const int MAXN = 8005;


int n;
set<int> g[MAXN];
bool used[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
   // read(FILENAME);
  	cin >> n;
  	for (int i = 0; i < n - 1; i++) {
  		int a, b;
  		cin >> a >> b;
  		g[a].insert(b);
  		g[b].insert(a);
  	}
  	set<int> s;
 	for (int i = 1; i <= n; i++) {
 		if (sz(g[i]) == 1) {
 			s.insert(i);
 			used[i] = true;
 		}
 	}
 	while (sz(s) > 1) {
 		int a = *s.begin();
 		s.erase(s.find(a));
 		int b = *s.begin();
 		s.erase(s.find(b));
 		cout << "? " << a << ' ' << b << endl;
 		int c;
 		cin >> c;
 		if (c == a || c == b) {
 			cout << "! " << c << endl;
 			return 0;
 		}	
 		for (auto x: g[a]) {
 			g[x].erase(a);
			if (!used[x] && sz(g[x]) <= 1) {
				used[x] = true;
				s.insert(x);
			}
 		}
 		for (auto x: g[b]) {
 			g[x].erase(b);
			if (!used[x] && sz(g[x]) <= 1) {
				used[x] = true;
				s.insert(x);
			} 		
		}
 	}
 	cout << "! " << *s.begin() << endl;
    return 0;    
}