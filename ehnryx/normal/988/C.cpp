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



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int k;
	cin >> k;

	map<int,pii> sums;
	for (int i=1; i<=k; i++) {
		int n;
		cin >> n;

		vector<int> arr;
		int sum = 0;
		for (int j=1; j<=n; j++) {
			int a;
			cin >> a;
			arr.push_back(a);
			sum += a;
		}

		for (int j=1; j<=n; j++) {
			int it = arr[j-1];
			if (sums.count(sum-it) && sums[sum-it].first != i) {
				cout << "YES" << nl;
				cout << sums[sum-it].first << " " << sums[sum-it].second << nl;
				cout << i << " " << j << nl;
				return 0;
			} else {
				sums[sum-it] = pii(i,j);
			}
		}
	}

	cout << "NO" << nl;

	return 0;
}