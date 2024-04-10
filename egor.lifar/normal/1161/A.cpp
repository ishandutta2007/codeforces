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
#define rank rank228
const string FILENAME = "input";
const int MAXN = 100228;


int n, k;
int x[MAXN];
bool used[MAXN];
vector<int> g[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> x[i];
		used[x[i]] = true;
		g[x[i]].pb(i);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			ans++;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i - 1; j <= i + 1; j++) {
			if (j < 1 || j > n || j == i) {
				continue;
			}
			if (g[i].empty()) {
				ans++;
			} else {
				int f = g[i][0];
				if (g[j].empty()) {
					ans++;
				} else {
					int s = lower_bound(all(g[j]), f) - g[j].begin();
					if (s == sz(g[j])) {
						ans++;
					}
				}
			}
		}
	}
	cout << ans << '\n';
	return 0; 	
}