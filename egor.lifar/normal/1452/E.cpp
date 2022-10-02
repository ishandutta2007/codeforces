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
const int MAXN = 2008;



int n, m, k;
int l[MAXN], r[MAXN];
int val[MAXN][MAXN];
vector<pair<pair<int, int>, int> > kek[MAXN];
int add[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> l[i] >> r[i];
		l[i]--;
		r[i]--;
	}
	for (int i = 0; i < m; i++) {
		vector<pair<pair<int, int>, int> > st;
		for (int t = 0; t <= n - k; t++) {
			int f = max(l[i], t);
			int f1 = min(t + k - 1, r[i]);
			val[i][t] = max(f1 - f + 1, 0);
		}
		for (int t = 1; t <= n - k; t++) {
			int diff = val[i][t] - val[i][t - 1];
			if (st.empty() || st.back().second != diff) {
				st.pb(mp(mp(t, t), diff));
			} else {
				st.back().first.second = t;
			}
		}
		kek[i] = st;
	}
	int ans = 0;
	for (int i = 0; i <= n - k; i++) {
		int base = 0;
		for (int j = 0; j < m; j++) {
			int f = max(l[j], i);
			int f1 = min(i + k - 1, r[j]);
			base += max(f1 - f + 1, 0);
		}
		chkmax(ans, base);
		memset(add, 0, sizeof(add));
		for (int j = 0; j < m; j++) {
			int f = max(l[j], i);
			int f1 = min(i + k - 1, r[j]);
			int tp = max(f1 - f + 1, 0);
			for (auto x: kek[j]) {
				int dl = max(x.first.first, i + 1);
				int dr = x.first.second;
				if (dl > dr) {
					continue;
				}
				if (val[j][dr] >= tp) {

				} else {
					if (val[j][dl] < tp) {
						continue;
					}
					dr = dl + (val[j][dl] - tp);
				}	
				add[dl] += x.second;
				add[dr + 1] -= x.second;
			}
		}
		int cur = 0;
		for (int j = i + 1; j <= n - k; j++) {
			cur += add[j];
			base += cur;
			chkmax(ans, base);
		}
	}
	cout << ans << '\n';
}