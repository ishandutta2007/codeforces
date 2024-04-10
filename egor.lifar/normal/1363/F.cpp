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
const int MAXN = 2008;


string s, t;
int suff[26][MAXN], suff1[26][MAXN];
int dp[MAXN][MAXN];
 

int calc(int i, int j) {
	if (j == 0) {
		return 0;
	}
	int &ans = dp[i][j];
	if (ans != -1) {
		return ans;
	}
	ans = 1e9;
	if (i > 0) {
		ans = 1 + calc(i - 1, j);
		if (s[i - 1] == t[j - 1]) {
			chkmin(ans, calc(i - 1, j - 1));
		}
	}
	int c = t[j - 1] - 'a';
	if (suff[c][i + 1] - suff1[c][j + 1] > 0) {
		chkmin(ans, calc(i, j - 1));
	}
	return ans;
}


void solve() {
	int n;
	cin >> n;
	cin >> s >> t;
	vector<char> vs, vt;
	for (int i = 0; i < sz(s); i++) {
		vs.pb(s[i]);
	}	
	sort(all(vs));
	for (int i = 0; i < sz(t); i++) {
		vt.pb(t[i]);
	}	
	sort(all(vt));
	if (vs != vt) {
		cout << -1 << '\n';
		return;
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = -1;
		}
	}
	for (int i = 0; i <= 25; i++) {
		for (int j = 0; j <= n + 1; j++) {
			suff[i][j] = suff1[i][j] = 0;
		}
	}
	for (int i = n; i >= 1; i--) {
		for(int j = 0; j < 26; j++) {
			suff[j][i] = suff[j][i + 1];
			suff1[j][i] = suff1[j][i + 1];
		}
		suff[s[i - 1] - 'a'][i]++;
		suff1[t[i - 1] - 'a'][i]++;
	}
	int ans = calc(n, n);
	cout << ans << endl;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0; 	
}