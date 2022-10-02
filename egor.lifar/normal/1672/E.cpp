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
template<typename T1, typename T2> inline bool chkmin(T1 &a, T2 b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<typename T1, typename T2> inline bool chkmax(T1 &a, T2 b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
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


int n;
int l[2005];
int tk = 0;
 
 
int query(int a) {
	tk++;
	assert(tk <= n + 30);
	cout << "? " << a << endl;
	int ans = 0;
	cin >> ans;
	// for (int i = 0; i < n; i++) {
	// 	if (l[i] > a) {
	// 		return n + 1;
	// 	}
	// }
	// int cur = 0;
	// int cnt = 0;
	// ans = 1;
	// for (int i = 0; i < n; i++) {
	// 	if (cur + l[i] + (cnt > 0) <= a) {
	// 		cur += l[i] + (cnt > 0);
	// 		cnt++;
	// 	} else{
	// 		cur = l[i];
	// 		cnt = 1;
	// 		ans++;
	// 	}
	// }
	return ans;
}


void ans(int area) {
	// int resarea = 1e9;
	// for (int i = 1; i <= n; i++) {
	// 	int ls = 1;
	// 	int rs = 4003000;
	// 	while (ls < rs) {
	// 		int mid = (ls + rs) >> 1;
	// 		if (query(mid) > i) {
	// 			ls = mid + 1;
	// 		} else {
	// 			rs = mid;
	// 		}
	// 	}
	// 	chkmin(resarea, ls * query(ls));
	// }
	// cerr << area << ' ' << resarea << endl;
	//assert(area == resarea);
	cout << "! " << area << endl;
}




void solve() {
	cin >> n;
	// n = 2000;
	// l[0] = 5;
	// l[1] = 2;
	// l[2] = 7;
	// l[3] = 3;
	// l[4] = 5;
	// l[5] = 6;
	int ls = 1;
	int rs = 2000 * 2001;
	while (ls < rs) {
		int mid = (ls + rs) >> 1;
		if (query(mid) != 1) {
			ls = mid + 1;
		} else {
			rs = mid;
		}
	}
	int res = ls;
	for (int i = 2; i <= n; i++) {
		int t = (res - 1) / i;
		if (t <= 0) {
			break;
		}
		int f = query(t);
		if (1 <= f) {
			chkmin(res, t * f);
		}
	}
	ans(res);
	//cerr << tk << endl;
}		


int main(){
	//cin.tie(0)->sync_with_stdio(0);
	ios_base::sync_with_stdio(0);
	int t;
	t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}