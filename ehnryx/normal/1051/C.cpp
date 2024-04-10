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

	int a[n];
	vector<int> cnt(101,0);
	for (int i=0; i<n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}

	char ans[n];
	int val = 0;
	int split = -1;
	for (int i=0; i<n; i++) {
		if (cnt[a[i]] == 1) {
			ans[i] = 'A'+val;
			val ^= 1;
		} else {
			ans[i] = 'A';
		}
		if (cnt[a[i]] > 2) {
			split = i;
		}
	}

	if (val && split == -1) {
		cout << "NO" << nl;
	} else{
		if (val) {
			ans[split] = 'B';
		}
		cout << "YES" << nl;
		for (char c : ans) {
			cout << c;
		}
		cout << nl;
	}

	return 0;
}