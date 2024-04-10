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
using ll = long long;
const string FILENAME = "input";
const int MAXN = 7028;


int n;
ll a[MAXN];
ll b[MAXN];
int cnt[MAXN];
vector<int> g[MAXN];
bool on[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
 	cin >> n;
 	for (int i = 0; i < n; i++) {
 		cin >> a[i];
 		on[i] = true;
 	}
 	ll res = 0;
 	for (int i = 0; i < n; i++) {
 		cin >> b[i];
 		res += b[i];
 	}
 	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i] ^ (a[i] & a[j])) {
				cnt[i]++;
				g[j].pb(i);
			}
		}
 	}
 	int cur = n;
 	while (cur >= 2) {
 		pair<int, int> x = mp(-1, -1);
 		for (int i = 0; i < n; i++) {
 			if (!on[i]) continue;
 			if (x.first < cnt[i]) {
 				x.first = cnt[i];
 				x.second = i;
 			}
 		}
 		if (x.first < cur - 1) {
 			break;
 		}
 		res -= b[x.second];
 		cur--;
 		on[x.second] = false;
 		for (auto y: g[x.second]) {
 			if (on[y]) {
 				cnt[y]--;
 			}
 		}
 	}
 	if (cur == 1) {
 		res = 0;
 	}
 	cout << res << '\n';
	return 0; 	
}