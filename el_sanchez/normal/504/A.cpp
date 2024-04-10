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
const int INF = 1E6;
const int MAXN = 300500;      

int n, a, b;
int deg[MAXN], sum[MAXN];
set<pii> lib;
vector<pii> edges;

int main() {

	cin >> n;
	forn(i, n) {
		cin >> deg[i] >> sum[i];
		lib.insert({deg[i], i}); 	
	}
		
	while (!lib.empty()) {
		pii p = *lib.begin();
		lib.erase(p);

		int v = p.Y;
		
		if (deg[v] >= 2)
			assert(false);
		if (deg[v] == 0)
			continue;
		int w = sum[v];
		sum[w] ^= v;
		
		//cout << v << ' ' << w << '\n';
		
		lib.erase({deg[w], w});
		deg[w]--;
		if (deg[w] > 0)
			lib.insert({deg[w], w});
		
		edges.pb({v, w});		
	}
	
	cout << edges.size() << '\n';
	for (auto e: edges)
		cout << e.X << ' ' << e.Y << '\n';
			return 0;
}