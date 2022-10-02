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
const int MAXN  = 200228;




struct node
{
	int mod = 0;
	int mx = 0;
	int len = 0;
	ll sum = 0;
};


node operator +(const node &a, const node &b) {
	node c;
	c.len = a.len + b.len;
	c.mx = max((a.mod ? a.mod: a.mx), (b.mod ? b.mod: b.mx));
	c.sum = (a.mod ? (ll)a.mod * a.len: a.sum) + (b.mod ? (ll)b.mod * b.len: b.sum);
	c.mod = 0;
	return c;
}


struct rmq
{
	vector<node> d;
	int ss = 1;
	void init(int n, vector<int> a) {
		while (ss < n) {
			ss <<= 1;
		}
		d.resize(2 * ss);
		for (int i = ss; i < ss + n; i++) {
			d[i].len = 1;
			d[i].mx = a[i - ss];
			d[i].sum = a[i - ss];
		}
		for (int i = ss - 1; i >= 1; i--) {
			d[i] = d[i * 2] + d[i * 2 + 1];
		}
	}
	void push(int v) {
		if (d[v].mod) {	
			d[v].mx = d[v].mod;
			d[v].sum = (ll)d[v].mx * d[v].len;
			if (v < ss) {
				d[v * 2].mod = d[v].mod;
				d[v * 2 + 1].mod = d[v].mod;
			}
			d[v].mod = 0;
		}
	}
	void setVal(int v, int vl, int vr, int l, int r, int x) {
		if (l > vr || vl > r) {
			return;
		} 
		if (l <= vl && vr <= r) {
			d[v].mod = x;
			return;
		}
		push(v);
		setVal(v * 2, vl, (vl + vr) / 2, l, r, x);
		setVal(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, x);
		d[v] = d[v * 2] + d[v * 2 + 1];
	}
	ll getsum(int v, int vl, int vr, int l, int r) {
		if (l > vr || vl > r) {
			return 0;
		} 
		if (l <= vl && vr <= r) {
			push(v);
			return d[v].sum;
		}
		push(v);
		return getsum(v * 2, vl, (vl + vr) / 2, l, r) + getsum(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r);
	}
	ll getsum(int l, int r) {
		return getsum(1, 1, ss, l + 1, r + 1);
	}
	int spusk(int v, int vl, int vr, int pos, int val) {
		push(v);
		if (d[v].mx < val) {
			return 0;
		}
		if (vl > pos) {
			return 0;
		}
		if (vl == vr) {
			return vl;
		}
		int d = spusk(v * 2 + 1, (vl + vr) / 2 + 1, vr, pos, val);
		if (d != 0) {
			return d;
		}
		return spusk(v * 2, vl, (vl + vr) / 2, pos, val);
	}
	int findF(int pos, int val) {
		return spusk(1, 1, ss, pos + 1, val) - 1;
	}
	void setVal(int l, int r, int x) {
		setVal(1, 1, ss, l + 1, r + 1, x);
	}
	void modify(int pos, int val) {
		int k = findF(pos, val);
		if (k == pos) {
			return;
		}
		setVal(k + 1, pos, val);
	}
	int spusk1(int v, int vl, int vr, ll val) {
		push(v);
		if (d[v].sum <= val) {
			return vr;
		}
		if (vl == vr) {
			return 0;
		}
		push(v * 2);
		if (d[v * 2].sum <= val) {
			int t = spusk1(v * 2 + 1, (vl + vr) / 2 + 1, vr, val - d[v * 2].sum);
			if (t == 0) {
				return (vl + vr) / 2;
			}
			return t;
		}
		return spusk1(v * 2, vl, (vl + vr) / 2, val);
	}
	int findD(ll val) {
		return spusk1(1, 1, ss, val) - 1;
	}
} kek;
 
int n, q;
int a[MAXN];



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> q;
	vector<int> d;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		d.pb(a[i]);
	}
	kek.init(n, d);
	for (int it = 0; it < q; it++) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, y;
			cin >> x >> y;
			x--;
			kek.modify(x, y);
		} else {
			int x;
			ll y;
			cin >> x >> y;
			x--;
			int cur = x;
			int res = 0;
			while (cur < n) {
				ll fk = kek.getsum(0, cur - 1);
				int ft = kek.findD(fk + y);
			//	 cout << ft << ' ' << cur << ' ' << fk + y << ' ' << kek.getsum(0, cur) << endl;
				if (ft >= cur) {
					chkmin(ft, n - 1);
					res += ft - cur + 1;
					y -= kek.getsum(cur, ft);
					cur = ft + 1;
				} else {
					int l = kek.findF(n - 1, y + 1);
				//	cout << cur << ' ' << l << ' ' << kek.getsum(l + 1, l + 1) << ' ' << y << endl;
					cur = l + 1;
				}
			}
			cout << res << '\n';
		}
	}
}