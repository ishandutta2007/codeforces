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



mt19937 as;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
 	as.seed(time(NULL));
 	int n;
	cin >> n;
	vector<bool> kek(n);
	int cc = 0;
	int sq = 1;
	while (sq * sq < n) {
		sq++;
	}
	vector<int> ord;
	int cur = 0;
	vector<bool> used(n);
	for (int i = 0; i < n; i++) {
		ord.pb(cur);
		used[cur] = true;
		cur += sq;
		if (cur >= n) {
			cur -= n;
		}
		while (used[cur]) {
			cur++;
		}
	}
	for (int it = 0; it < 9999; it++) {
		int cnt = 0;
		vector<int> v;
		for (auto x: ord) {
			if (!kek[x]) {
				v.pb(x);
				cnt++;
				if (cnt == sq) {
					break;
				}
			}
		}
		cout << sq << ' ';
		for (auto x: v) {
			cout << x + 1 << ' ';
			kek[x] = true;
		}
		cout << endl;
		int x;
		cin >> x;
		x--;
		for (int i = 0; i < sq; i++) {
			int y = x + i;
			if (y >= n) {
				y -= n;
			}
			kek[y] = false;
		}
	}
	cout << 0 << endl;
	return 0;	 	
}