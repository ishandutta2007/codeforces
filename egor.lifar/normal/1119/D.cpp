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
const int MAXN = 100228;


int n;
long long s[MAXN];
long long ans[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	sort(s, s + n);
	int q;
	cin >> q;
	vector<pair<long long, int> > kek;
	for (int i = 0; i < q; i++) {
		long long l, r;
		cin >> l >> r;
		r -= l;
		kek.pb({r, i});
	}
	sort(all(kek));
	long long cur = 0;
	int cnt = n;
	vector<pair<long long, int> > g;
	for (int i = 0; i < n - 1; i++) {
		g.pb({s[i + 1] - s[i], i});
	}
	sort(all(g));
	int uk = 0;
	long long add = 0;
 	for (auto x: kek) {
 		while (uk < sz(g) && g[uk].first <= x.first) {
 			cnt--;
 			add += g[uk].first;
 			uk++;
 		}
 		ans[x.second] = add + 1LL * cnt * (x.first + 1);
	}
	for (int i = 0; i < q; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0; 	
}