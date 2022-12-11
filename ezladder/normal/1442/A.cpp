#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n;
int a[300007];

int solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
		int last = a[0];
	a[0] = 0;
	for (int i = 1; i < n; ++i) {
		last = min(last, a[i]);
		int prev = a[i - 1];
		last = min(last, a[i] - prev);
	//	cout << i << ' ' << last << endl;
		if (last < 0) break;
		a[i] -= last;
	}

	reverse(a, a + n);

	for (int i = 1; i < n; ++i) {
		if (a[i] > a[i - 1]) return 0;
	}
	return 1;
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		if (
		solve() ) cout << "YES\n"; else cout << "NO\n";
	}

}