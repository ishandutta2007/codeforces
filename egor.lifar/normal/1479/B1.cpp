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
const int Mod = 998244353;


int sum(int a, int b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
	return ((ll)a * b) % Mod;
}


int powm(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = mul(res, a);
		}
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}


int inv(int a) {
    return powm(a, Mod - 2);
}



const int MAXN = 100228;


int n;
int a[MAXN];
int pref[MAXN];
int dp[MAXN];
int kek[MAXN];


void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 1;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] != a[i + 1]) {
			ans++;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		if (a[i] != a[i + 1]) {
			pref[i]++;
		}
	}
	for (int i = 1; i < n; i++) {
		pref[i] += pref[i - 1];
	}
	for (int i = 0; i < n - 1; i++) {
		dp[i] = -1e9;
	}
	for (int i = 0; i <= n; i++) {
		kek[i] = -1e9;
	}
	multiset<int> s;
	for (int i = 0; i <= n; i++) {
		s.insert(kek[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		if (i) {
			chkmax(dp[i], pref[i - 1] + kek[a[i + 1]]);
			s.erase(s.find(kek[a[i + 1]]));
			if (!s.empty()) {
				chkmax(dp[i], pref[i - 1] + *s.rbegin() + 1);
			}
			s.insert(kek[a[i + 1]]);
		}
		chkmax(dp[i], (i ? pref[i - 1]: 0) + 2);
		chkmax(ans, dp[i] + pref[n - 1] - pref[i]);
		int val = a[i];
		int t = dp[i] - pref[i];
		s.erase(s.find(kek[val]));
		chkmax(kek[val], t);
		s.insert(kek[val]);
	}
	cout << ans << '\n';
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
  //   read(FILENAME);
   	int t;
   	//cin >> t;
   	t = 1;
   	while (t--) {
   		solve();
   	}
   	return 0;
}