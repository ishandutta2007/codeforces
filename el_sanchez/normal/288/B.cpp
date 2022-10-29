#pragma comment(linker, "/STACK:67108864")

#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <complex>
#include <bitset>
#include <map>
#include <set>
#include <ctime>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for(int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for(int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 10;
const int MAXMASK = 1 << 8;
const ll MOD = 1E9 + 7;

int n, k, a[MAXN], used[MAXN], mask, tmr;
ll nn, v, ans;
int link[MAXN][MAXN], sz[MAXN], c[MAXN], csz;

const ll m[] = {1, 2, 9, 64, 625, 7776, 117649, 2097152};
/*
inline void dfs(int v) {
	used[v] = tmr;
	mask += (1 << v);
	forn(i, sz[v])
		if (used[link[v][i]] != tmr)
			dfs(link[v][i]);
}

inline void get(int v) {
	if (v == k) {
		mask = 0;
		tmr++;
		dfs(0);
		if (mask == (1 << k) - 1)
			ans++;
		return;
	}

	forn(i, k) {
		a[v] = i;
		link[i][sz[i]++] = v;
		get(v + 1);
		sz[i]--;
	}
}
*/
int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> n >> k;
	ans = 0;
	//get(0);
	ans = m[k - 1];
	nn = n - k;
	for (ll i = k + 1; i <= n; i++) {
		ans *= nn;
		ans %= MOD;
	}
	cout << ans << '\n';

    return 0;
}