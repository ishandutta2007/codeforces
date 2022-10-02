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
const string FILENAME = "input";



ll gcd(ll a, ll b) {
	while (b) {
		a %= b;
		swap(a, b);
	} 
	return a;
}
 
pair<pair<ll, ll>, ll> sig(vector<ll> a) {
	ll r1 = a[1] - a[0];
	ll r2 = a[2] - a[1];
	ll r3 = a[3] - a[2];
	ll g = gcd(gcd(r1, r2), r3);
	if (g == 0) {
		return {{0, a[0]}, 0};
	}
	ll f = ((a[0] % g) + g) % g;
	ll res = 0;
	for (int j = 0; j < 4; j++) {
		res += ((a[j] - f) / g) & 1;
	}
	return {{g, f}, res};
}
 

bool inside(ll x, ll a, ll b){
	return (a <= x && x <= b) || (b <= x && x <= a);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 //   read(FILENAME);	
    function<void(vector<ll>&, vector<pair<ll, ll> >&)> solve;
	solve = [&](vector<ll>& v, vector<pair<ll, ll> >& moves) {
		auto make = [&](int i, int j) {
			moves.pb({v[i], v[j]});
			v[i] = 2 * v[j] - v[i];
		};
		while (true) {
			sort(all(v));
			if (v[0] == v[3]) {
			} else if (v[0] + 1 < v[3]) {
				ll target = (v[3] - v[0]) / 8;
				for (int j = 1; j <= 2; j++) {
					if (v[j] - v[0] > target && v[3] - v[j] > target) {
						if(v[3] - v[j] > v[j] - v[0]) {
							make(0, j); 
							goto done;
						} else {
							make(3, j); 
							goto done;
						}
					}
				}
				if (v[1] - v[0] > target) {
					make(3, 1); 
					continue;
				}
				if (v[3] - v[2] > target) {
					make(0, 2); 
					continue;
				}
				if (v[2] - v[1] > target) {
					if (v[1] - v[0] > v[3] - v[2]) {
						make(2, 1); 
						make(2, 0); 
						continue;
					} else {
						make(1, 2); 
						make(1, 3); 
						continue;
					}
				}
			} else if (v[0] == 0) {
			} else if (v[3] == 0 && v[0] < 0) {
				for (int i = 0; i < 3; i++) {
					make(i, 3);
				}
				continue;
			} else if (v[1] != v[2]) {
				if (v[0] > 0 && v[0] == v[2]) {
					make(3, 0); 
					sort(all(v));
				}
				if (v[3] < 0 && v[1] == v[3]) {
					make(0, 3); 
					sort(all(v));
				}
				while (v[3] < 0) {
					make(1, 3); 
					sort(all(v));
				}
				while (v[0] > 0) {
					make(2, 0); 
					sort(all(v));
				}
				while (v[0] + 1 < v[3]) {
					if (v[2] >= 0) {
						make(3, 2); 
						sort(all(v));
					} else if (v[1] <= 0) {
						make(0, 1); 
						sort(all(v));						
					}
				}
				continue;
			} else {
				if (v[0] == v[2] && v[3] > 0) {
					make(3, 0);
				}
				if (v[1] == v[3] && v[0] < 0) {
					make(0, 3);
				}
				sort(all(v));
				bool flag = false;
				if (v[0] != v[2]) {
					flag = true;
				}
				if (flag) {
					reverse(all(v));
				}
				while (!inside(0, v[0], v[3])) {
					make(1, 3); 
					sort(all(v)); 
					if (flag) {
						reverse(all(v));
					}
				}
				while (abs(v[0] - v[3]) > 1){
					make(3, 2); 
					sort(all(v)); 
					if (flag) {
						reverse(all(v));
					}
					while (!inside(0, v[0], v[3])){
						make(0, 3);
						make(1, 3);
						make(2, 3);
						flag = !flag;
					}
				}
				sort(all(v));
				continue;
			}
			break;
			done:;
			continue;
		}
	};
	vector<vector<ll> > a(2, vector<ll>(4));
	for (int x = 0; x < 2; x++) {
		for (int i = 0; i < 4; i++) {
			cin >> a[x][i];
		}
		sort(all(a[x]));
	}
	if (sig(a[0]) != sig(a[1])) {
		cout << -1 << '\n';
		return 0;
	}
	ll g = sig(a[0]).first.first;
	ll f = sig(a[0]).first.second;
	if (g == 0) {
		cout << 0 << '\n';
		return 0;
	}
	for (int j = 0; j < 2; j++) {
		for (auto &x: a[j]) {
			x = (x - f) / g;
		}
	}
	vector<vector<pair<ll, ll> > > moves(2);
	solve(a[0], moves[0]);
	solve(a[1], moves[1]);
	for (auto & x: moves[1]) {
		x.first = x.second * 2 - x.first;
	}
	reverse(all(moves[1]));
	moves[0].insert(moves[0].end(), all(moves[1]));
	vector<pair<ll, ll> > res;
	for (auto x: moves[0]) {
		if (x.first == x.second) {
			continue;
		}
		res.push_back(x);
	}
	cout << sz(res) << '\n';
	for (auto x: res) {
		if (x.first == x.second) {
			continue;
		}
		cout << x.first * g + f << ' ' << x.second * g + f << '\n';
	}
}