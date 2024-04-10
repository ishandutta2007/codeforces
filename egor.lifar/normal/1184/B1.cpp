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
#define mp make_pair
const string FILENAME = "input";
const int MAXN = 100228;


int s, b;
int a[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> s >> b;
	for (int i = 0; i < s; i++) {
		cin >> a[i];
	}
	vector<pair<int, long long> > st;
	for (int i = 0; i < b; i++) {
		int d, g;
		cin >> d >> g;
		st.pb({d, g});
	}
	sort(all(st));
	for (int i = 1; i < b; i++) {
		st[i].second += st[i - 1].second;
	}
	for (int i = 0; i < s; i++) {
		int pos = lower_bound(all(st), mp(a[i] + 1, 0LL)) - st.begin();
		if (pos) {
			cout << st[pos - 1].second << '\n';
		} else {
			cout << 0 << '\n';
		}
	}
	return 0;
}