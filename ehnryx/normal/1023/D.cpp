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

const int N = 2e5+1;
int freq[N];
void insert(int x) {
	for ( ; x < N; x += x&-x)
		freq[x]++;
}
int query(int x) {
	int res = 0;
	for ( ; x > 0; x -= x&-x)
		res += freq[x];
	return res;
}
int query(int xl, int xr) {
	return query(xr) - query(xl-1);
}

int a[N];
int maxv[N], minv[N];
vector<int> id[N];

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n, q;
	cin >> n >> q;

	set<int> zero;
	fill(maxv, maxv+q+1, -INF);
	fill(minv, minv+q+1, INF);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxv[a[i]] = max(maxv[a[i]], i);
		minv[a[i]] = min(minv[a[i]], i);
		id[a[i]].push_back(i);
		if (a[i] == 0) zero.insert(i);
	}

	if (minv[q] == INF) {
		if (zero.empty()) {
			cout << "NO" << nl;
			return 0;
		}
		minv[q] = maxv[q] = *zero.begin();
	}

	for (int i = q; i >= 1; i--) {
		if (minv[i] != INF) {
			for (int it : id[i]) {
				insert(it);
			}
			set<int>::iterator it = zero.lower_bound(minv[i]);
			while (it != zero.end() && *it <= maxv[i]) {
				insert(*it);
				a[*it] = i;
				it = zero.erase(it);
			}
			if (query(minv[i], maxv[i]) != maxv[i] - minv[i] + 1) {
				cout << "NO" << nl;
				return 0;
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		if (a[i] == 0) a[i] = a[i-1];
	}
	for (int i = n-1; i > 0; i--) {
		if (a[i] == 0) a[i] = a[i+1];
	}

	cout << "YES" << nl;
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	cout << nl;

	return 0;
}