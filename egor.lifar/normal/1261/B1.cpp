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
const int MAXN = 200228;


int n, m;
int a[MAXN], as[MAXN];
vector<pair<int, int> > g[MAXN];
map<int, vector<int> > where;
int d[MAXN];
int res[MAXN];



void inc(int i, int val) {
	for (int j = i; j < n; j |= (j + 1)) {
		d[j] += val;
	}
}


int get(int i) {
	int res = 0;
	for (int j = i; j >= 0; j = (j & (j + 1)) - 1) {
		res += d[j];
	}
	return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  	//read(FILENAME);
  	cin >> n;
  	for (int i = 0; i < n; i++) {
  		cin >> a[i];
  		as[i] = a[i];
  		where[a[i]].pb(i);
  	}
  	sort(a, a + n);
  	cin >> m;
  	for (int it = 0; it < m; it++) {
  		int k, c;
  		cin >> k >> c;
  		g[k].pb({c, it});
  	}
  	for (int i = 0; i < n; i++) {
  		inc(i, 1);
  	}
  	for (int i = n; i >= 1; i--) {
  		for (auto x: g[i]) {
  			int j = x.first;
  			int l = 0;
  			int r = n - 1;
  			while (l < r) {
  				int mid = (l + r) >> 1;
  				if (get(mid) >= j) {
  					r = mid;
  				} else {
  					l = mid + 1;
  				}
  			}
  			res[x.second] = as[l];
   		}
  		int val = a[n - i];
  		int x = where[val].back();
  		where[val].pop_back();
  		inc(x, -1);
  	} 
  	for (int it = 0; it < m; it++) {
  		cout << res[it] << '\n';
  	}
}