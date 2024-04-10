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
// const int MAXMEM = 200 * 1000 * 1024;
// char _memory[MAXMEM];
// size_t _ptr = 0;
// void* operator new(size_t _x) { _ptr += _x; return _memory + _ptr - _x; }
// void operator delete (void*) noexcept {}
const string FILENAME = "input";
const int MAXN = 2505;
 
 
struct point
{
	ll x, y;
	point(){}
	point(ll _x, ll _y) {
		x = _x;
		y = _y;
	}
};
 
 
point operator -(const point &a, const point &b) {
	return point(a.x - b.x, a.y - b.y);
}
 
 
 
bool operator ==(const point &a, const point &b) {
	return a.x == b.x && a.y == b.y;
}
 
int n;
point p[MAXN];
 
 
 
int get(const point &a) {
	if (a.y > 0 || (a.y == 0 && a.x > 0)) {
		return 1;
	}
	return 0;
}
 
 
ll vec(const point &a, const point &b) {
	return a.x * b.y - a.y * b.x;
}
 
 
bool comp(const pair<point, int> &a, const pair<point, int> &b) {
	int s = get(a.first);
	int s1 = get(b.first);
	if (s != s1) {
		return s < s1;
	}
	return vec(a.first, b.first) > 0;
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> p[i].x >> p[i].y;
    }
    ll res = 0;
    for (int i = 0; i < n; i++) {
    	ll k = ((ll)(n - 1) * (n - 2) * (n - 3) * (n - 4)) / 24;
    	//cout << k << endl;
    	vector<pair<point, int> > st;
    	for (int j = 0; j < n; j++) {
    		if (i == j) {
    			continue;
    		}
    		point q = p[j] - p[i];
    		st.pb({q, 1});
    		st.pb({point(-q.x, -q.y), 0});
    	}
    	sort(all(st), comp);
    	ll s = 0;
    	int uk = 0;
    	ll sum = st[0].second;
    	for (int i = 0; i < sz(st); i++) {
    		point g = point(-st[i].first.x, -st[i].first.y);
    		while (st[uk] != mp(g, st[i].second ^ 1)) {
    			uk++;
    			uk %= sz(st);
    			sum += st[uk].second;
    		}
    		sum -= st[i].second;
    		if (st[i].second == 1) {
    			s += sum * (sum - 1) * (sum - 2) / 6;
    		}
    	}
    	//cout << s << endl;
    	res += k - s;
    }
    cout << res << '\n';
}