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


bool used[2000];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  //  read(FILENAME);
  	string s;
  	cin >> s;
  	vector<vector<int> > res;
  	while (true) {
  		int l = 0;
  		int r = sz(s) - 1;
  		while (l < sz(s) && s[l] != '(') {
  			l++;
  		}
  		while (r >= 0 && s[r] != ')') {
  			r--;
  		}
  		if (l > r) {
  			break;
  		}
  		vector<int> a, b;
  		a.pb(l);
  		b.pb(r);
  		while (true) {
  			l++;
  			r--;
  			if (l > r) {
  				break;
  			}
  			while (l < sz(s) && s[l] != '(') {
	  			l++;
	  		}
	  		while (r >= 0 && s[r] != ')') {
	  			r--;
	  		}
	  		if (l > r) {
	  			break;
	  		}
	  		a.pb(l);
  			b.pb(r);
  		}
  		reverse(all(b));
  		for (auto x: b) {
  			a.pb(x);
  		}
  		res.pb(a);
  		memset(used, 0, sizeof(used));
  		for (auto x: a) {
  			used[x] = true;
  		}
  		string t;
  		for (int i = 0; i < sz(a); i++) {
  			if (!used[i]) {
  				t += s[i];
  			}
  		}
  		s = t;
  	}
  	cout << sz(res) << '\n';
  	for (auto x: res) {
  		cout << sz(x) << '\n';
  		for (auto y: x) {
  			cout << y + 1 << ' ';
  		}
  		cout << '\n';
  	}
    return 0;    
}