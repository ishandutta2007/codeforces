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
const int MAXN = 500228;



int n;
int a[MAXN];
int pref[MAXN];
int pid[MAXN];


void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		pref[i] = a[i];
		pid[i] = i;
		if (i) {
			chkmin(pref[i], pref[i - 1]);
			if (pref[i] == pref[i - 1]) {
				pid[i] = pid[i - 1];
			}
		}
	}
	int x = 1e9;
	bool ok = false;
	int pk = -1;
	int si, sj, sk;
	for (int i = n - 1; i >= 1; i--) {
		if (a[i] > pref[i - 1] && a[i] > x) {
			ok = true;
			si = pid[i - 1];
			sj = i;
			sk = pk;
		}
		chkmin(x, a[i]);
		if (x == a[i]) {
			pk = i;
		}
	}
	if (ok) {
		cout << "Yes\n";
		cout << si + 1 << ' ' << sj + 1 << ' ' << sk + 1 << '\n';
	} else {
		cout << "No\n";
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