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
const int Mod = 1000000007;


int sum(int a, int b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
	return (ll)a * b % Mod;
}


const int MAXN = 100228;


int pref[MAXN];
int mda[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	string s;
	cin >> s;
	pref[0] = 1;
	mda[0] = 1;
	for (int i = 1; i < sz(s); i++) {
		pref[i] = mul(pref[i - 1], 10);
		mda[i] = pref[i];
	}
	for (int i = 1; i < sz(s); i++) {
		pref[i] = sum(pref[i], pref[i - 1]);
	}
	int cur = 0;
	int ans = 0;
	for (int i = 0; i < sz(s) - 1; i++) {
		cur = mul(cur, 10);
		cur = sum(cur, s[i] - '0');
		ans = sum(ans, mul(cur, pref[sz(s) - i - 2]));
	}
	cur = 0;
	for (int i = sz(s) - 1; i >= 1; i--) {
		cur = sum(cur, mul(s[i] - '0', mda[sz(s) - i - 1]));
		ans = sum(ans, mul(cur, i));
	}
	cout << ans << '\n';
}