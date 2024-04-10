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

const int N = 2e5+1;
int a[N];

int valid(int n, int k, int v, bool out=false) {
	int j = 0;
	For(i,n) {
		while (a[i]-a[j] > 2*v) {
			j++;
		}
		if (i-j >= k) {
			if (out) return (a[i]+a[j])/2;
			else return true;
		}
	}
	return false;
}

void solve() {
	int n, k;
	cin >> n >> k;
	For(i,n) {
		cin >> a[i];
	}

	int left = 0;
	int right = 1e9;
	while (left < right) {
		int mid = (left+right)/2;
		if (valid(n, k, mid)) {
			right = mid;
		} else {
			left = mid+1;
		}
	}
	cout << valid(n, k, left, true) << nl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}