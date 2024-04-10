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


int x, y;
int dx[6] = {1, 0, -1, -1, 0, 1};
int dy[6] = {1, 1, 0, -1, -1, 0};
map<pair<int, int>, ll> dist;


void solve() {
	cin >> x >> y;
	ll c1, c2, c3, c4, c5, c6;
	cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
	ll c[6] = {c1, c2, c3, c4, c5, c6};
	dist.clear();
	dist[mp(0, 0)] = 0;
	set<pair<ll, pair<int, int> > > s;
	s.insert(mp(0, mp(0, 0)));
	while (!s.empty()) {
		auto d = *s.begin();
		s.erase(d);
		int x = d.second.first;
		int y = d.second.second;
		ll cur = d.first;
		for (int k = 0; k < 6; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (max(abs(nx), abs(ny)) <= 4) {
				if (dist.find(mp(nx, ny)) == dist.end()) {
					dist[mp(nx, ny)] = cur + c[k]; 
					s.insert(mp(cur + c[k], mp(nx, ny)));
				} else if (dist[mp(nx, ny)] > cur + c[k]) {
					s.erase(mp(dist[mp(nx, ny)], mp(nx, ny)));
					dist[mp(nx, ny)] = cur + c[k];
					s.insert(mp(cur + c[k], mp(nx, ny)));
				}
			}
		}
	}
	ll cs[6] = {c1, c2, c3, c4, c5, c6};
	ll ans = 0;
	for (int i = 0; i < 6; i++) {
		int tx = dx[i];
		int ty = dy[i];
		cs[i] = dist[mp(tx, ty)];
		if (tx == 0 || ty == 0) {
			continue;
		}
		if (tx > 0 && x < 0) {
			continue;
		}
		if (tx < 0 && x > 0) {
			continue;
		}
		if (ty > 0 && y < 0) {
			continue;
		}
		if (ty < 0 && y > 0) {
			continue;
		}
		if (tx != 0 && x == 0) {
			continue;
		}
		if (ty != 0 && y == 0) {
			continue;
		}
		if (tx == 0) {
			int val = abs(y);
			ans += (ll)cs[i] * val;
			x -= tx * val;
			y -= ty * val;
		} else if (ty == 0) {
			int val = abs(x);
			ans += (ll)cs[i] * val;
			x -= tx * val;
			y -= ty * val;
		} else {
			int val = min(abs(x), abs(y));
			ans += (ll)cs[i] * val;
			x -= tx * val;
			y -= ty * val;
		}
	}
	for (int i = 0; i < 6; i++) {
		int tx = dx[i];
		int ty = dy[i];
		cs[i] = dist[mp(tx, ty)];
		if (tx > 0 && x < 0) {
			continue;
		}
		if (tx < 0 && x > 0) {
			continue;
		}
		if (ty > 0 && y < 0) {
			continue;
		}
		if (ty < 0 && y > 0) {
			continue;
		}
		if (tx != 0 && x == 0) {
			continue;
		}
		if (ty != 0 && y == 0) {
			continue;
		}
		if (tx == 0) {
			int val = abs(y);
			ans += (ll)cs[i] * val;
			x -= tx * val;
			y -= ty * val;
		} else if (ty == 0) {
			int val = abs(x);
			ans += (ll)cs[i] * val;
			x -= tx * val;
			y -= ty * val;
		} else {
			int val = min(abs(x), abs(y));
			ans += (ll)cs[i] * val;
			x -= tx * val;
			y -= ty * val;
		}
	}
	cout << ans << '\n';
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}