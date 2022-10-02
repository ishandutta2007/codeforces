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
const string FILENAME = "input";





int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  	//read(FILENAME);
  	int tt;
	cin >> tt;
	for (int it = 0; it < tt; it++) {
		string s;
		int n, k;
		cin >> n >> k >> s;
		int len = n - (k - 1) * 2;
		string t;
		for (int i = 0; i < len; i++) {
			if (i < len / 2) {
				t += '(';
			} else {
				t += ')';
			}
		}
		for (int j = 0; j < (k - 1); j++) {
			t += '(';
			t += ')';
		}
		vector<pair<int, int> > st;
		for (int i = sz(s) - 1; i >= 0; i--) {
			if (s[i] != t[i]) {
				for (int j = i - 1; j >= 0; j--) {
					if (s[j] == t[i]) {
						st.pb({j + 1, i + 1});
						for (int g = j; g <= (i + j) / 2; g++) {
							swap(s[g], s[i - (g - j)]);
						}
						break;
					}
				}
			}
		}
		assert(s == t);
		cout << sz(st) << '\n';
		for (auto x: st) {
			cout << x.first << ' ' << x.second << '\n';
		}
	}
}