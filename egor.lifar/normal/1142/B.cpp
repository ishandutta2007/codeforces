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
const string FILENAME = "input";
const int MAXN = 300228;


int n, m, q;
int p[MAXN];
int a[MAXN];
int jump[MAXN][20];
int where[MAXN];
int d[MAXN * 4];
int ss = 1;
int last[MAXN];

void change(int i, int x) {
	i += ss;
	d[i] = x;
	while (i > 0) {
		i >>= 1;
		d[i] = min(d[i * 2], d[i * 2 + 1]);
	}
}


int rmq(int l, int r) {
	l += ss;
	r += ss;
	int ans = 1e9;
	while (l <= r) {
		if (l & 1) {
			chkmin(ans, d[l]);
			l++;
		} 
		if (!(r & 1)) {
			chkmin(ans, d[r]);
			r--;
		}
		l >>= 1;
		r >>= 1;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		where[p[i]] = i; 
	}
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		last[i + 1] = m;
	}
	jump[m][0] = m;
	for (int i = m - 1; i >= 0; i--) {
		jump[i][0] = last[p[(where[a[i]] + 1) % n]];
		last[a[i]] = i;
	}
	for (int k = 1; k <= 19; k++) {
		for (int i = 0; i <= m; i++) {
			jump[i][k] = jump[jump[i][k - 1]][k - 1];
		}
	}
	while (ss < m) {
		ss <<= 1;
	}
	for (int i = 0; i < m; i++) {
		int cur = n - 1;
		int pos = i;
		for (int k = 19; k >= 0; k--) {
			if (cur >= (1 << k)) {
				cur -= (1 << k);
				pos = jump[pos][k];
			}
		}
		//cout << pos << endl;
		change(i, pos);
	}	
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >>l >> r;
		l--, r--;
		int t = rmq(l, r);
		//cout << t << endl;
		if (t <= r) {
			cout << '1';
		} else {
			cout << '0';
		}
	}
	cout << '\n';
	return 0; 	
}