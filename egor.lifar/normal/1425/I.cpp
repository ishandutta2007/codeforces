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
const int MAXN = 50228;
const int BLOCK = 230;


int n, q;
int a[MAXN];
vector<int> g[MAXN];
int timer = 0;
int in[MAXN], out[MAXN];
int deep[MAXN];
vector<int> alive[MAXN * 2];
set<int> s[11];
int who[MAXN];
vector<int> smalls[11][BLOCK + 5];
vector<pair<pair<int, int>, int> > aliveBIG[MAXN * 2][11];
set<pair<int, int> > cur[11][BLOCK + 5];



void dfs(int u) {
	timer++;
	who[timer] = u;
	in[u] = timer;
	for (auto h: g[u]) {
		deep[h] = deep[u] + 1;
		dfs(h);
	}
	out[u] = timer;
}


vector<int> extract(set<int> &s, int l, int r) {
	auto it = s.lower_bound(l);
	vector<int> res;
	while (it != s.end()) {
		if (*it > r) {
			break;
		}
		res.pb(*it);
		it++;
	}
	return res;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		int p;
		cin >> p;
		p--;
		g[p].pb(i);
	}
	dfs(0);
	for (int i = 0; i < n; i++) {
		if (a[i] <= BLOCK) {
			smalls[deep[i]][a[i]].pb(in[i]);
		} else {
			alive[0].pb(i);
		}
	}
	for (int i = 0; i <= 10; i++) {
		for (int j = 1; j <= BLOCK; j++) {
			sort(all(smalls[i][j]));
			if (!smalls[i][j].empty()) {
				aliveBIG[0][i].pb(mp(mp(0, sz(smalls[i][j]) - 1), j));
			}
		}
	}
	for (int it = 0; it < q; it++) {
		for (auto y: alive[it]) {
			s[deep[y]].insert(in[y]);
		}
		int x;
		cin >> x;
		x--;
		int sum = 0;
		int cnt = 0;
		int l = in[x];
		int r = out[x];
		for (int i = 0; i <= 10; i++) {
			for (auto x: aliveBIG[it][i]) {
				cur[i][x.second].insert(x.first);
			}
		}
		for (int i = deep[x]; i <= 10; i++) {
			int cnt1 = 0;
			{
				//deal with bigger than BLOCK
		
				auto d = extract(s[i], l, r);
				for (auto x: d) {
					cnt1++;
					s[i].erase(x);
					int id = who[x];
					alive[it + a[id]].pb(id);
				}
			}
			{
				for (int j = 1; j <= BLOCK; j++) {
					if (!cur[i][j].empty()) {
						int lx = lower_bound(all(smalls[i][j]), l) - smalls[i][j].begin();
						int rx = lower_bound(all(smalls[i][j]), r + 1) - smalls[i][j].begin() - 1;
						if (lx <= rx) {
							auto itr = cur[i][j].lower_bound(mp(lx, 0));
							if (itr != cur[i][j].begin()) {
								itr--;
							}
							vector<pair<int, int> > d;
							while (itr != cur[i][j].end()) {
								if (itr->first > rx) {
									break;
								}
								if (itr->second >= lx) {
									d.pb(*itr);
								}
								itr++;
							}
							vector<pair<int, int> > st;
							for (auto x: d) {
								cur[i][j].erase(x);
								int fl = max(x.first, lx);
								int fr = min(x.second, rx);
								cnt1 += fr - fl + 1;
								if (x.first < fl) {
									cur[i][j].insert(mp(x.first, fl - 1));
								}
								if (fr < x.second) {
									cur[i][j].insert(mp(fr + 1, x.second));
								}
								if (st.empty() || st.back().second != fl - 1) {
									st.pb(mp(fl, fr));
								} else {
									st.back().second = fr;
								}
							}
							for (auto x: st) {
								aliveBIG[it + j][i].pb(mp(x, j));
							}
						}
					}
				}
			}
			cnt += cnt1;
			sum += (i - deep[x]) * cnt1;
		}
		cout << sum << ' ' << cnt << '\n';
	}
}