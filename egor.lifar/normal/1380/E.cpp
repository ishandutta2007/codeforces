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
const int MAXN = 200228;


int n, m;
set<int> kek[MAXN];
int cnt[MAXN];
int sum = 0;



void add(int i, int val) {
	auto x = kek[i].lower_bound(val);
	bool was = false, was1 = false;
	if (x != kek[i].end() && *x == val + 1) {
		was = true;
	}
	if (x != kek[i].begin()) {
		x--;
		if (*x == val - 1) {
			was1 = true;
		}
	}
	kek[i].insert(val);
	if (was && was1) {
		cnt[i]--;
		sum--;
	} else if (!was && !was1) {
		cnt[i]++;
		sum++;
	} 
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		add(t, i);
	}
	cout << sum - 1 << '\n';
	for (int i = 0; i < m - 1; i++) {
		int a, b;
		cin >> a >> b;
		if (sz(kek[a]) < sz(kek[b])) {
			swap(kek[a], kek[b]);
			swap(cnt[a], cnt[b]);
		}
		sum -= cnt[b];
		for (auto x: kek[b]) {
			add(a, x);
		}
		kek[b].clear();
		cnt[b] = 0;
		cout << sum - 1 << '\n';
	}
}