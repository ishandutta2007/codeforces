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
const int MAXN = 22;
const ll MOD = 1E9 + 7;
    
int n, k, d;
vector<pair<pii, pii> > ans;

int main() {

	cin >> n >> k;
	d = 1;
	for (int i = 1; i <= n; i++) {
		ans.pb(mp(mp(d, d + 1), mp(d + 2, d + 4)));
		d += 6;
	}
	
	forn(i, ans.size()) {
		ans[i].X.X *= k;
		ans[i].X.Y *= k;
		ans[i].Y.X *= k;
		ans[i].Y.Y *= k;
	}
	
	cout << ans.back().Y.Y << '\n';
	forn(i, ans.size()) {
		printf("%d %d %d %d\n", ans[i].X.X, ans[i].X.Y, ans[i].Y.X, ans[i].Y.Y);	
	}
	
	return 0;
}