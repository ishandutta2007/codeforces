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
const int MAXN = 1000228;
 

int n, k;
vector<ll> have[MAXN];
ll sum[MAXN];
ll ans;
ll dp[3050][3050];

 
void add(int v, int uk) {
	for (int i = 0; i <= k; i++) {
		dp[uk + 1][i] = dp[uk][i];
	}
	int r = sz(have[v]);
	for (int i = 0; i <= k - r; i++) {
		chkmax(dp[uk + 1][i + r], dp[uk][i] + sum[v]);
	}
}
 

void calc(int a, int b, int g) {
	if (a == b) {
		ll suma = 0;
		for (int i = 0; i <= sz(have[a]) && i <= k; i++) {
			chkmax(ans, suma + dp[g][k - i]);
			if (i < sz(have[a])) {
				suma += have[a][i];
			}
		}
		return;
	}
	int s = (a + b) >> 1;
	{
		int p = g;
		for (int i = a; i <= s; i++) {
			add(i, p);
			p++;
		}
		calc(s + 1, b, p);
	}
	{
		int p = g;
		for (int i = s + 1; i <= b; i++) {
			add(i, p);
			p++;
		}
		calc(a, s, p);
	}
}

 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int m;
		cin >> m;
		for (int j = 0; j < m; j++) {
			int w;
			cin >> w;
			have[i].pb(w);
			sum[i] += w;
		}
	}
	calc(1, n, 0);
	cout << ans << '\n';
	return 0;
}