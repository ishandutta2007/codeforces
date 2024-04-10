#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e5+1;

vector<pii> clouds;
vector<int> match;
int L, wmax;

int intersect(int xl, int xr) {
	ld w = 0;
	if (xl >= 0) {
		w = (ld)2*abs(xr+L)/(abs(xr+L)-abs(xl)) - 1;
	}
	else if (xr+L <= 0) {
		w = (ld)2*abs(xl)/(abs(xl)-abs(xr+L)) - 1;
	}
	//cerr << "intersect " << xl << " " << xr << " -> " << w << nl;
	return w+EPS > wmax ? -1 : 0;
}

int solve(int start) {
	int ileft = upper_bound(match.begin(), match.end(), start) - match.begin();
	int iright = match.size()-1;
	if (ileft > iright) return 0;

	int left, first, second, right;
	first = 0;
	second = -1;

	//cerr << "solving for cloud @ " << start << nl;
	//cerr << "  first: " << match[ileft] << "  last: " << match[iright] << nl;

	// left
	left = ileft;
	right = iright;
	while (left <= right) {
		first = (left+right)/2;
		if (intersect(start, match[first]) == -1) {
			left = first+1;
		} else {
			right = first-1;
		}
	}
	if (intersect(start, match[first]) == -1) first++;

	// right
	left = ileft;
	right = iright;
	while (left <= right) {
		second = (left+right)/2;
		if (intersect(start, match[second]) == 1) {
			right = second-1;
		} else {
			left = second+1;
		}
	}
	if (intersect(start, match[second]) == 1) second--;

	//cerr << "result: " << '[' << first << ',' << second << ']' << nl;
	assert(second-first+1 >= 0);
	return second-first+1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n >> L >> wmax;

	int x, v;
	for (int i=0; i<n; i++) {
		cin >> x >> v;
		clouds.push_back(pii(x,v));
	}
	sort(clouds.begin(), clouds.end());

	for (const pii& it : clouds) {
		if (it.second == -1) match.push_back(it.first);
	}

	ll ans = 0;
	for (const pii& it : clouds) {
		if (it.second == 1) ans += solve(it.first);
	}
	cout << ans << nl;

	return 0;
}