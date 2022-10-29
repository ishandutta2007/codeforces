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
const int MAXN = 1111;

int t;
int n, m, p;
vi g[MAXN];

int main() {

	cin >> t;
	forn(tt, t) {
		cin >> n >> p;
		m = 2 * n + p;
		
		int k = 1;
		while (k * (k - 1) / 2 < 2 * k + p)
			k++;
		
		forn(i, n)
			g[i].clear();
		
		int sz = 2 * k + p;
		forn(i, k) {
			forab(j, i + 1, k) {
				g[i].pb(j);
				sz--;
				if (sz == 0)
					break;
			}
			if (sz == 0)
				break;
		}		
		
		if (k != n) {
			int j = 0;
			for (int i = k; i < n; i++) {
				g[i].pb(i - 1);
				g[i].pb(j);
				j++;
			}
		}
		
		forn(i, n)
			for (auto j: g[i])
				cout << i + 1 << ' ' << j + 1 << '\n';
	}
	return 0;
}