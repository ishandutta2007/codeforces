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
const int MAXN = 100228;




int n, L;
int a[MAXN];


void solve() {
	cin >> n >> L;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	double l = 0;
	double r = L;
	int i = 0;
	int j = n - 1;
	double ans = 0;
	double cur = 0;
	double lspeed = 1, rspeed = 1;
	while (true) {
		if (abs(r - l) < 1e-9) {
			break;
		}
		//cout << l << ' ' << r << endl; 
		while (i < n && a[i] <= l + 1e-9) {
			i++;
		}
		while (j >= 0 && a[j] >= r - 1e-9) {
			j--;
		}
		if (j < 0 || a[j] <= l + 1e-9) {
			if (i >= n || a[i] >= r - 1e-9) {
				ans += (r - l) / (lspeed + rspeed);
				break;
			}
		}
		double f = (a[i] - l) / (lspeed);
		double f1 = (r - a[j]) / (rspeed);
		if (abs(f - f1) < 1e-9) {
			ans += f;
			l += f * lspeed;
			r -= f * rspeed;
			lspeed++;
			rspeed++;
			continue;
		}
		if (f < f1) {
			ans += f;
			l += f * lspeed;
			r -= f * rspeed;
			lspeed++;
		} else {
			ans += f1;
			l += f1 * lspeed;
			r -= f1 * rspeed;
			rspeed++;
		}
	}
	cout.precision(10);
	cout << fixed << ans << endl;
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