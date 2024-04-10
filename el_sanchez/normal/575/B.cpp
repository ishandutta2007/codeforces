//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
/*
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <complex>
#include <map>
#include <set>
#include <cassert>
#include <ctime>
*/			   
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9; 
const int MAXN = 100500;
const int MAXPW = 1005000;
const int MAXK = 21;
const int MOD = 1E9 + 7;

int n, k, a, b, c;
int used[MAXN];
vector<pii> g[2][MAXN];
ll pw2[MAXPW];

int tmr;
int h[MAXN], tin[MAXN], tout[MAXN], par[MAXN][MAXK];

void dfs(int v, int from, int ch) {
	h[v] = ch;
	tin[v] = tmr++;
	par[v][0] = from;
	forab(i, 1, MAXK)
		par[v][i] = par[par[v][i - 1]][i - 1];

	for (auto p: g[0][v]) {
		int to = p.X;
		if (from != to)
			dfs(to, v, ch + 1);
	}
	tout[v] = tmr++;
}

bool parent(int a, int b) {
	return (tin[a] <= tin[b] && tin[b] <= tout[a]);
}

int lca(int a, int b) {
	if (parent(a, b)) return a;
	if (parent(b, a)) return b;
	for (int i = MAXK - 1; i >= 0; i--)
		if (!parent(par[a][i], b))
			a = par[a][i];
	return par[a][0];
}

ll ans;
int st[2][MAXN], fn[2][MAXN], sumSt[2][MAXN], sumFn[2][MAXN];

void dfsSum(int v, int par, int id) {
	sumSt[id][v] = st[id][v];
	sumFn[id][v] = fn[id][v];
	for (auto p: g[id][v]) {
		int w = p.X;
		if (w != par) {
			dfsSum(w, v, id);
			sumSt[id][v] += sumSt[id][w];
			sumFn[id][v] += sumFn[id][w];
		}
	}
}

void dfsCount(int v, int par, int id) {
	for (auto p: g[id][v]) {
		int w = p.X;
		if (w != par) {
			int cnt = sumSt[id][w] - sumFn[id][w];
		 	assert(cnt >= 0 && cnt < MAXPW);
			//cout << v << " -> " << w << " cost " << p.Y << '\n';
			//cout << "added " << sum + add[id][w] << '\n';
			if (p.Y) {
				ans = (ans + pw2[cnt] + MOD - 1) % MOD;
			}
			dfsCount(w, v, id);
		}
	}
}

int main() {

	cin >> n;
	forn(i, n - 1) {
		scanf("%d%d%d", &a, &b, &c);
		a--, b--;
		g[0][a].pb({b, 0});
		g[1][b].pb({a, 0});
		
		if (c == 0) {
			g[1][a].pb({b, 0});
			g[0][b].pb({a, 0});
		} else {
			g[1][a].pb({b, 1});
			g[0][b].pb({a, 1});
		}
	}	
	        	
	dfs(0, 0, 0);
	
	//cout << "lca\n";
	
	scanf("%d", &k);
	int now = 0, prv;
	forn(i, k) {
		prv = now;
		scanf("%d", &now);
		now--;
		
		//cout << "new\n";
		
		int root = lca(now, prv);
		st[1][prv]++;
		fn[1][root]++;
		
		st[0][now]++;
		fn[0][root]++;		
	}

	pw2[0] = 1;
	forab(i, 1, MAXPW) {
		pw2[i] = (pw2[i - 1] * 2) % MOD;	
	}
	/*
	forn(i, numComp)
		for (auto w: g2[i])
			cout << i << " -> " << w << '\n';
	*/		
	/*
	forn(i, numComp)
		cout << add[i] << '\n';
	*/
	
	ans = 0;	
	forn(i, 2) {
		dfsSum(0, 0, i);
		dfsCount(0, 0, i);
	}
	cout << ans;
	
	return 0;
}