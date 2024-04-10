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
const int MAXN = 300229;


int n;
int a[MAXN];
int mask[MAXN];
int t[MAXN];
ll cnt[30][2];
int nxt[MAXN * 31][2];
int ukt = 0;
int cntr[MAXN * 31][2];


void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	memset(cnt, 0, sizeof(cnt));
	ukt = 1;
	for (int i = 0; i < n; i++) {
		int cur = 0;
		for (int j = 29; j >= 0; j--) {
			int c = 0;
			if (a[i] & (1 << j)) {
				c = 1;
			} else {
				c = 0;
			}	
			if (c == 1) {
				cnt[j][1] += cntr[cur][0];
			} else {
				cnt[j][0] += cntr[cur][1];
			}
			cntr[cur][c]++;
			if (nxt[cur][c]) {
				cur = nxt[cur][c];
			} else {
				ukt++;
				nxt[cur][c] = ukt;
				cur = ukt;
			}
		}
	}
	ll res = 0;
	ll ans = 0;
	for (int j = 29; j >= 0; j--) {
		if (cnt[j][0] <= cnt[j][1]) {
			ans += cnt[j][0];
		} else {
			ans += cnt[j][1];
			res |= (1 << j);
		}
	}
	cout << ans << ' ' << res << '\n';
	for (int i = 0; i <= ukt; i++) {
		nxt[i][0] = nxt[i][1] = 0;
		cntr[i][0] = cntr[i][1] = 0;
	}
	ukt = 0;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	read(FILENAME);
	int t;
	t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}