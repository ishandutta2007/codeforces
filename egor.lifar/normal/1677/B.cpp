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
const int MAXN = 1000228;


int n, m;
string s;
int pref[MAXN];
int cnt[MAXN];
int dp[MAXN];


void solve() {
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < n * m; i++) {
		cnt[i] = 0;
		dp[i] = 0;
	}
	int add = 0;
	for (int i = 0; i < n * m; i++) {
		pref[i] = (s[i] - '0');
		if (i) {
			pref[i] += pref[i - 1];
		}
		cnt[i % m] += (s[i] - '0');
		if (s[i] == '1' && cnt[i % m] == 1) {
			add++;
		}
		dp[i] = (i >= m ? dp[i - m]: 0) + (pref[i] - (i >= m ? pref[i - m]: 0) >= 1);
		cout << dp[i] + add << ' ';
	}
	cout << '\n';
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