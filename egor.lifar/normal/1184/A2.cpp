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
 
 
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
const string FILENAME = "input";



bool bad[200002];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int add = 1;
	for (auto x: s) {
		if (x != '0') {
			add = 0;
		}
	}
	for (int j = 1; j < n; j++) {
		if (n % j != 0) continue;
		for (int i = 0; i < j; i++) {
			int cur = s[i] - '0';
			for (int k = i + j; k < n; k += j) {
				cur ^= s[k] - '0';
			}
			if (cur) {
				bad[j] = true;
				for (int g = j; g < n; g += j) {
					if (__gcd(g, n) == j) {
						bad[g] = true;
						//cout << g << endl;
					}
				}
				break;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i < n; i++) {
		if (!bad[i]) {
			ans++;
		}
	}
	cout << ans + add << '\n';
	return 0;
}