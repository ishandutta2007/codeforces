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
const int MAXN = 1000228;
const int Mod = 1000000007;



int sum(int a, int b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}

int mul(int a, int b) {
	return ((ll)a * b) % Mod;
}


string s;
int dp[MAXN];
int nxt[MAXN][2];
int dp1[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	read(FILENAME);
	cin >> s;
	nxt[sz(s)][0] = sz(s);
	nxt[sz(s)][1] = sz(s);
	for (int i = sz(s) - 1; i >= 0; i--) {
		nxt[i][0] = nxt[i + 1][0];
		nxt[i][1] = nxt[i + 1][1];
		nxt[i][s[i] - '0'] = i;
	}
	int last = sz(s);
	int tot = 0;
	int rem = 0;
	for (int i = sz(s) - 1; i >= 0; i--) {
		if (s[i] == '1') {
			if (last < sz(s)) {
				for (int j = 1; j < last - i; j++) {
					tot = sum(tot, Mod - dp1[j]);
					dp1[j] = dp[last];
					tot = sum(tot, dp1[j]);
				}
			} else {
				rem = last - i;
			}
			dp[i] = dp[nxt[i + 1][1]];
			dp[i] = sum(dp[i], tot);
			dp[i] = sum(dp[i], rem);
			last = i;
		}
	}
	int uk = 0;
	while (s[uk] == '0' && uk < sz(s)) {
		uk++;
	}
	if (uk == sz(s)) {
		cout << uk << '\n';
		return 0;
	}
	cout << mul(dp[last], uk + 1) << '\n';
}