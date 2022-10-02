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
const int MAXN = 300228;


int q;
int n;
int a[MAXN], b[MAXN];
int cnt[MAXN];
vector<int> pos[MAXN];
int where[MAXN];
int d[MAXN];


void inc(int i, int val) {
	for (; i <= n; i |= (i + 1)) {
		chkmax(d[i], val);
	}
}  


int getmax(int i) {
	int res = 0;
	for (; i >= 0; i = (i & (i + 1)) - 1) {
		chkmax(res, d[i]);
	}
	return res;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> q;
	for (int it = 0; it < q; it++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cnt[i] = 0;
			pos[i].clear();
			d[i] = 0;
		}
		d[0] = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			cnt[a[i]]++;
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			cnt[b[i]]--;
			pos[b[i]].pb(i);
		}
		bool bad = false;
		for (int i = 1; i <= n; i++) {
			if (cnt[i] != 0) {
				bad = true;
			}
		}
		if (bad) {
			cout << "NO\n";
			continue;
		}
		for (int i = n - 1; i >= 0; i--) {
			where[i] = pos[a[i]].back();
			pos[a[i]].pop_back();
		}
		for (int i = 0; i < n; i++) {
			inc(a[i], where[i]);
			if (getmax(a[i] - 1) > where[i]) {
				bad = true;
			}
		}
		if (bad) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
	}
	return 0; 		
}