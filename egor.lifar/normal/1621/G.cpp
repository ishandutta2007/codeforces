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
const int Mod = 1000000007;


int sum(int a, int b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
	return ((ll)a * b) % Mod;
}


void add(int &a, int b) {
	a += b;
	if (a >= Mod) {
		a -= Mod;
	}
}

int powm(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = mul(res, a);
		}
		b >>= 1;
		a = mul(a, a);
	}
	return res;
}


const int MAXN = 220228;


int n;
int a[MAXN];
int dl[MAXN], dr[MAXN];
int curdp[MAXN];


struct fenw {
	vector<int> d;
	void init(int n) {
		d.resize(n + 1, 0);
	}
	void inc(int i, int val) {
		for (; i < sz(d); i |= (i + 1)) {
			add(d[i], val);
		}
	}
	int get(int i) {
		int ans = 0;
		for (; i >= 0; i = (i & (i + 1)) - 1) {
			add(ans, d[i]);
		}
		return ans;
	}
	int get(int l, int r) {
		return sum(get(r), Mod - get(l - 1));
	}
};

 
void solve() {
	cin >> n;
	vector<int> tp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		tp.pb(a[i]);
	}	
	sort(all(tp));
	tp.resize(distance(tp.begin(), unique(all(tp))));
	for (int i = 0; i < n; i++) {
		a[i] = lower_bound(all(tp), a[i]) - tp.begin();
	}
	fenw kek;
	kek.init(n + 1);
	for (int i = 0; i < n; i++) {
		curdp[i] = 0;
		dl[i] = sum(kek.get(a[i] - 1), 1);
		kek.inc(a[i], dl[i]);
	}
	vector<pair<int, int> > st;
	for (int i = 0; i < n; i++) {
		st.pb(mp(a[i], -i));
	}
	sort(all(st));
	reverse(all(st));
	for (int i = 0; i < n; i++) {
		st[i].second *= -1;
	}
	fenw kek1;
	kek1.init(n + 1);
	fenw kek2;
	kek2.init(n + 1);
	vector<pair<int, int> > ste;
	int uk = 0;
	int ans = 0;
	int prev = -1;
	int pos = 0;
	int dd = -1;
	for (auto xx: st) {
		int last = -1;
		while (uk < sz(st) && st[uk].first > xx.first) {
			if (st[uk].second > prev) {
				prev = st[uk].second;
				last = uk;
			}
			kek1.inc(n + 1 - st[uk].second, dr[st[uk].second]);
			uk++;
		}
		if (last != -1) {
			curdp[prev] = 1;
			for (auto z: ste) {
				kek2.inc(z.first, Mod - z.second);
			}
			ste.clear();
			kek2.inc(n + 1 - prev, curdp[prev]);
			ste.pb(mp(n + 1 - prev, curdp[prev]));
			for (int j = last + 1; j < sz(st); j++) {
				int k = st[j].second;
				if (k > prev) {
					break;
				}
				curdp[k] = kek2.get(n + 1 - (k + 1));
				kek2.inc(n + 1 - k, curdp[k]);
				ste.pb(mp(n + 1 - k, curdp[k]));
			}
			dd = pos;
		}
		int i = xx.second;
		dr[i] = sum(kek1.get(n + 1 - (i + 1)), 1);
		if (i > prev) {

		} else {	
			int rdr = sum(dr[i], Mod - curdp[i]);
			ans = sum(ans, mul(rdr, dl[i]));
		}
		pos++;
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