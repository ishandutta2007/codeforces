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
	return ((ll)a * b)% Mod;
}

struct node
{
	int a[2][2];
	int who;
	node(){}
};



node operator +(const node& a, const node& b) {
	node c;
	memset(c.a, 0, sizeof(c.a));
	for (int t = 0; t < 2; t++) {
		for (int t1 = 0; t1 < 2; t1++) {
			for (int t2 = 0; t2 < 2; t2++) {
				c.a[t][t2] = sum(c.a[t][t2], mul(a.a[t][t1], b.a[t1][t2]));
			}
		}
	}
	return c;
}




void inits(node &x, int val) {
	x.who = val;
	memset(x.a, 0, sizeof(x.a));
	if (val == 1) {
		x.a[0][1] = 1;
	}
	for (int c = 0; c < 10; c++) {
		for (int c1 = 0; c1 < 10; c1++) {
			int f = c + c1;
			int k = 0;
			if (f >= 10) {
				f -= 10;
				k = 1;
			}
			if (f == x.who) {
				x.a[k][0]++;
			}
		}
	}
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
		for (int i = ss + n; i < 2 * ss; i++) {
			d[i].a[0][0] = 1;
		}
	}
	void relax() {
		for (int i = ss - 1; i >= 1; i--) {
			d[i] = d[i * 2] + d[i * 2 + 1];
		}
	}
	void change(int i, int val) {
		i += ss;
		inits(d[i], val);
		while (i >> 1 > 0) {
			i >>= 1;
			d[i] = d[i * 2] + d[i * 2 + 1];
		}
	}
	int getVal() {
		return d[1].a[0][0];
	}
} kek;



int n, m;
string s;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> m;
	cin >> s;
	kek.init(n);
	for (int i = 0; i < n; i++) {
		inits(kek.d[kek.ss + i], s[i] - '0');
	}
	kek.relax();
	for (int i = 0; i < m; i++) {
		int x, d;
		cin >> x >> d;
		x--;
		kek.change(x, d);
		cout << kek.getVal() << '\n';
	}
}