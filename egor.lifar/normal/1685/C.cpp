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



int n;
vector<pair<int, int> > ans;
int sum = 0;


int get(int id) {
	if (sz(ans) & 1) {
		return sum - id;
	}
	return sum + id;
}


void solve() {
	ans.clear();
	sum = 0;
	cin >> n;		
	string s;
	cin >> s;
	int bal = 0;
	vector<int> pos;
	for (int i = 0; i < sz(s); i++) {
		if (s[i] == '(') {
			bal++;
		} else if (s[i] == ')') {
			bal--;
			if (bal == -1) {
				pos.pb(i);
				bal = 0;
			}
		}
	}
	if (pos.empty()) {
		cout << 0 << '\n';
		return;
	}
	int l = 0;
	int r = sz(s) - 1;
	int lbal = 0;
	int rbal = 0;
	while (l < r) {
	//	cout << l << ' ' << r << endl;
		bool was = false;
		int plbal = lbal, prbal = rbal;
		int optl = 0;
		int vall = -1;
		int pl = l;
		int pr = r;
		while (l <= r) {
			if (s[get(l)] == '(') {
				lbal++;
				if (lbal > vall) {
					vall = lbal;
					optl = l + 1; 
				}
			} else {
				lbal--;
				if (lbal < 0) {
					if (vall == -1) {
						optl = l;
					}
					was = true;
					break;
				}
			}
			l++;
		}
		int optr = 0;
		int valr = -1;
		while (r >= l) {
			if (s[get(r)] == ')') {
				rbal++;
				if (rbal > valr) {
					valr = rbal;
					optr = r - 1; 
				}
			} else {
				rbal--;
				if (rbal < 0) {
					if (valr == -1) {
						optr = r;
					}
					break;
				}
			}
			r--;
		}
		if  (!was) {
			break;
		}	
		//cout << optl << ' ' << optr << ' ' << l << ' ' << r << ' ' << plbal << ' ' << lbal << endl;
 		lbal = plbal;
		rbal = prbal;
 		l = pl;
		r = pr;
		while (l < optl) {
			if (s[get(l)] == '(') {
				lbal++;
			} else {
				lbal--;
			}
			l++;
		}
		while (r > optr) {
			if (s[get(r)] == ')') {
				rbal++;
			} else {
				rbal--;
			}
			r--;
		}
 		ans.pb(mp(optl, optr));
	
		sum += (sz(ans) & 1 ? optl + optr: -optl -optr);
		
	}
	if (sz(ans) > 2) {
		int bal = 0;
		int pos = -1;
		int opt = -1;
		for (int i = 0; i < sz(s); i++) {
			if (s[i] == '(') {
				bal++;
				if (bal > opt) {
					opt = bal;
					pos = i;
				}
			} else if (s[i] == ')') {
				bal--;
			}
		}
		cout <<2 << '\n';
		cout << 1 << ' ' << pos + 1 << '\n';
		cout << pos + 2 << ' '  << sz(s) << '\n';
		return;
	}
	for (auto x: ans) {
		for (int i = x.first; i <= x.second - (i - x.first); i++) {
			swap(s[i], s[x.second - (i - x.first)]);
		}
	}
	bal = 0;
	for (auto x: s) {
		if (x == '(') {
			bal++;
		} else {
			bal--;
		}
		assert(bal >= 0);
	}
	cout << sz(ans) << '\n';
	for (auto x: ans) {
		cout << x.first + 1 << ' ' << x.second + 1 << '\n';
	}
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