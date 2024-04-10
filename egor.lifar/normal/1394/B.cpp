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
#include <complex>


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
const int MAXN = 200228;



int n, m, k;
vector<pair<int, int> > g[MAXN];
vector<pair<int, int> > in[MAXN];
ll hsh[MAXN];
mt19937 as;
ll add[10][10];
ll sum = 0;
ll need = 0;
ll ans = 0;


void get(int i) {
	if (i == k + 1) {
		if (sum == need) {
			ans++;
		}
		return;
	}
	for (int j = 1; j <= i; j++) {
		sum += add[i][j];
		get(i + 1);
		sum -= add[i][j];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a].pb(mp(c, b));
	}
	for (int i = 1; i <= n; i++) {
		sort(all(g[i]));
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < sz(g[i]); j++) {
			in[g[i][j].second].pb(mp(sz(g[i]), j + 1));
		}
		hsh[i] = ((ll)as() << 30) + as();
		need += hsh[i];
	}
	for (int i = 1; i <= n; i++) {
		for (auto x: in[i]) {
			add[x.first][x.second] += hsh[i];
		}
	}
	get(1);
	cout << ans << '\n';
}