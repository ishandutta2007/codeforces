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
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}


const int MAXN = 200228;


int n;
int w[MAXN];
vector<int> g[MAXN];
ll add[MAXN];


void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> w[i];
		g[i].clear();
	}
	for (int it = 0; it < n - 1; it++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	for (int i = 1; i <= n; i++) {
		add[i] = 0;
	}
	vector<int> st;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 2; j <= sz(g[i]); j++) {
			st.pb(w[i]);
		}
		sum += w[i];
	}
	sort(all(st));
	reverse(all(st));
	int uk = 0;
	for (int i = 0; i < n - 1; i++) {
		if (i) {
			sum += st[uk];
			uk++;
		}
		cout << sum << ' ';
	}	
	cout << '\n';
} 


int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
 	int t;
 	cin >> t;
 	while (t--) {
 		solve();
 	}
   	return 0;
}