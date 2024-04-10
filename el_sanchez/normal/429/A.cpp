#include <iostream>
#include <fstream> 
#include <cstdio>
#include <vector>
#include <queue>
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

using namespace std;

typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 100500;
                
int n, u, v, ans;
vi g[MAXN];
int a[MAXN], dp[MAXN][2];
vi st, steps;
vi childs[MAXN];

void dfs(int v, int p) {
	st.pb(v);
	if (st.size() >= 3)
		childs[st[st.size() - 3]].pb(st.back());		
	
	for (auto w: g[v]) {
		if (w != p) {
			dfs(w, v);	
		}
	}		
	
	st.pop_back();}

void solve(int v, int p, int x) {
	int xx;
	if (x == a[v]) {
		xx = x;
	} else {
		xx = x ^ 1;
		steps.pb(v);	
	}
			
	for (auto w: childs[v])
		if (w != p)
			solve(w, v, xx);
}
int main() {

	cin >> n;
	forn(i, n - 1) {
		cin >> u >> v;
		u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	forn(i, n)
		cin >> a[i];
	forn(i, n) {
		cin >> u;
		a[i] ^= u;
	}
	
	dfs(0, 0);
	
	solve(0, 0, 0);
	for (auto w: g[0])
		solve(w, w, 0);
		
	cout << steps.size() << '\n';
	forn(i, steps.size())
		cout << steps[i] + 1 << '\n';
		
	return 0;
}