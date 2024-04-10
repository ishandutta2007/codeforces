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
#include <complex>


using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
using ll = long long;
using ld = long double; 
const string FILENAME = "input";



ll a[30][30];


int main() {
	ios_base::sync_with_stdio(false);
	//read(FILENAME);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int ci = i;
			int cj = j;
			int cnt = 0;
			while (ci + 1 < n && cj - 1 >= 0) {
				ci++;
				cj--;
				cnt++;
			}
			int id = (cj == 0 ? ci: n - 1 + cj);
			if (cnt % 2 == 0) {
				a[i][j] = (1LL << id);
				cout << (1LL << id) << ' ';
			}  else {	
				cout << 0 << ' ';
			}
		}
		cout << endl;
	}
	int q;
	cin >> q;
	while (q--) {
		ll k;
		cin >> k;
		int curi = 0;
		int curj = 0;
		while (curi != n - 1 || curj != n - 1) {
			cout << curi + 1 << ' ' << curj + 1 << endl;
			if (curi + 1 >= n) {
				curj++;
				continue;
			}
			if (curj + 1 >= n) {
				curi++;
				continue;
			}
			ll val = max(a[curi][curj + 1], a[curi + 1][curj]);
			if ((k & val) == val) {
				if (a[curi][curj + 1] == val) {
					curj++;
				} else {
					curi++;
				}
			} else {
				if (a[curi][curj + 1] == val) {
					curi++;
				} else {
					curj++;
				}
			}
		}
		cout << curi + 1 << ' ' << curj + 1 << endl;
	}
}