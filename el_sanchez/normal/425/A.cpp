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
const int MAXN = 222;
                
int n, m, sz;
int a[MAXN], b[MAXN];
int ans, cur;
vi minIn, maxOut;

int main() {

	cin >> n >> m;
	forn(i, n)
		cin >> a[i];
	ans = a[0];
	
	for (int l = 0; l < n; l++)
		for (int r = l; r < n; r++) {
			
			cur = 0;
			minIn.clear();
			maxOut.clear();
			for (int i = l; i <= r; i++) {
				cur += a[i];
				b[i - l] = a[i];	
			}
			
			sort(b, b + r - l + 1);
			forn(i, min(m, r - l + 1))
				minIn.pb(b[i]);
			
			sz = 0;
			for (int i = 0; i < l; i++)
				b[sz++] = a[i];
			for (int i = r + 1; i < n; i++)
				b[sz++] = a[i];
			sort(b, b + sz);
			reverse(b, b + sz);
			forn(i, min(m, sz))
				maxOut.pb(b[i]);
				
			ans = max(ans, cur);
			forn(i, min(minIn.size(), maxOut.size())) {
				cur += -minIn[i] + maxOut[i];
				ans = max(ans, cur);
			}
		}

	cout << ans;
	                       		
	return 0;
}