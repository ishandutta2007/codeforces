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
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { x = (x > y ? y: x);}
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { x = (x < y ? y: x);}
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left224
#define right right224
#define next next224
#define rank rank224
#define prev prev224
#define y1 y1224
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
const string FILENAME = "input";
const int MAXN = 200228;



int n;
ll s[MAXN];


struct rmq {
	vector<pair<ll, int> > d;
	vector<ll> mod;
	int ss = 1;
	void calc(int v) {
		d[v] = min(d[v * 2], d[v * 2 + 1]);
	}
	void init(int n) {
		while (ss < n) {
			ss <<= 1;
		}
		d.resize(2 * ss);
		mod.resize(2 * ss);
		for (auto &x: d) {
			x.first = 0;
			x.second = 0;
		}
		for (int i = ss; i < ss + n; i++) {
			d[i].second = ss - i;
		}
		for (int i = ss + n; i < 2 * ss; i++) {
			d[i].first = 1e18;
		}
		for (int j = ss - 1; j >= 1; j--) {
			calc(j);
		}
		for (auto &x: mod) {
			x = 0;
		}
	}
	void push(int v) {
		if (mod[v] != 0) {
			d[v].first += mod[v];
			if (v < ss) {
				mod[v * 2] += mod[v];
				mod[v * 2 + 1] += mod[v];
			}
			mod[v] = 0;
		}
	}
	void add(int v, int vl, int vr, int l, int r, ll x) {
		if (vl > r || vr < l) {
			push(v);
			return;
		}
		if (l <= vl && vr <= r) {
			mod[v] += x;
			push(v);
			return;
		}
		push(v);
		add(v * 2, vl, (vl + vr) / 2, l, r, x);
		add(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, x);
		calc(v);
	}
} kek;



int p[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME); 
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> s[i];
    }
    kek.init(n);
    for (int i = 0; i < n; i++) {
    	kek.add(1, 1, kek.ss, i + 1, i + 1, s[i]);
    }
    for (int i = 1; i <= n; i++) {
    	auto x = kek.d[1].second;
    	x *= -1;
    	p[x] = i;
    	kek.add(1, 1, kek.ss, x + 1, n, -i);
    	kek.add(1, 1, kek.ss, x + 1, x + 1, 1e13);
    }	
    for (int i = 0; i < n; i++) {
    	cout << p[i] << ' ';
    }
    cout << '\n';
    return 0;  
}