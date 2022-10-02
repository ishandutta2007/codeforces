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

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	string yes = "Ya";
	string no = "Tidak";
	int sign = (a + b) & 1;
	if (sign) {
		int can = (a + d) > 0;
		int can1 = (b + c) > 0;
		if (can) {
			cout << yes;
		} else {
			cout << no;
		}
		cout << ' ';
		if (can1) {
			cout << yes;
		} else {
			cout << no;
		}
		cout << ' ';
		cout << no << ' ' << no;
		cout << '\n';
	} else {
		cout << no << ' ' << no << ' ';
		int can = (a + d) > 0;
		int can1 = (b + c) > 0;
		if (can1) {
			cout << yes;
		} else {
			cout << no;
		}
		cout << ' ';
		if (can) {
			cout << yes;
		} else {
			cout << no;
		}
		cout << '\n';
	}
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
}