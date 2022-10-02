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
template<typename T1, typename T2> inline bool chkmin(T1 &a, T2 b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<typename T1, typename T2> inline bool chkmax(T1 &a, T2 b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
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

const int MAXN = 500228;


int n, m;
vector<int> who[MAXN];
int a[MAXN];
ll sum[MAXN];
ll cnt[MAXN];
bool bad[MAXN];
int pos[MAXN];


struct rmq {
	vector<ll> d;
	vector<ll> mod;
	int ss = 1;
	void init(int n) {
		while (ss < n) {
			ss <<= 1;
		}
		d.resize(2 * ss, 0);
		mod.resize(2 * ss, 0);
	}
	void push(int v) {
		if (mod[v] != 0) {
			if (v < ss) {
				mod[v * 2] += mod[v];
				mod[v * 2 +1] += mod[v]; 
			}
			d[v] += mod[v];
			mod[v] = 0;
		}
	}
	void add(int v, int vl, int vr, int l, int r, int x) {
		if (vl > r || vr < l) {
			push(v);
			return;
		}
		if (l <= vl && vr <= r) {
			mod[v] += x;
			push(v);
			return;
		}
		push(v);
		add(v * 2, vl, (vl + vr) / 2, l, r, x);
		add(v * 2 +1 , (vl + vr) / 2 + 1, vr, l, r, x);
		d[v] = min(d[v * 2], d[v * 2 + 1]);
	}
};

 
void solve() {
	rmq kek;
	cin >> n >> m;
	kek.init(2 * n + 2);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		kek.add(1, 1, kek.ss, 1, 2 * (i + 1), 1);
	}
	sort(a, a + n);
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		who[i].clear();
		cnt[i] = 0;
		sum[i] = 0;
		for (int j = 0; j < k; j++) {
			int b;
			cin >> b;
			who[i].pb(b);
			sum[i] += b;
			cnt[i]++;
		}
	}
	int bads = 0;
	for (int i = 0; i < m; i++) {
		if (cnt[i] * a[n - 1] < sum[i]) {
			bad[i] = true;
			bads++;
		} else {
			bad[i] = false;
			int l = 0;
			int r = n - 1;
			while (l < r) {
				int mid = (l + r) >> 1;
				if (cnt[i] * a[mid] < sum[i]) {
					l = mid + 1;
				} else {
					r = mid;
				}
			}
			pos[i] = l;
			kek.add(1, 1, kek.ss, 1, 2 * (pos[i] + 1) - 1, -1);
		}
	}
	string ans;
	for (int i = 0; i < m; i++) {
		for (auto x: who[i]) {
			if (bad[i])  {
				bads--;
			} else {
				kek.add(1, 1, kek.ss, 1, 2 * (pos[i] + 1) - 1, 1);
			}
			cnt[i]--;
			sum[i] -= x;
			if (cnt[i] * a[n - 1] < sum[i]) {
				ans += '0';
			} else {
				if (bads) {
					ans += '0';
				} else {
					int l = 0;
					int r = n - 1;
					while (l < r) {
						int mid = (l + r) >> 1;
						if (cnt[i] * a[mid] < sum[i]) {
							l = mid + 1;
						} else {
							r = mid;
						}
					}
					kek.add(1, 1, kek.ss, 1, 2 * (l + 1) - 1, -1);
					kek.push(1);
					if (kek.d[1] < 0) {
						ans += '0';
					} else {
						ans += '1';
					}
					kek.add(1, 1, kek.ss, 1, 2 * (l + 1) - 1, 1);
				}
			}
			cnt[i]++;
			sum[i] += x;
			if (bad[i])  {
				bads++;
			} else {
				kek.add(1, 1, kek.ss, 1, 2 * (pos[i] + 1) - 1, -1);
			}
		}
	}
	cout << ans << '\n';
}


int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;
	t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}