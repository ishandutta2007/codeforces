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
const int MAXN = 5005;



int n;
int p[MAXN];
int cnt[MAXN];
int cnt1[MAXN];
int pref[MAXN];



void inc(int i) {
	for (; i <= n; i |= (i + 1)) {
		cnt1[i]++;
	}
}


int get(int i) {
	int ans = 0;
	for (; i >= 0; i= (i & (i + 1)) - 1) {
		ans += cnt1[i];
	}
	return ans;
}


void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	for (int i = 0; i <= n; i++) {
		cnt[i] = 0;
		pref[i] = 0;
	}
	ll ans = 0;
	for (int b = 0; b < n; b++) {
		for (int i = 0; i <= n; i++) {
			cnt1[i] = 0;
		}
		for (int c = n - 1; c >= b + 1; c--) {
			ans += pref[p[c]] * get(p[b]);
			inc(p[c]);
		}
		cnt[p[b]]++;
		for (int i = 0; i <= n; i++) {
			pref[i] = cnt[i];
			if (i) {
				pref[i] += pref[i - 1];
			}
		}
	}
	cout << ans << '\n';
}


int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;
	t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}