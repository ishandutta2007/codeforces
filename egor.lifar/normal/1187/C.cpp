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
const int MAXN = 1002;


int n, m;
int a[MAXN];
int g[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> m;
	vector<pair<int, int> > kt;
	for (int i = 0; i < m; i++) {
		int t, l, r;
		cin >> t >> l >> r;
		if (t == 1) {
			g[l]++;
			g[r]--;
		} else {
			kt.pb({l, r});
		}
	}
	int fk = 3000000;
	int cur = 0;
	vector<int> st;
	for (int i = 1; i <= n; i++) {
		cur += g[i];
		fk++;
		st.pb(fk);
		//cout << fk << endl;
		if (cur == 0) {
			fk -= 2000;
		}
	}
	for (auto y: kt) {
		bool was = false;
		for (int j = y.first - 1; j < y.second - 1; j++) {
			if (st[j] > st[j + 1]) {
				was = true;
			}
		}
		if (!was) {
			cout << "NO\n";
			exit(0);
		}
	}
	cout << "YES\n";
	for (auto x: st) {
		cout << x << ' ';
	}
	cout << '\n';
	return 0; 		
}