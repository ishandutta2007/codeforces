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
const int MAXN = 1005;


int h;
int l[MAXN];
int v;
int p[MAXN];
bitset<1000228> can[MAXN];


void solve() {
	cin >> h;
	int sum = 0;
	for (int i = 0; i < h; i++) {
		cin >> l[i];
		sum += l[i];
	}
	cin >> v;
	int sum1 = 0;
	for (int i = 0; i < v; i++) {
		cin >> p[i];
		sum1 += p[i];
	}
	if (h != v || sum & 1 || sum1 & 1) {
		cout << "No\n";
		return;
	}
	can[0].reset();
	can[0][0] = true;
	for (int i = 0; i < h; i++) {
		can[i + 1] = (can[i] << l[i]) | can[i];
	}
	if (!can[h][sum >> 1]) {
		cout << "No\n";
		return;
	}
	int need = sum / 2;
	vector<int> st, st1;
	for (int i = h; i >= 1; i--) {
		if (need >= l[i - 1] && can[i - 1][need - l[i - 1]]) {
			st.pb(l[i - 1]);
			need -= l[i - 1];
		} else {
			st1.pb(l[i - 1]);
		}
	}
	can[0].reset();
	can[0][0] = true;
	for (int i = 0; i < v; i++) {
		can[i + 1] = (can[i] << p[i]) | can[i];
	}
	if (!can[v][sum1 >> 1]) {
		cout << "No\n";
		return;
	}
	need = sum1 / 2;
	vector<int> st2, st3;
	for (int i = v; i >= 1; i--) {
		if (need >= p[i - 1] && can[i - 1][need - p[i - 1]]) {
			st2.pb(p[i - 1]);
			need -= p[i - 1];
		} else {
			st3.pb(p[i - 1]);
		}
	}
	sort(all(st));
	sort(all(st1));
	sort(all(st2));
	sort(all(st3));
	if (sz(st) < sz(st1)) {
		swap(st, st1);
	}
	if (sz(st2) < sz(st3)) {
		swap(st2, st3);
	}
	cout << "Yes\n";
	if (sz(st) > sz(st2)) {
		reverse(all(st2));
		reverse(all(st1));
		reverse(all(st));
		int cx = 0;
		int cy = 0;
		for (int i = 0; i < sz(st2); i++) {
			cy += st2[i];
			cout << cx << ' ' << cy << '\n';
			cx += st.back();
			cout << cx << ' ' << cy << '\n';
			st.pop_back();
		}
		for (int i = 0; i < sz(st3); i++) {
			cy -= st3[i];
			cout << cx << ' ' << cy << '\n';
			if (!st.empty()) {
				cx += st.back();
				cout << cx << ' ' << cy << '\n';
				st.pop_back();
			} else {
				cx -= st1.back();
				cout << cx << ' ' << cy << '\n';
				st1.pop_back();
			}
		}
	} else {
		reverse(all(st));
		reverse(all(st3));
		reverse(all(st2));
		int cx = 0;
		int cy = 0;
		for (int i = 0; i < sz(st); i++) {
			cx += st[i];
			cout << cx << ' ' << cy << '\n';
			cy += st2.back();
			cout << cx << ' ' << cy << '\n';
			st2.pop_back();
		}
		for (int i = 0; i < sz(st1); i++) {
			cx -= st1[i];
			cout << cx << ' ' << cy << '\n';
			if (!st2.empty()) {
				cy += st2.back();
				cout << cx << ' ' << cy << '\n';
				st2.pop_back();
			} else {
				cy -= st3.back();
				cout << cx << ' ' << cy << '\n';
				st3.pop_back();
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}