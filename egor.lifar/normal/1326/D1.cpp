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
const int MAXN = 1000228;


int d1[MAXN], d2[MAXN];

string get(string s) {
	int n = sz(s);
	for (int i = 0; i <= n; i++) {
		d1[i] = 0;
		d2[i] = 0;
	}
	int l = 0;
	int r = -1;
	int ans = 0;
	int ps, ps1;
	for (int i = 1; i <= n; i++) {
		int k = 0;
		if (i <= r) {
			k = min(r - i, d1[r - i + l]);
		}
		while (i + k + 1 <= n && i - k - 1 > 0 && s[i + k + 1 - 1] == s[i - k - 1 - 1]) {
			k++;
		}
		d1[i] = k;
		if (i + k > r) {
			l = i - k;
			r = i + k;
		}
		if (i - d1[i] == 1 || i + d1[i] == n) {
			chkmax(ans, d1[i] * 2 + 1);
			if (ans == d1[i] * 2 + 1) {
				ps = i - d1[i];
				ps1 = i + d1[i];
			}
		}
	}
	l = 0;
  	r = -1;
  	for (int i = 1; i <= n; i++) {
  		int k = 0;
  		if (i <= r) {
  			k = min(r - i + 1, d2[r - i + l + 1]);
  		}
  		while (i +  k <= n && i - k - 1 > 0 && s[i + k - 1] == s[i - k - 1 - 1]) {
  			k++;
  		}
  		d2[i] = k;
  		if (i + k - 1 > r) {
  			l = i - k;
  			r = i + k - 1;
  		}
  		if (i - d2[i] == 1 || i + d2[i] - 1 == n) {
  			chkmax(ans, d2[i] * 2);
  			if (ans == d2[i] * 2) {
				ps = i - d2[i];
				ps1 = i + d2[i] - 1;
			}
  		}
  	}
  	string fs;
  	for (int i = ps; i <= ps1; i++) {
  		fs += s[i - 1];
  	}
	return fs;
}

void solve() {
	string s;
	cin >> s;
	int l = 0;
	int r = sz(s) - 1;
	int ans = 0;
	string cur;
	while (l <= r && s[l] == s[r]) {
		cur += s[l];
		if (l != r) {
			ans += 2;
		} else {
			ans++;
		}
		l++;
		r--;
	}
	if (l > r) {
		cout << s << '\n';
		return;
	}
	string res;
	for (int i = l; i <= r; i++) {
		res += s[i];
	}
	string f = get(res);
	string cur1 = cur;
	reverse(all(cur1));
	cout << cur << f << cur1 << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME); 
    int t;
    cin >> t;
    while (t--) {
    	solve();
    }
    return 0;       
}