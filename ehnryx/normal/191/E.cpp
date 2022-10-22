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
int a[N];
unordered_map<int,vector<ll>> lv[N], rv[N];

ll dc(ll v, int l, int r) {
	if (l==r) { return a[l] >= v; }
	int m = (l+r)/2;

	if (!lv[l].count(r)) {
		ll cur = 0;
		vector<ll>& ref = lv[l][r];
		for (int i=m; i>=l; i--) {
			cur += a[i];
			ref.push_back(cur);
		}
		sort(ref.begin(), ref.end());
	}
	if (!rv[l].count(r)) {
		ll cur = 0;
		vector<ll>& ref = rv[l][r];
		for (int i=m+1; i<=r; i++) {
			cur += a[i];
			ref.push_back(cur);
		}
		sort(ref.begin(), ref.end());
	}

	const vector<ll>& left = lv[l][r];
	const vector<ll>& right = rv[l][r];

	ll res = 0;
	int j = right.size();
	for (int i=0; i<left.size(); i++) {
		while (j>0 && left[i]+right[j-1] >= v) j--;
		res += right.size()-j;
	}
	return res + dc(v, l, m) + dc(v, m+1, r);
}

ll solve(int n, ll v) {
	return dc(v, 1, n);
}

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n; ll k;
	cin >> n >> k;

	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	const ll maxv = 1e9; // fix
	ll left, right, mid;
	left = -n*maxv;
	right = n*maxv;
	while (left <= right) {
		mid = (left+right)/2;
		if (solve(n, mid) >= k) {
			left = mid+1;
		} else {
			right = mid-1;
		}
	}

	if (solve(n, mid) < k) {
		mid--;
	}
	cout << mid << nl;

	return 0;
}