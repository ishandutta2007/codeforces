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


const int MAXN = 200228;


int n;
int a[MAXN];
int b[MAXN];
vector<int> where[MAXN];
vector<int> bucket[MAXN];
map<vector<int>, int> dist;


void checker() {
	queue<vector<int> > q;
	vector<int> d;
	for (int i = 0; i < n; i++) {
		d.pb(a[i]);
	}
	q.push(d);
	dist.clear();
	dist[d] = 0;
	int ans = 0;
	int maxd = 0;
	while (!q.empty()) {
		auto f = q.front();
		q.pop();
		chkmax(maxd, dist[f]);
		int res = dist[f] + 1;
		for (int i = 0; i < sz(f) - 1; i++) {
			for (int j = i + 1; j < sz(f); j++) {
				swap(f[i], f[j]);
				if (dist.find(f) == dist.end()) {
					dist[f] = res;
					q.push(f);
				}
				swap(f[i], f[j]);
			}
		}
	}
	vector<int> d1;
	for (int i = 0; i < n; i++) {
		d1.pb(b[i]);
	}
	assert(dist[d1] == maxd);
}

mt19937 as;

void solve() {
	cin >> n;
	//cerr << "opa" << endl;
	//n = 7;
	for (int i = 0; i <= n; i++) {
		where[i].clear();
		bucket[i].clear();
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		//a[i] = as() % n + 1;
		where[a[i]].pb(i);
		b[i] = a[i];
	}
	vector<pair<int, int> > st;
	for (int i = 1; i <= n; i++) {
		if (sz(where[i]) >= n - sz(where[i])) {
			for (int j = 1; j <= n; j++) {
				if (j != i) {
					for (auto x: where[j]) {
						b[where[i].back()] = j;
						b[x] = i;
						where[i].pop_back();
					}
				}
			}
			for (int i = 0; i < n; i++) {
				cout << b[i] << ' ';
			}
			cout << '\n';
			//checker();
			return;
		}
		st.pb(mp(sz(where[i]), i));
	}
	sort(all(st));
	reverse(all(st));
	vector<int> order;
	for (auto xx: st) {
		int i = xx.second;
		for (int j = 0; j < sz(where[i]); j++) {
			bucket[j].pb(where[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (auto x: bucket[i]) {
			order.pb(x);
		}
	}
	for (int i = 0; i < sz(order); i++) {
		b[order[i]] = a[order[(i + 1) % n]];
	}
	for (int i = 0; i < n; i++) {
		cout << b[i] << ' ';
	}
	cout << '\n';
	//checker();
}		


int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;
	t = 10000;
	cin >> t;
	while (t--) {
	//	cerr << t << endl;
		solve();
	}
}