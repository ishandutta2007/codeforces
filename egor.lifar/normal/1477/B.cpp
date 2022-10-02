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
const int Mod = 998244353;


int sum(int a, int b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
	return ((ll)a * b) % Mod;
}


int powm(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = mul(res, a);
		}
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}


int inv(int a) {
    return powm(a, Mod - 2);
}

const int MAXN = 200228;


int n, q;
string s, f;
int l[MAXN], r[MAXN];


struct node
{
	int sum = 0;
	int mod = -1;
	int len = 0;
	node(){}
};


node operator +(const node &a, const node &b) {
	node c;
	c.sum = a.sum + b.sum;
	c.len = a.len + b.len;
	return c;
}


struct rmq
{
	vector<node> d;
	int ss = 1;
	void init(int n) {
		while (ss < n) {
			ss <<= 1;
		}
		d.resize(2 * ss);
		for (int i = ss; i < ss + n; i++) {
			d[i].sum = f[i - ss] - '0';
			d[i].len = 1;
		}
		for (int i = ss - 1; i >= 1; i--) {
			d[i] = d[i * 2] + d[i * 2 + 1];
		}
	}
	void push(int v, int len) {
		if (d[v].mod != -1) {
			d[v].sum = d[v].mod * len;
			if (v < ss) {
				d[v * 2].mod = d[v].mod;
				d[v * 2 + 1].mod = d[v].mod;
			}
			d[v].mod = -1;
		}
	}
	void add(int v, int vl, int vr, int l, int r, int x) {
		if (vl > r || vr < l) {
			push(v, vr - vl + 1);
			return;
		}
		if (l <= vl && vr <= r) {
			d[v].mod = x;
			push(v, vr - vl + 1);
			return;
		}
		push(v, vr - vl + 1);
		add(v * 2, vl, (vl + vr) / 2, l, r, x);
		add(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, x);
		d[v] = d[v * 2] + d[v * 2 + 1];
	}
	void add(int l, int r, int x) {
		add(1, 1, ss, l + 1, r + 1, x);
	}
	bool check() {
		for (int i = 1; i < 2 * ss; i++) {
			push(i, d[i].len);
		}
		for (int i = ss; i < ss + n; i++) {
			if (d[i].sum != s[i - ss] - '0') {
				return false;
			}
		}
		return true;
	}
	int getsum(int v, int vl, int vr, int l, int r) {
		if (vl > r || vr < l) {
			return 0;
		}
		if (l <= vl && vr <= r) {
			push(v, vr - vl + 1);
			return d[v].sum;
		}
		push(v, vr - vl + 1);
		return getsum(v * 2, vl, (vl + vr) / 2, l, r) + getsum(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r);
	}
	int getsum(int l, int r) {
		return getsum(1, 1, ss, l + 1, r + 1);
	}
};



void solve() {
	cin >> n >> q;
	cin >> s >> f;
	for (int it = 0; it < q; it++) {
		cin >> l[it] >> r[it];
		l[it]--, r[it]--;
	}
	rmq kek;
	kek.init(n);
	for (int it = q - 1; it >= 0; it--) {
		int f = kek.getsum(l[it], r[it]);
		int tp = r[it] - l[it] + 1;
		if (f < tp - f) {
			if (f * 2 >= tp) {
				cout << "NO\n";
				return;
			}
			kek.add(l[it], r[it], 0);
		} else {
			if ((tp - f) * 2 >= tp) {
				cout << "NO\n";
				return;
			}
			kek.add(l[it], r[it], 1);
		}
	}
	if (kek.check()) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
   //  read(FILENAME);
   	int t;
   	cin >> t;
   	while (t--) {
   		solve();
   	}
   	return 0;
}