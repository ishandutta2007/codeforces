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
                  
int n, ans;
vi a;
vector<pair<int, pii> > p;

int main() {

	cin >> n;
	a.resize(n);
	forn(i, n)
		cin >> a[i];
		
	p.pb(mp(1, mp(0, 0)));
	for (int i = 1; i < n; i++) {
		if (a[i - 1] < a[i]) {
			p.back().X++;
			p.back().Y.Y = i;
		} else {
			p.pb(mp(1, mp(i, i)));
		}
	}
	
	ans = 0;
	forn(i, p.size())
		ans = max(ans, min(p[i].X + 1, n));
	forn(i, p.size() - 1)
		if (p[i].X >= 2 && a[p[i].Y.Y - 1] + 2 <= a[p[i + 1].Y.X])
			ans = max(ans, p[i].X + p[i + 1].X);
			
	forn(i, p.size() - 1)
		if (p[i + 1].X >= 2 && a[p[i].Y.Y] + 2 <= a[p[i + 1].Y.X + 1])
			ans = max(ans, p[i].X + p[i + 1].X);
			
	forn(i, p.size() - 2)
		if (p[i + 1].X == 1 && a[p[i].Y.Y] + 2 <= a[p[i + 2].Y.X])
			ans = max(ans, p[i].X + 1 + p[i + 2].X);	
	
	cout << ans;
	
	return 0;
}