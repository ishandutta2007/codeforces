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


using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
const string FILENAME = "input";
const int MAXN = 300228;


int n;
int x[MAXN], y[MAXN];
map<int, int> whox;
map<int, vector<int> > who;
int cnts[MAXN];
int f[MAXN];
vector<int> st;


void inc(int i) {
	for (; i < sz(st); i |= (i + 1)) {
		f[i]++;
	}
}


int get(int i) {
	int ans = 0;
	for (; i >= 0; i = (i & (i + 1)) - 1) {
		ans += f[i];
	}
	return ans;
}

int getsum(int l, int r) {
	return get(r) - (l ? get(l - 1): 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		st.pb(x[i]);
	}
	sort(all(st));
	st.resize(distance(st.begin(), unique(all(st))));
	for (int i = 0 ; i < sz(st); i++) {
		whox[st[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		x[i] = whox[x[i]];
		who[-y[i]].pb(x[i]);
	}
	long long ans = 0;
	for (auto y: who) {
		int last = -1;
		for (auto x: y.second) {
			cnts[x]++;
			if (cnts[x] == 1) {
				inc(x);
			}
		}
		sort(all(y.second));
		for (auto x: y.second) {
			int pos = 0;
			//cout << last+ 1 << ' ' << x << endl;
			int g = getsum(last + 1, x);
			int g1 = getsum(x, sz(st) - 1);
			ans += 1LL * g * g1;
			last = x;
		}
	}
	cout << ans << endl;
 	return 0;
}