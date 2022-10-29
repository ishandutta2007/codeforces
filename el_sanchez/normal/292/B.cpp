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
const int MAXN = 200500;

int n, m, a, b, st[MAXN], used[MAXN], cmp;
vector<vi> g;

void dfs(int v) {
	used[v] = 1;
	forn(i, g[v].size()) {
		int w = g[v][i];
		if (!used[w])
			dfs(w);
	}
}

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> n >> m;
	g.resize(n);
	forn(i, m) {
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	forn(i, n)
		st[g[i].size()]++;
	cmp = 0;
	forn(i, n)
		if (!used[i]) {
			cmp++;
			dfs(i);
		}

	if (st[1] == 2 && st[2] == n - 2 && cmp == 1)
		cout << "bus";
	else if (st[2] == n && cmp == 1)
		cout << "ring";
	else if (st[1] == n - 1 && st[n - 1] == 1 && cmp == 1)
		cout << "star";
	else
		cout << "unknown";
	cout << " topology";


    return 0;
}