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

ll n, m, k, ans;
ll a, b, h, w;

int main() {

	cin >> n >> m >> k;
	if ((n - 1) + (m - 1) < k) {
		cout << -1;
		return 0;
	}
	
	ans = 0;
	a = max(0ll, k - m + 1);
	
	forn(i, 1111) {
		b = k - a;
		if (a < 0 || a >= n || b < 0 || b >= m)
			continue;
			
		h = n / (a + 1);
		w = m / (b + 1);
		ans = max(ans, h * w);
		a++;
	}
	
	b = max(0ll, k - n + 1);
	forn(i, 1111) {
		a = k - b;
		if (a < 0 || a >= n || b < 0 || b >= m)
			continue;
			
		h = n / (a + 1);
		w = m / (b + 1);
		ans = max(ans, h * w);
		b++;
	}

	cout << ans;
	
	return 0;
}