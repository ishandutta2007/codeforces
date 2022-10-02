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
const int MAXN = 500228;



int n;
string s;
ll cntmid = 0;
ll sumlenmid = 0;
ll sumborder = 0;
ll cnttot = 0;
ll sumtot = 0;
set<pair<int, int> > cur;
ll cursum = 0;


void delcon(pair<int, int> x, pair<int, int> y) {
	if (x.first < 0 && y.first >= n) {
		return;
	}
	if (x.first < 0) {
		cursum -= (ll)(y.second) * (y.second + 1) / 2;
		sumborder -= y.first;
	} else if (y.first >= n) {
		cursum -= (ll)(n - x.first - 1) * ((n - x.first - 1) + 1) / 2;
		sumborder -= n - x.second - 1;
	} else {
		cntmid--;
		cursum -= (ll)(y.second - x.first - 1) * ((y.second - x.first - 1) + 1) / 2;
		sumlenmid -= y.first - x.second - 1;
	}
}


void addcon(pair<int, int> x, pair<int, int> y) {
	if (x.first < 0 && y.first >= n) {
		cursum += (ll)n * (n + 1) / 2;
		return;
	}
	if (x.first < 0) {
		cursum += (ll)(y.second) * (y.second + 1) / 2;
		sumborder += y.first;
	} else if (y.first >= n) {
		cursum += (ll)(n - x.first - 1) * ((n - x.first - 1) + 1) / 2;
		sumborder += n - x.second - 1;
	} else {
		cursum += (ll)(y.second - x.first - 1) * ((y.second - x.first - 1) + 1) / 2;
	//	cout << x.first << ' ' << x.second << ' ' << y.first << ' ' << y.second << '\n';
		cntmid++;
		sumlenmid += y.first - x.second - 1;
	}
}


void add(pair<int, int> x)  {
	sumtot += x.second - x.first + 1;
	cnttot++;
	auto d = cur.lower_bound(x);
	pair<int, int> r, l;
	if (d != cur.end()) {
		r = *d;
	}
	if (d != cur.begin()) {
		d--;
		l = *d;
	}
	delcon(l, r);
	addcon(l, x);
	addcon(x, r);
	cur.insert(x);
}


ll kek;


void del(pair<int, int> x) {
	ll len = x.second - x.first + 1;
	sumtot -= x.second - x.first + 1;
	cnttot--;
	cur.erase(x);
	auto d = cur.lower_bound(x);
	pair<int, int> r, l;
	if (d != cur.end()) {
		r = *d;
	}
	if (d != cur.begin()) {
		d--;
		l = *d;
	}
	ll dd = max(0LL, l.second - len + 2);
	ll d1 = min((ll)n - 1, r.first + len - 2);
	kek += (x.first - dd + 1) * (d1 - x.second + 1);
	addcon(l, r);
	delcon(l, x);
	delcon(x, r);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	read(FILENAME);
	cin >> n >> s;
// 	int ret = 0;
// 	int cntr = 0;
// 	for (int i = 0; i < n; i++) {
// 		int cur = 0;
// 		int t = 0;
// 		for (int j = i; j < n; j++) {
// 			if (s[j] == '1') {
// 				cur++;
// 			} else {
// 				cur = 0;
// 			}
// 			chkmax(t, cur);
// 			if (t == 1) {
// 				cntr++;
// 			}
// 			ret += t;
// 		}
// 	}
// //	cout << cntr << endl;
// 	cout << ret << '\n';
	vector<pair<int, int> > st;
	int last = -1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			if (last != -1) {
				st.pb(mp(last, i - 1));
			}
			last = -1;
		} else {
			if (last == -1) {
				last = i;
			}
		}
	}		
	if (last != -1) {
		st.pb(mp(last, n - 1));
	} 
	if (st.empty()) {
		cout << 0 << '\n';
		return 0;
	}
	vector<pair<int, int> > res;
	for (int i = 0; i < sz(st); i++) {
		res.pb(mp(st[i].second - st[i].first + 1, i));
	}	
	cur.insert(mp(-1, -1));
	cur.insert(mp(n, n));
	for (int i = 0; i < sz(st); i++) {
		add(st[i]);
	}
	sort(all(res));
	int uk = 0;
	ll ans = 0;
	for (int len = 1; len <= n; len++) {
		kek = 0;
		int cnt = 0;
		while (uk < sz(res) && res[uk].first <= len) {
			//cout << st[res[uk].second].first << ' ' << st[res[uk].second].second << endl;
			del(st[res[uk].second]);
			cnt++;
			uk++;
		}
		if (uk == sz(res)) {
			ans += kek * len;
			break;
		}
		ll tot = kek + (sumlenmid * 2 + cntmid * (2 * len - 1) + sumborder + sumtot - cnttot * (len - 1));
		//cout << cntmid  << endl;
		ans += tot * len;
	}
	cout << ans << '\n';
}