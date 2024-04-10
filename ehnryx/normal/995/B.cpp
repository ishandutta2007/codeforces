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

	int n;
	cin >> n;

	int a[2*n];
	for (int i=0; i<2*n; i++) {
		cin >> a[i];
	}

	int ans = 0;
	for (int i=0; i<2*n; i+=2) {
		if (a[i] != a[i+1]) {
			int j = i+1;
			while (j < 2*n && a[i] != a[j]) { j++; }
			for (int k = j; k > i+1; k--) {
				swap(a[k], a[k-1]);
				ans++;
			}
		}
	}
	cout << ans << nl;

	//cerr << "final: "; for (int i = 0; i < 2*n; i++)
		//cerr << a[i] << " ";
	//cerr << nl;

	return 0;
}