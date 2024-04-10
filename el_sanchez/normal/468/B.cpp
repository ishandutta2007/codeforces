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
const int MAXN = 100500;                   
                  
int n, a[2];
vi p, ans, used, deg;
int nxt[MAXN][2];
map<int, int> lib;

bool dfs(int v, int rootclr) {
	used[v] = 1;
	if (!used[nxt[v][0]]) {
		if (!dfs(nxt[v][0], rootclr))
			return 0;
		ans[v] = rootclr;
		return 1;
	} else if (!used[nxt[v][1]]) {
		if (!dfs(nxt[v][1], rootclr))
			return 0;
		ans[v] = rootclr;
		return 1;
	} else {
		
		if (nxt[v][rootclr] == -1)
			return 0;
		else {
			ans[v] = rootclr;
			return 1;	
		}
	
	}

}

int main() {

	cin >> n >> a[0] >> a[1];
	p.resize(n);
	ans.resize(n, -1);
	forn(i, n) {
		cin >> p[i];
		lib[p[i]] = i;
	}
	
	memset(nxt, -1, sizeof(nxt));
	
	forn(i, 2) {
		forn(j, n) {
			if (lib.find(a[i] - p[j]) != lib.end())
				nxt[j][i] = lib[a[i] - p[j]];	
		}
	}
	/*
	forn(i, 2) {
		forn(j, n)
			cout << nxt[j][i] << ' ';
		cout << '\n';
	}
	*/
	deg.resize(n, 0);
	forn(i, n) {
		if (nxt[i][0] != -1)
			deg[i]++;
		if (nxt[i][1] != -1)
			deg[i]++;	
	}
	
	//no way
	forn(i, n)
		if (deg[i] == 0) {
			cout << "NO";
			return 0;
		}
	
	used.resize(n, 0);
	
	//paths
	forn(i, n)
		if (!used[i]) {
			if (deg[i] == 1) {
				int k = (nxt[i][0] != -1 ? 0 : 1);
				int nv = nxt[i][k];
				
				used[i] = 1;
				if (!dfs(nv, k)) {
					cout << "NO";
					return 0;
				} else
					ans[i] = k;
			}
		}
	
	//cycles
	forn(i, n)
		if (!used[i]) {
			if (deg[i] == 2) {
				ans[i] = 0;	
				used[i] = 1;
			}
		}
		
	forn(i, n)
		if (ans[i] == -1)
			assert(false);
	
	cout << "YES\n";
	forn(i, n)
		printf("%d ", ans[i]);
		
	return 0;
}