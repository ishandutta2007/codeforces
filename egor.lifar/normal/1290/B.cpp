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
#include <iomanip>
 
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
const int MAXN = 200228;

string s;
int pref[MAXN][26];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> s;
	for (int i = 0; i < sz(s); i++) {
		pref[i][s[i] - 'a']++;
		for (int j = 0; j < 26; j++) {
			if (i) {
				pref[i][j] += pref[i - 1][j]; 
			}
		}
	}
	int q;
	cin >> q;
	for (int it = 0; it < q; it++) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		if (l == r) {
			cout << "Yes\n";
			continue;
		}
		int cnt = 0;
		int kek = 0;
		char pc;
		for (int i = 0; i < 26; i++) {
			if (pref[r][i] - (l ? pref[l - 1][i]: 0) > 0) {
				cnt++;
				if (pref[r][i] - (l ? pref[l - 1][i]: 0) == 1) {
					kek++;
					pc = char('a' + i);
				}
			}
		}
		if (cnt == 1) {
			cout << "No\n";
		} else {
			if (cnt == 2) {
				if (s[l] == s[r]) {
					cout << "No\n";
				} else {
					cout << "Yes\n";
				}
			} else {
				cout << "Yes\n";
			}
		}
	}
	return 0;
}