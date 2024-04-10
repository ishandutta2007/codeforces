/*
KAMUI!
 
 

 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

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
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define rank rank228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int MAXN = 200228;


int n, q;
ll s[MAXN];
int t[MAXN];
ll a[MAXN];
vector<ll> st;
int cnt = 0;



struct rmq
{
	vector<int> d;
	vector<ll> d1;
	int ss = 1;
	void init(int n) {
		while (ss < n) {
			ss <<= 1;
		}
		d1.resize(2 * ss, 0);
		d.resize(2 * ss, 0);
	}
	void change(int i, ll val1, int val) {
		i += ss;
		d1[i] += val1;
		d[i] += val;
		while (i >> 1 > 0) {
			i >>= 1;
			d1[i] = d1[i * 2] + d1[i * 2 + 1];
			d[i] = d[i * 2] + d[i * 2 + 1];
		}
	}
	int spuskl(int v, int vl, int vr, int need) {
		if (d[v] < need) {
			return -1;
		}
		if (need == 0) {
			return vl - 1;
		}
		if (vl == vr) {
			return vl;
		}
		int f = spuskl(v * 2, vl, (vl + vr) / 2, need);
		if (f != -1) {
			return f;
		}
		return spuskl(v * 2 + 1, (vl + vr) / 2 + 1, vr, need - d[v * 2]);
	}
	int spuskr(int v, int vl, int vr, int need) {
		if (d[v] < need) {
			return -1;
		}
		if (need == 0) {
			return vr + 1;
		}
		if (vl == vr) {
			return vl;
		}
		int f = spuskr(v * 2 + 1, (vl + vr) / 2 + 1, vr, need);
		if (f != -1) {
			return f;
		}
		return spuskr(v * 2, vl, (vl + vr) / 2, need - d[v * 2 + 1]);
	}
	int findL(int k) {
		int a = spuskl(1, 1, ss, k);
		return a - 1;
	}
	int findR(int k) {
		int a = spuskr(1, 1, ss, k);
		return a - 1;
	}
	ll spusklS(int v, int vl, int vr, int need) {
		if (d[v] < need) {
			return -1;
		}
		if (need == 0) {
			return 0;
		}
		if (vl == vr) {
			return d1[v];
		}
		ll f = spusklS(v * 2, vl, (vl + vr) / 2, need);
		if (f != -1) {
			return f;
		}
		return d1[v * 2] + spusklS(v * 2 + 1, (vl + vr) / 2 + 1, vr, need - d[v * 2]);
	}
	ll spuskrS(int v, int vl, int vr, int need) {
		if (d[v] < need) {
			return -1;
		}
		if (need == 0) {
			return 0;
		}
		if (vl == vr) {
			return d1[v];
		}
		ll f = spuskrS(v * 2 + 1, (vl + vr) / 2 + 1, vr, need);
		if (f != -1) {
			return f;
		}
		return d1[v * 2 + 1] + spuskrS(v * 2, vl, (vl + vr) / 2, need - d[v * 2 + 1]);
	}
	ll findLS(int k) {
		return spusklS(1, 1, ss, k);
	}
	ll findRS(int k) {
		return spuskrS(1, 1, ss, k);
	}
} kek1;


struct node
{
	ll sumall = 0;
	ll sumgood = 0;
	int cntgood = 0;
	ll mod = 0;
	int mod1 = 0;
};


node operator +(const node & a, const node &b) {
	node c;
	c.sumall = a.sumall + b.sumall;
	c.sumgood = a.sumgood + b.sumgood;
	c.cntgood = a.cntgood + b.cntgood;
	return c;
}


struct rsq
{
	vector<node> d;
	int ss = 1;
	void init(int n) {
		while (ss < n) {
			ss <<= 1;
		}
		d.resize(2 * ss);
	}	
	void push(int v, int len) {
		if (d[v].mod != 0 || d[v].mod1 != 0) {
			if (v < ss) {
				d[v * 2].mod += d[v].mod;
				d[v * 2 + 1].mod += d[v].mod;
				d[v * 2].mod1 += d[v].mod1;
				d[v * 2 + 1].mod1 += d[v].mod1;
			}
			d[v].sumall += d[v].mod * len;
			d[v].sumgood += d[v].mod * d[v].cntgood;
			d[v].cntgood += d[v].mod1;
			d[v].sumgood += d[v].sumall * d[v].mod1;
			d[v].mod = 0;
			d[v].mod1 = 0;
		}
	}
	void add(int v, int vl, int vr, int l, int r, ll mod, int mod1) {
		if (vl > r || vr < l) {
			push(v, vr - vl + 1);
			return;
		}
		if (l <= vl && vr <= r) {
			d[v].mod += mod;
			d[v].mod1 += mod1;
			push(v, vr - vl + 1);
			return;
		}
		push(v, vr - vl + 1);
		add(v * 2, vl, (vl + vr) / 2, l, r, mod, mod1);
		add(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, mod, mod1);
		d[v] = d[v * 2] + d[v * 2 + 1];
	}
	ll getsum(int v, int vl, int vr, int l, int r) {
		if (vl > r || vr < l) {
			return 0;
		}
		if (l <= vl && vr <= r) {
			push(v, vr - vl + 1);
			return d[v].sumgood;
		}
		push(v, vr - vl + 1);
		return getsum(v * 2, vl, (vl + vr) / 2, l, r) + getsum(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r);
	}
	void add(int l, int r, ll mod, int mod1) {
		add(1, 1, ss, l + 1, r + 1, mod, mod1);
	}
	ll getsum(int l, int r) {
		return getsum(1, 1, ss, l + 1, r + 1);
	}
} pref, suff;


void add(ll val, int mod) {
	cnt += mod;
	int pos = lower_bound(all(st), val) - st.begin();
	pref.add(pos, pos, 0, mod);
	suff.add(pos, pos, 0, mod);
	pref.add(pos, sz(st) - 1, val * mod, 0);
	suff.add(0, pos, val * mod, 0);
	kek1.change(pos, val * mod, mod);
}


ll getval(int x) {
	ll fl = kek1.findLS(x);
	ll fr = kek1.findRS(x - 1);
	return fr - fl;
}	


//kek.getSuffSum(fr) - kek.getSuffSum(fr - 1) - (kek.getSuffSum(fl) - kek.getPrefSum(fl - 1))


ll solve() {
	if (cnt == 0) {
		return 0;
	}
	ll res = suff.getsum(0, sz(st) - 1) - pref.getsum(0, sz(st) - 1);
	int l = 1;
	int r = (cnt + 1) / 2;
	bool was = false;
	while (l < r) {
		int mid = (l + r) >> 1;
		ll f = getval(mid);
		if (f >= 0) {
			r = mid;	
		} else {
			l = mid + 1;
		}
	}
	ll f = getval(l);
	if (f < 0) {
		return res;
	}
	int l1 = cnt - l + 1;
	// int r1 = cnt - l1 + 1;
	// while (l1 < r1) {
	// 	int mid = (l1 + r1 + 1) >> 1;
	// 	if (getval(mid) >= 0) {
	// 		l1 = mid;
	// 	} else {
	// 		r1 = mid - 1;
	// 	}
	// }
	int fl = l;
	int fr = l1;
	res -= (suff.getsum(kek1.findR(fr - 1), min(sz(st) - 1, kek1.findR(fl - 1)))) - (pref.getsum(kek1.findL(fl), kek1.findL(fr)));
	return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	//read(FILENAME);
 	cin >> n >> q;
 	for (int i = 0; i < n; i++) {
 		cin >> s[i];
 		st.pb(s[i]);
 	}
 	for (int it = 0; it < q; it++) {
 		cin >> t[it] >> a[it];
 		st.pb(a[it]);
 	}
 	sort(all(st));
 	st.resize(distance(st.begin(), unique(all(st))));
 	kek1.init(sz(st));
 	pref.init(sz(st));
 	suff.init(sz(st));
 	for (int i = 0; i < n; i++) {
 		add(s[i], 1);
 	}
 	cout << solve() << '\n';
 	for (int it = 0; it < q; it++) {
 		if (t[it] == 1) {
 			add(a[it], 1);
 		} else {
 			add(a[it], -1);
 		}
 		cout << solve() << '\n';
 	}
}