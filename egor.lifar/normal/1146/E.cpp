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


int n, q;
int a[MAXN];
int nxt[MAXN];
pair<int, int> p[MAXN];
int uk = 0;
int mod[MAXN];
vector<pair<int, int> > g;
int cnt = 0;

void proceed(int &id, int x, char c) {
	if (mod[id] == -1) {
		if (c == '<') {
			if (-g[p[id].second].first >= x) {
				return;
			}
			if (-g[p[id].first].first < x) {
				mod[id] *= -1;
				return;
			}
			int l = p[id].first;
			int r = p[id].second;
			while (l < r) {
				int mid = (l + r) >> 1;
				if (g[mid].first * mod[id] < x) {
					r = mid;
				} else {
					l = mid + 1;
				}
			}
			int i = l;
				int val = g[i].first * mod[id];
				if (val < x) {
					uk++;
					p[uk].first = i;
					p[uk].second = p[id].second;
					mod[uk] = mod[id];
					cnt++;
					p[id].second = i - 1;
					int ft = nxt[id];
					nxt[id] = uk;
					nxt[uk] = ft;
					mod[uk] *= -1;
					id = uk;
					
				}
		} else {
			if (-g[p[id].first].first <= x) {
				return;
			}
			if (-g[p[id].second].first > x) {
				mod[id] *= -1;
				return;
			}
			int l = p[id].first;
			int r = p[id].second;
			while (l < r) {
				int mid = (l + r) >> 1;
				if (g[mid].first * mod[id] <= x) {
					r = mid;
				} else {
					l = mid + 1;
				}
			}
			int i = l;
				int val = g[i].first * mod[id];
				if (val <= x) {
					uk++;
					p[uk].first = i;
					p[uk].second = p[id].second;
					mod[uk] = mod[id];
					cnt++;
					p[id].second = i - 1;
					int ft = nxt[id];
					nxt[id] = uk;
					nxt[uk] = ft;
					mod[id] *= -1;
					id = uk;
					
				}
	

		}	
	} else {
		if (c == '<') {
			if (g[p[id].first].first >= x) {
				return;
			}
			if (g[p[id].second].first < x) {
				mod[id] *= -1;
				return;
			}
			int l = p[id].first;
			int r = p[id].second;
			while (l < r) {
				int mid = (l + r) >> 1;
				if (g[mid].first * mod[id] >= x) {
					r = mid;
				} else {
					l = mid + 1;
				}
			}
			int i = l;
				int val = g[i].first * mod[id];
				if (val >= x) {
					uk++;
					p[uk].first = i;
					p[uk].second = p[id].second;
					mod[uk] = mod[id];
					cnt++;
					p[id].second = i - 1;
					int ft = nxt[id];
					nxt[id] = uk;
					nxt[uk] = ft;
					mod[id] *= -1;
					id = uk;
					
				}
		
		} else {
			if (g[p[id].second].first <= x) {
				return;
			}
			if (g[p[id].first].first > x) {
				mod[id] *= -1;
				return;
			}
			int l = p[id].first;
			int r = p[id].second;
			while (l < r) {
				int mid = (l + r) >> 1;
				if (g[mid].first * mod[id] > x) {
					r = mid;
				} else {
					l = mid + 1;
				}
			}
			int i = l;
				int val = g[i].first * mod[id];
				if (val > x) {
					uk++;
					p[uk].first = i;
					p[uk].second = p[id].second;
					mod[uk] = mod[id];
					cnt++;
					p[id].second = i - 1;
					int ft = nxt[id];
					nxt[id] = uk;
					nxt[uk] = ft;
					mod[uk] *= -1;
					id = uk;
					
				}
			
		}
	}
}


void recalc() {
	int cur = 1;
	while (cur != -1) {
		if (mod[cur] == -1) {
			for (int i = p[cur].first; i <= p[cur].second; i++) {
				g[i].first *= -1;
			}
		}
		cur = nxt[cur];
	}
	sort(all(g));
	uk = 1;
	p[uk] = {0, sz(g) - 1};
	nxt[uk] = -1;
	mod[uk] = 1;
	cnt = 1;
}


unordered_map<int, int> ans;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		g.pb({a[i], a[i]});
	}
	sort(all(g));
	g.resize(distance(g.begin(), unique(all(g))));
	uk++;
	p[uk] = {0, sz(g) - 1};
	nxt[uk] = -1;
	mod[uk] = 1;
	cnt = 1;
	for (int i = 0; i < q; i++) {
		if (cnt >= 600) {
			recalc();
		}
		char s;
		int x;
		cin >> s >> x;
		int cur = 1;
		while (cur != -1) {
			proceed(cur, x, s);
			cur = nxt[cur];
		}
	}
	int cur = 1;
	while (cur != -1) {
		if (mod[cur] == -1) {
			for (int i = p[cur].first; i <= p[cur].second; i++) {
				g[i].first *= -1;
			}
		}
		cur = nxt[cur];
	}
	for (auto x: g) {
		ans[x.second] = x.first;
	}
	for (int i = 0; i < n; i++) {
		cout << ans[a[i]] << ' ';
	}
	cout << '\n';
	return 0; 	
}