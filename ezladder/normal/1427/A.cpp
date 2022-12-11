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
int a[55];

void solve() {
	cin >> n;
	int s = 0;
	for (int i = 0; i < n; ++i) cin >> a[i], s += a[i];

	if (s == 0) {
		cout << "NO\n";
		return;
	} else {
		cout << "YES\n";
	}

	sort(a, a + n);

	if (s > 0) {
		reverse(a, a + n);
	} else {

	}

	for (int i = 0; i < n; ++i) cout << a[i] << ' ';
	cout << "\n";

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
		solve();
	}
}