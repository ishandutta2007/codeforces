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
const int Mod = 998244353;


int sum(int a, int b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
	return ((ll)a * b) % Mod;
}


int powm(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = mul(res, a);
		}
		b >>= 1;
		a = mul(a, a);
	}
	return res;
}


int mdiv(int a, int b) {
	return mul(a, powm(b, Mod - 2));
}


const int MAXN = 200228;


int n;
int a[MAXN];
vector<int> where[MAXN];


void solve() {
	cin >> n;
	for (int i = 0; i <= n; i++) {
		where[i].clear();
	}
	for (int i = 0; i < n; i++)	{
		cin >> a[i];
		where[a[i]].pb(i);
	}
	int uk = 0;
	vector<int> st;
	while (uk < n) {
		int curl = uk;
		int curr = uk;
		int val = 0;
		for (int t = 0; t <= n + 1; t++) {
			auto it = lower_bound(all(where[t]), curl);
			if (it == where[t].end()) {
				val = t;
				break;
			}
			chkmax(curr, *it);
		}
		st.pb(val);
		uk = curr + 1;
	}
	cout << sz(st) << '\n';
	for (auto x: st) {
		cout << x << ' ';
	}
	cout << '\n';
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