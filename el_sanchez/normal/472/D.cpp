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
typedef long double ld; 

const long double pi = acos(-1.0);
const long double eps = 1e-6;
const int INF = 1E9;        
const ll LINF = 1E18;        
const int MAXN = 2111;
                  
int n, tmr;
int a[MAXN][MAXN], used[MAXN], par[MAXN];
ll dist[MAXN];
vi g[MAXN];

bool prim() {
	forn(i, n) {
		dist[i] = LINF;
		used[i] = 0;
	}
	dist[0] = 0;

	forn(i, n) {
		int id = -1;
		forn(j, n)
			if (!used[j] && (id == -1 || dist[id] > dist[j])) {
				id = j;	
			}
			
		if (id == -1)
			return 0;
		used[id] = 1;
		
		if (id != 0) {
			g[id].pb(par[id]);
			g[par[id]].pb(id);
		}
			
		forn(j, n) {
			if (!used[j])
				if (a[id][j] < dist[j]) {
					dist[j] = a[id][j];
					par[j] = id;
				}						
		} 		
	}	
	
	return 1;
}

bool dfs(int root, int v, ll h) {
	used[v] = tmr;
	if (h != a[root][v])
		return 0;
		
	for (auto w: g[v]) {
		if (used[w] != tmr && !dfs(root, w, h + a[v][w]))
			return 0;	
	}
	
	return 1;
}

int main() {

	cin >> n;
	forn(i, n)
		forn(j, n)
			scanf("%d", &a[i][j]);

	forn(i, n)
		if (a[i][i] != 0) {
			cout << "NO";
			return 0;
		}
	
	forn(i, n)
		forn(j, n)
			if (i != j && a[i][j] == 0) {
				cout << "NO";
				return 0;
			}
	
	forn(i, n)
		forn(j, n)
			if (a[i][j] != a[j][i]) {
				cout << "NO";
				return 0;
			}
	
	if (!prim()) {
		cout << "NO";
		return 0;			
	}
	/*
	forn(i, n)
		for (auto w: g[i])
			cout << i << ' ' << w << '\n';
	*/
	tmr = 100;
	forn(i, n) {
		tmr++;
		if (!dfs(i, i, 0)) {
			cout << "NO";
			return 0;
		}
	}	
	
	cout << "YES";
		
	return 0;
}