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
template<class T1, class T2> inline void chkmin(T1 &x, const T2 &y) {if (x > y) x = y;}
template<class T1, class T2> inline void chkmax(T1 &x, const T2 &y) {if (x < y) x = y;}
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define mp make_pair
#define pb push_back
#define read(FILENAME) freopen((string(FILENAME) + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((string(FILENAME) + ".out").c_str(), "w", stdout);
const int MAXN = 500228;



int n, m;
int l[MAXN], r[MAXN];
int x[MAXN], y[MAXN];
int jump[MAXN][20];
vector<int> st[MAXN];
vector<int> en[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read("input");
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		st[l[i]].pb(r[i]);
		en[r[i]].pb(r[i]);
	}
	for (int i = 0; i < m; i++) {
		cin >> x[i] >> y[i];
 	}
 	multiset<int> cur;
 	for (int i = 0; i < MAXN; i++) {
 		for (auto x: st[i]) {
 			cur.insert(x);
 		}
 		if (!cur.empty()) {
 			jump[i][0] = *cur.rbegin();
 		} else {
 			jump[i][0] = i;
 		}
 		for (auto x: en[i]) {
 			cur.erase(cur.find(x));
 		}
	}
	for (int k = 1; k <= 19; k++) {
		for (int i = 0; i < MAXN; i++) {
			jump[i][k] = jump[jump[i][k - 1]][k - 1];
		}
	}
 	for (int i = 0; i < m; i++) {
 		int cur = x[i];
 		int ans = 0;
 		for (int k = 19; k >= 0; k--) {
 			if (jump[cur][k] < y[i]) {
 				cur = jump[cur][k];
 				ans += 1 << k;
 			}  
 		}
 		if (jump[cur][0] >= y[i]) {
 			ans++;
 			cout << ans << '\n';
 		} else {
 			cout << -1 << '\n';
 		}
  	}	
}