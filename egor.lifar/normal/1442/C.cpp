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
const int MAXN = 400229;
const ll Mod = 998244353;


ll sum(ll a, ll b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}
 
 
ll mul(ll a, ll b) {
	return ((ll)a * b) % Mod;
}


ll powm(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) {
			res = mul(res, a);
		}
		b >>= 1;
		a = mul(a, a);
	}
	return res;
}


int n, m;
vector<int> g[MAXN][2];
ll ans = 1e18;
ll curdist[MAXN];
vector<int> who[MAXN];
vector<pair<int, int> > v[MAXN];
pair<ll, ll> dist[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	read(FILENAME);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a][0].pb(b);
		v[a].pb(mp(b, 0));
		v[b + n].pb(mp(a + n, 0));
		g[b][1].pb(a);
	}
	for (int i = 0; i < n; i++) {
		curdist[i] = 1e18;
		v[i].pb(mp(i + n, 1));
		v[i + n].pb(mp(i, 1));
	}
	curdist[0] = 0;
	ll add = 0;
	for (int t = 0; t <= 20; t++) {
		for (int i = 0; i <= m; i++) {
			who[i].clear();
		}
		for (int i = 0; i < n; i++) {
			if (curdist[i] <= m) {
				who[curdist[i]].pb(i);
			}
		}
		for (int i = 0; i <= m; i++) {
			vector<int> st;
			for (auto h: who[i]) {
				if (curdist[h] == i) {
					st.pb(h);
				}
			}
			for (auto x: st) {
				//cout << x << endl;
				for (auto y: g[x][t & 1]) {
					if (curdist[y] > curdist[x] + 1) {
						curdist[y] = curdist[x] + 1;
						who[i + 1].pb(y);
					}
				}
			}
		}
		if (curdist[n - 1] <= m) {
			chkmin(ans, curdist[n - 1] + add);
		}
		add += (1 << t);
	}
	for (int i = 0; i < n; i++) {
		curdist[i] = 1e18;
	}
	curdist[0] = 0;
	set<pair<pair<ll, ll>, ll> > s;
	for (int i = 0; i < n; i++) {
		if (curdist[i] <= m) {
			dist[i] = mp(0, curdist[i]);
			s.insert(mp(dist[i], i));
		} else {
			dist[i] = mp(1e18, 1e18);
		}
	}
	for (int i = 0; i < n; i++) {
		dist[i + n] = mp(1e18, 1e18);
	}
	while (!s.empty()) {
		auto x = *s.begin();
		s.erase(x);
		for (auto y: v[x.second]) {
			int h = y.first;
			int t = y.second;
			auto z = dist[x.second];
			if (t == 0) {
				z.second++;
			} else {
				z.first++;
			}
			if (dist[h] > z) {
				s.erase(mp(dist[h], h));
				dist[h] = z;
				s.insert(mp(dist[h], h));
			}
		}
	}
	auto f = min(dist[n - 1], dist[n - 1 + n]);
	ll res = 0;
	ll t = 1;
	ll g = 1;
	ll ans1 = 0;
	for (int i = 0; i < f.first; i++) {
		ans1 = min((ll)1e18, ans1 + g); 
		res = sum(res, t);
		t = sum(t, t);
		g = min((ll)1e18, g + g);
	}
	ans1 += f.second;
	if (ans1 < ans || ans > 1e17) {
		//cout << f.first << ' ' << f.second << '\n';
		cout << (res + f.second) % Mod << '\n';
	} else {
		cout << ans % Mod << '\n';
	}
}