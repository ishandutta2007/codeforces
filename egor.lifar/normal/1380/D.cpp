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
const int MAXN = 200228;




int n, m;
int x, y, k;
int a[MAXN], b[MAXN];
bool need[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> m;
	cin >> x >> k >> y;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	int uk = 0;
	vector<int> st;
	for (int i = 0; i < m; i++) {
		while (uk < n && a[uk] != b[i]) {
			uk++;
		}
		if (a[uk] != b[i]) {
			cout << -1 << '\n';
			return 0;
		}
		st.pb(uk);
		uk++;
	}
	ll ans = 0;
	for (int i = 0; i <= sz(st); i++) {
		int fa = 0;
		if (i != sz(st)) {
			chkmax(fa, a[st[i]]);
		}
		if (i) {
			chkmax(fa, a[st[i - 1]]);
		}
		int l = (i ? st[i - 1] + 1: 0);
		int r = (i != sz(st) ? st[i] - 1: n - 1);
		if (l > r) {
			continue;
		}
		int cnt = 0;
		for (int i = l; i <= r; i++) {
			if (a[i] > fa) {
				need[i] = true;
				cnt++;
			}
		}
		int f = (r - l + 1);
		int cnts = cnt;
		if (cnt % k != 0) {
			cnt += k - cnt % k;
		}
		ll add = 1e18;
		for (int i = cnt; i <= f; i += k) {
			chkmin(add, (ll)i / k * x + (ll)(f - i) * y);
		}
		for (int i = cnt - k; i >= k; i-= k) {
			chkmin(add, (ll)i / k * x + (ll)(f - i) * y);
		}
		if (add > 1e17) {
			cout << -1 << '\n';
			exit(0);
		}
		ans += add;
	}
	cout << ans << '\n';
}