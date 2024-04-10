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


const int MAXN = 200228;


int n, q;
string s;
int pref[MAXN];
int ss = 1;


struct node {
	int l = 0;
	int r = 0;
	int len = 0;
};

node d[MAXN * 4];


node operator +(const node &a, const node & b) {
	if (a.len == 0) {
		return b;
	}
	if (b.len == 0) {
		return a;
	}
	node c;
	c.len = a.len + b.len;
	c.l = a.l;
	c.r = a.r;
	if (a.len & 1) {
		c.l += b.r;
		c.r += b.l;
	} else {
		c.l += b.l;
		c.r += b.r;
	}
	return c;
}


void change(int i, int x) {
	d[i].l = x - 1;
	d[i].r = 0;
	d[i].len = 1;
	while (i >> 1 > 0) {
		i >>= 1;
		d[i] = d[i * 2] + d[i * 2 + 1];
	}
}


node get(int v, int vl, int vr, int l, int r) {
	if (vl > r || vr < l) {
		return node();
	}
	if (l <= vl && vr <= r) {
		return d[v];
	}
	return get(v * 2, vl, (vl + vr) / 2, l, r) + get(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r);
}


void solve() {
	cin >> n >> q;
	cin >> s;
	vector<pair<char, int> > st;
	for (auto x: s) {
		if (st.empty() || st.back().first != x) {
			st.pb(mp(x, 1));
		} else {
			st.back().second++;
		}
	}
	while (ss < n) {
		ss <<= 1;
	}
	for (int i = 0; i < sz(st); i++) {
		pref[i] = st[i].second;
		if (i) {
			pref[i] += pref[i - 1];
		}
		d[ss + i].l = st[i].second - 1;
		d[ss + i].r = 0;
		d[ss + i].len = 1;
	}
	for (int i = ss - 1; i >= 1; i--) {
		d[i] = d[i * 2] + d[i * 2 + 1];
	}
	for (int it = 0; it < q; it++) {
		int l, r;
		cin >> l >> r;
		int posl = lower_bound(pref, pref + sz(st), l) - pref;
		int posr = lower_bound(pref, pref + sz(st), r) - pref;
		if (posl == posr) {
			cout << r - l + 1 << '\n';
			continue;
		}
		int rl = pref[posl] - (l - 1);
		int rr = r - (posr ? pref[posr - 1]: 0); 
		change(ss + posl, rl);
		change(ss + posr, rr);
		auto f = get(1, 1, ss, posl + 1, posr + 1);
		change(ss + posl, st[posl].second);
		change(ss + posr, st[posr].second);
		cout << 1 + max(f.l, f.r) << '\n';
	}	
}		


int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;
	t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}