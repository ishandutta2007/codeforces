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
const string FILENAME = "input";
const int MAXN = 1000228;





struct rmq
{
	vector<int> d;
	int ss = 1;
	void init(int n) {
		while (ss < n) {
			ss <<= 1;
		}
		d.resize(2 * ss);
		for (int i = 0; i < 2 * ss; i++) {
			d[i] = 1e9;
		}
	}
	void change(int i, int val) {
		i += ss;
		d[i] = val;
		while (i >> 1 > 0) {
			i >>= 1;
			d[i] = max(d[i * 2], d[i * 2 + 1]);
		}
	}
	int getpos(int v, int vl, int vr, int val) {
		if (d[v] <= val) {
			return -1;
		}
		if (vl == vr) {
			return vl - 1;
		}
		int f = getpos(v * 2, vl, (vl + vr) / 2, val);
		if (f != -1) {
			return f;
		}
		return getpos(v * 2 + 1, (vl + vr) / 2 + 1, vr, val);
	}
	int findf(int i) {
		return getpos(1, 1, ss, i);
	}
	int getval(int i) {
		return d[ss + i];
	}
};


rmq kek;


struct segment
{
	int l, r, val, t;
	segment(){}
	segment(int _l, int _r, int _val, int _t) {
		l = _l;
		r = _r;
		val = _val;
		t = _t;
	}
};



bool operator <(const segment &a, const segment &b) {
	return a.val < b.val || (a.val == b.val && a.r < b.r);
}


set<segment> s;


long long ans = 0;


void proceed(int lx, int rx, int ly, int ry, int val) {
	int l1y = ly - val + 1;
	int r1y = ry - val + 1;
	chkmax(l1y, lx);
	chkmin(r1y, rx);
	//cout << lx << ' ' << rx << ''
	if (l1y <= r1y) {
		ans += r1y - l1y +1 ;
	}
}

void del(segment a, int t) {
	if (t + 1 > a.t) {
		return;
	}
	proceed(t + 1, a.t, a.l, a.r, a.val);
}

void add(int gr, int l, int r, int val, int i) {
	if (l > r) {
		return;
	}
	if (gr == r) {
		auto it = s.lower_bound(segment(0, 0, val, 0));
		if (it != s.end() && it->val == val) {
			segment a = *it;
			del(a, i);
			s.erase(a);
			a.t = i;
			a.l = l;
			s.insert(a);
			return;
		}
	}
	s.insert(segment(l, r, val, i));
}


void provide(int l, int r, int i) {
	int cur = l;
	while (cur <= r) {
		int k = kek.findf(cur);
		int f = kek.getval(k);
		add(r, cur, min(r, f - 1), k, i);
		cur = f;
	}
}



int who[MAXN];
int n, q;
int a[MAXN];
bool kekr[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n;
	mt19937 ast;
	ast.seed(time(NULL));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	kek.init(n + 1);
	for (int i = n - 1; i >= 0; i--){
		kek.change(a[i], i);
		if (i == n - 1) {
			if (a[i] == 0) {
				s.insert(segment(i, i, 1, i));
			} else {
				s.insert(segment(i, i, 0, i));
			}
		} else {
			auto it = s.lower_bound(segment(0, 0, a[i], 0));
			if (!(it == s.end() || it->val != a[i])) {
				segment ass = *it;
				s.erase(ass);
				del(ass, i);
				provide(ass.l, ass.r, i);
			}
			int t = (a[i] == 0);
			segment p = *s.begin();
			if (t == p.val) {
				s.erase(p);
				del(p, i);
				p.l = i;
				p.t = i;
				s.insert(p);
			} else {
				segment ar;
				ar.l = i;
				ar.r = i;
				ar.t = i;
				ar.val = t;
				s.insert(ar);
			}
		}
	}
	for (auto x: s) {
		del(x, -1);
	}
	cout << ans << endl;
	return 0; 	
}