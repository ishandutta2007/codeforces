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
const int MAXN = 2001;
const int Mod = 998244353;



int sum(int a, int b) {
	return (a + b) % Mod;
}

vector<int> g[MAXN];
vector<int> ct[MAXN];
bool used[MAXN];
int who[MAXN];
int ft[MAXN];
int where[MAXN];


void dfs(int u, int c) {
	used[u] = true;
	who[u] = c;
	for (auto x: g[u]) {
		if (!used[x]) {
			dfs(x, c);
		}
	}
}

int ff;
void dfs1(int u, int c) {
	used[u] = true;
	ft[u] = c;
	where[u] = ff;
	for (auto x: ct[u]) {
		if (!used[x]) {
			dfs1(x, c ^ 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
	string s;
	cin >> s;
	int ans = 0;
	for (int pos = 1; pos < sz(s); pos++) {
		for (int i = 0; i <= sz(s) * 2 + 2; i++) {
			g[i].clear();
			used[i] = false;
			ct[i].clear();
		}
		for (int i = 0; i < sz(s); i++) {
			if (sz(s) - i - 1 <= i) {
				continue;
			}
			g[i].pb(sz(s) - i - 1);
			g[sz(s) - i - 1].pb(i);
		}
		for (int i = pos; i < sz(s); i++) {
			if (sz(s) - (i  - pos) - 1 <= i) {
				continue;
			}
			g[i + sz(s)].pb(sz(s) + sz(s) - (i  - pos) - 1);
			g[sz(s) + sz(s) - (i - pos) - 1].pb(i + sz(s));
		}
		for (int i = 0; i < sz(s); i++) {
			if (s[i] != '?') {
				if (s[i] == '0') {
					if (i < pos) {
					} else {		
						g[i].pb(i + sz(s));
						g[i + sz(s)].pb(i);
					}
				}  else {
					if (i < pos) {
						g[0].pb(i);
						g[i].pb(0);
					}
				}
			}
		}
		int c = 0;
		for (int i = 0; i < 2 * sz(s); i++) {
			if (i >= sz(s) && i - sz(s) < pos) {
				continue;
			}
			if (!used[i]) {
				c++;
				dfs(i, c);
			}
		}
		bool bad = false;
		for (int i = 0; i < sz(s); i++) {
			if (s[i] == '1') {
				if (i < pos) {
					continue;
				}
				if (who[i] == who[sz(s) + i]) {
					bad = true;
					break;
				}
				ct[who[i]].pb(who[sz(s) + i]);
				ct[who[sz(s) + i]].pb(who[i]);
			} else if (s[i] == '0') {
				if (i < pos) {
					ct[who[0]].pb(who[i]);
					ct[who[i]].pb(who[0]);
				}
			}
		}
		//cout << bad << ' ' << pos << endl;
		for (int i = 1; i <= c; i++) {
			used[i] = false;
		}
		int kek = 0;
		ff = 0;
		for (int i = 1; i <= c; i++) {
			if (!used[i]) {
				ff++;
				dfs1(i, 1);
				kek++;
			}
		}
		for (int i = 1; i <= c; i++) {
			for (auto x: ct[i]) {
				//cout << i << ' ' << x << endl;
				if (ft[x] == ft[i] && where[x] == where[i]) {
					bad = true;
				}
			}
		}
		//cout << bad << ' ' << pos << endl;
		if (!bad) {
			//cout << ft[who[0]] << ' ' << ft[who[pos + sz(s)]] << endl;
			if (where[who[0]] == where[who[pos + sz(s)]]) {
				if (ft[who[0]] != ft[who[pos + sz(s)]]) {
				//	cout << ft[who[0]] << ' ' << ft[who[pos + sz(s)]] << endl;
					continue;
				}
			}
			//cout << "opa" << endl;
			int res = 1;
			if (where[who[0]] == where[who[pos + sz(s)]]) {
				kek--;
			} else {
				kek -= 2;
			}
			for (int i = 0; i < kek; i++) {
				res = sum(res, res);
			}
			ans = sum(ans, res);
		}
	}
	cout << ans << '\n';
	return 0; 	
}