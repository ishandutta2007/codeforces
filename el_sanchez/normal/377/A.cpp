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
const int MAXN = 555;

int n, m, x;
bool used[MAXN][MAXN];
string s[MAXN];
vector<pii> g[MAXN][MAXN];

bool dfs(int a, int b) {
	used[a][b] = 1;
	bool f = 1;
	for (auto v: g[a][b])
		if (!used[v.X][v.Y]) {
			if (!dfs(v.X, v.Y))
				f = 0;	
		}	
	
	if (x > 0 && f) {
		s[a][b] = 'X';
		x--;
		return 1;	
	}
	return 0;
}

int main() {

	cin >> n >> m >> x;
	forn(i, n) {
		cin >> s[i];
	}			
	forn(i, n)
		forn(j, m) {
			if (i != 0 && s[i][j] == '.' && s[i - 1][j] == '.')
				g[i][j].pb(mp(i - 1, j));
			if (i != n - 1 && s[i][j] == '.' && s[i + 1][j] == '.')
				g[i][j].pb(mp(i + 1, j));
			if (j != 0 && s[i][j] == '.' && s[i][j - 1] == '.')
				g[i][j].pb(mp(i, j - 1));
			if (j != m - 1 && s[i][j] == '.' && s[i][j + 1] == '.')
				g[i][j].pb(mp(i, j + 1));
		}

	forn(i, n)
		forn(j, m)
			if (s[i][j] == '.') {
				if (x != 0)
					dfs(i, j);
				
				forn(i1, n)
					cout << s[i1] << '\n';
				return 0;
			}
	
	return 0;
}