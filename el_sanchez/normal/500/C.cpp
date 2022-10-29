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
const int MAXN = 555;
        
int n, m, q, qq[MAXN * 3];
int w[MAXN], a[MAXN], used[MAXN];
int sz, order[MAXN];

int main() {

	cin >> n >> m;
	forn(i, n)
		cin >> w[i];
	
	sz = 0;
	forn(i, m) {
		cin >> q;
		q--;
		qq[i] = q;
		if (!used[q]) {
			order[sz++] = q;
			used[q] = 1;
		}		
	}	
	
	forn(i, n)
		if (!used[i])
			order[sz++] = i;

	assert(sz == n);
		
	ll ans = 0;
	forn(i, m) {
		q = qq[i];
		forn(j, n + 1) {
			assert(j != n);
			if (order[j] != q)
				ans += w[order[j]];
			else {
				for (int k = j; k > 0; k--)
					order[k] = order[k - 1];
				order[0] = q;
				break;	 
			}
		}
		
	}
	
	cout << ans;
		
   	return 0;
}