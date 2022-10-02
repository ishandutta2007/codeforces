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
using ll = long long;
using ld = long double; 
const string FILENAME = "input";





struct node
{	
	int len = 0;
	int zeroOne = 0;
	int oneZero = 0;
	int lCnt = 0;
	int lLen = 0;
	int lLen2 = 0;
	int rCnt = 0;
	int rLen = 0;
	int rLen2 = 0;
	int mod = 0;
	node(){}
	node(int a) {
		len = 1;
		lCnt = a;
		lLen = 1;
		rCnt = a;
		rLen = 1;
	}
	void flip() {
		swap(oneZero, zeroOne);
		lCnt ^= 1;
		rCnt ^= 1;
	}
};



node operator +(const node& a, const node& b) {
	node c;
	c.len = a.len + b.len;
	c.zeroOne = max(a.zeroOne, b.zeroOne);
	c.oneZero = max(a.oneZero, b.oneZero);
	if (a.rCnt == 0 && b.lCnt == 0) {
		chkmax(c.zeroOne, a.rLen + b.lLen + b.lLen2);
		chkmax(c.oneZero, a.rLen2 + a.rLen + b.lLen);
	}
	if (a.rCnt == 0 && b.lCnt == 1) {
		chkmax(c.zeroOne, a.rLen + b.lLen);
	}
	if (a.rCnt == 1 && b.lCnt == 0) {
		chkmax(c.oneZero, a.rLen + b.lLen);
	}
	if (a.rCnt == 1 && b.lCnt == 1) {
		chkmax(c.zeroOne, a.rLen2 + a.rLen + b.lLen);
		chkmax(c.oneZero, a.rLen + b.lLen + b.lLen2);
	}
	c.lCnt = a.lCnt;
	if (a.lLen == a.len) {
		if (b.lCnt == a.lCnt) {
			c.lLen = a.len + b.lLen;
			c.lLen2 = b.lLen2;
		} else {
			c.lLen = a.len;
			c.lLen2 = b.lLen;
		}
	} else {
		c.lLen = a.lLen;
		c.lLen2 = a.lLen2;
		if (a.lLen + a.lLen2 == a.len && b.lCnt == a.rCnt) {
			c.lLen2 += b.lLen;
		}
	}
	c.rCnt = b.rCnt;
	if (b.rLen == b.len) {
		if (b.rCnt == a.rCnt) {
			c.rLen = b.len + a.rLen;
			c.rLen2 = a.rLen2;
		} else {
			c.rLen = b.len;
			c.rLen2 = a.rLen;
		}
	} else {
		c.rLen = b.rLen;
		c.rLen2 = b.rLen2;
		if (b.rLen + b.rLen2 == b.len && a.rCnt == b.lCnt) {
			c.rLen2 += a.rLen;
		}
	}
	return c;
}



struct rmq
{
	int ss = 1;
	vector<node> d;
	void init(vector<int> &st) {
		while (ss < sz(st)) {
			ss <<= 1;
		}
		d.resize(2 * ss);
		for (int i = 0; i < sz(st); i++) {
			d[ss + i] = node(st[i]);
		}
		for (int i = ss - 1; i >= 1; i--) {
			d[i] = d[i * 2] + d[i * 2 + 1];
		}
	}
	void push(int v) {
		if (d[v].mod) {
			d[v].flip();
			d[v].mod = 0;
			if (v < ss) {
				d[v * 2].mod ^= 1;
				d[v * 2 + 1].mod ^= 1;
			}
		}
	}
	void add(int v, int vl, int vr, int l, int r) {
		if (vl > r || vr < l) {
			push(v);
			return;
		} 
		if (l <= vl && vr <= r) {
			d[v].mod ^= 1;
			push(v);
			return;
		}
		push(v);
		add(v * 2, vl, (vl + vr) / 2, l, r);
		add(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r);
		d[v] = d[v * 2] + d[v * 2 + 1];
	}
	node get(int v, int vl, int vr, int l, int r) {
		if (vl > r || vr < l) {
			return node();
		}
		if (l <= vl && vr <= r) {
			push(v);
			return d[v];
		}
		push(v);
		return get(v * 2, vl, (vl + vr) / 2, l, r) + get(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r);
	}
	void flip(int l, int r) {
		add(1, 1, ss, l + 1, r + 1);
	}
	int get(int l, int r) {
		node ks = get(1, 1, ss, l + 1, r + 1);
		return max(max(ks.lLen, ks.rLen), ks.oneZero);
	}
} kek;


int get(int l, int r) {
	kek.flip(l, r);
	return kek.get(l, r);
}

int n, q;
string s;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
 	cin >> n >> q;
 	cin >> s;
 	vector<int> st;
 	for (int i = 0; i < n; i++) {
 		st.pb(s[i] == '>');
 	}
 	kek.init(st);
 	for (int it = 0; it < q; it++) {
 		int l, r;
 		cin >> l >> r;
 		l--, r--;
 		cout << get(l, r) << '\n';
 	}
	return 0;	 	
}