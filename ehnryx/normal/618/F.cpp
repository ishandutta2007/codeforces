#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

void output(pii a[], int i) {
	cout << i << nl;
	for (int ii=0; ii<i; ii++) {
		cout << a[ii].second << " ";
	}
	cout << nl;
}

bool solve(pii a[], pii b[], int n) {
	ll sa = a[0].first;
	ll sb = b[0].first;
	int i = 1;
	int j = 1;
	while (sa != sb) {
		if (sa < sb) {
			if (i == n) return false;
			sa += a[i++].first;
		} else {
			if (j == n) return false;
			sb += b[j++].first;
		}
	}
	output(a, i);
	output(b, j);
	return true;
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

	int n;
	cin >> n;

	pii a[n], b[n];
	For(i,n) {
		cin >> a[i].first;
		a[i].second = i+1;
	}
	For(i,n) {
		cin >> b[i].first;
		b[i].second = i+1;
	}

	sort(a,a+n);
	sort(b,b+n);
	if (solve(a,b,n)) {
		return 0;
	}

	reverse(a,a+n);
	reverse(b,b+n);
	if (solve(a,b,n)) {
		return 0;
	}

	cout << -1 << nl;

	return 0;
}