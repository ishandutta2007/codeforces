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
#include <cfloat>

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
const int MAXN = 1111;

int n, t, k;
vector<vi> g;
vi used;

bool dfs(int v) {
	if (v == t)
		return 1;
	if (g[v].empty())
		return 0;
	return dfs(g[v][0]);
}

int main() {

	cin >> n >> t;
	g.resize(n + 2);
	forn(i, n - 1) {
		cin >> k;
		g[i + 1].pb(i + 1 + k);	
	}		
	used.resize(n + 2, 0);
	if (dfs(1))
		cout << "YES";
	else
		cout << "NO";
	
	return 0;
}