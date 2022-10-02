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
const int MAXN = 501;



int n;
int a[MAXN];
int b[MAXN];


void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	if (n % 2 == 1) {
		if (a[n / 2] != b[n / 2]) {
			cout << "No\n";
			return;
		}
	}
	vector<int> v, v1;
	for (int i = 0; i < n; i++) {
		v.pb(a[i]);
	}
	for (int i = 0; i < n; i++) {
		v1.pb(b[i]);
	}
	sort(all(v));
	sort(all(v1));
	if (v != v1) {
		cout << "No\n";
		return;
	}
	vector<pair<int, int> > st;
	for (int i = 0; i < n / 2; i++) {
		st.pb(mp(min(a[i], a[n - i - 1]), max(a[i], a[n - i - 1])));
	}
	sort(all(st));
	vector<pair<int, int> > st1;
	for (int i = 0; i < n / 2; i++) {
		st1.pb(mp(min(b[i], b[n - i - 1]), max(b[i], b[n - i - 1])));
	}
	sort(all(st1));
	if (st != st1) {
		cout << "No\n";
		return;
	}
	cout << "Yes\n";
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
 	// map<vector<int>, int> used;
 	// used[vector<int>{1, 2, 3, 4, 5, 6}] = true;
 	// queue<vector<int> > q;
 	// q.push(vector<int>{1, 2, 3, 4, 5, 6});
 	// int cnt = 0;
 	// while (!q.empty()) {
 	// 	auto x = q.front();
 	// 	q.pop();
 	// 	cnt++;
 	// 	for (auto y: x) {
 	// 		cout << y << ' ';
 	// 	}
 	// 	cout << endl;
 	// 	swap(x[0], x[5]);
 	// 	if (used.find(x) == used.end()) {
 	// 		used[x] = true;
 	// 		q.push(x);
 			
 	// 	}
 	// 	swap(x[0], x[5]);

 	// 	swap(x[0], x[3]);
 	// 	swap(x[1], x[4]);
 	// 	swap(x[2], x[5]);
 	// 	if (used.find(x) == used.end()) {
 	// 		used[x] = true;
 	// 		q.push(x);
 	// 	}
 	// 	swap(x[0], x[3]);
 	// 	swap(x[1], x[4]);
 	// 	swap(x[2], x[5]);

 	// 	swap(x[0], x[4]);
 	// 	swap(x[1], x[5]);
 	// 	if (used.find(x) == used.end()) {
 	// 		used[x] = true;
 	// 		q.push(x);
 	// 	}
 	// }
 	// cout << cnt << endl;
 	// return 0;
 	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0; 	
}