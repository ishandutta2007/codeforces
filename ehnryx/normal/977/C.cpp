#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, k;
	cin >> n >> k;

	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int left, right, mid;
	left = 1;
	right = 1e9;
	while (left <= right) {
		mid = (left+right)/2;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += (a[i] <= mid);
		}
		if (cnt < k) left = mid+1;
		else if (cnt > k) right = mid-1;
		else {
			cout << mid << nl;
			return 0;
		}
	}

	cout << -1 << nl;

	return 0;
}