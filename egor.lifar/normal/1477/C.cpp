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
const int MAXN = 5028;

struct Point
{
    ll x, y;
    Point(){}
    Point(ll _x, ll _y): x(_x), y(_y){}
};


Point operator -(const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y);
} 



Point operator +(const Point &a, const Point &b) {
    return Point(a.x + b.x, a.y + b.y);
} 


ll vec(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}


ll scal(const Point &a, const Point &b) {
	return a.x * b.x + a.y * b.y;
}



int n;
Point p[MAXN];


bool ok(int a, int b, int c) {
	ll f = scal(p[a] - p[b], p[c] - p[b]);
	if (f <= 0) {
		return false;
	}
	return true;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    //read(FILENAME);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
	}
	vector<int> st;
	for (int i = 0; i < n; i++) {
		st.pb(i);
		int cur = sz(st) - 1;
		while (cur >= 2) {
			int fa = st[cur + 1 - 3];
			int fb = st[cur + 1 - 2];
			int fc = st[cur + 1 - 1];
			if (ok(fa, fb, fc)) {
				cur--;
				continue;
			}
			vector<int> order;
			order.pb(fa);
			order.pb(fb);
			order.pb(fc);
			sort(all(order));
			bool was = false;
			do {
				st[cur + 1 - 3] = order[0];
				st[cur + 1 - 2] = order[1];
				st[cur + 1 - 1] = order[2];
				if (ok(st[cur + 1 - 3], st[cur + 1 - 2], st[cur + 1 - 1])) {
					if (cur + 1 >= sz(st) || ok(st[cur + 1 - 2], st[cur + 1 - 1], st[cur + 1])) {
						if (cur + 2 >= sz(st) || ok(st[cur + 1 - 1], st[cur + 1], st[cur + 2])) {
							was = true;
							break;
						}
					}
				}
			} while (next_permutation(all(order)));
			if (!was) {
				order.clear();
				order.pb(fa);
				order.pb(fb);
				order.pb(fc);
				order.pb(st[cur + 1]);
				sort(all(order));
				bool was = false;
				do {
					st[cur + 1 - 3] = order[0];
					st[cur + 1 - 2] = order[1];
					st[cur + 1 - 1] = order[2];
					st[cur + 1] = order[3];
					if (ok(st[cur + 1 - 3], st[cur + 1 - 2], st[cur + 1 - 1])) {
						if (cur + 1 >= sz(st) || ok(st[cur + 1 - 2], st[cur + 1 - 1], st[cur + 1])) {
							if (cur + 2 >= sz(st) || ok(st[cur + 1 - 1], st[cur + 1], st[cur + 2])) {
								if (cur + 3 >= sz(st) || ok(st[cur + 1], st[cur + 2], st[cur + 3])) {
									was = true;
									break;
								}
							}
						}
					}
				} while (next_permutation(all(order)));
				assert(was);
			}
			cur--;
		}
	}
	for (int i = 0; i < sz(st) - 2; i++) {
		assert(ok(st[i], st[i + 1], st[i + 2]));
	}
	for (auto x: st) {
		cout << x + 1 << ' ';
	}
	cout << '\n';
   	return 0;
}