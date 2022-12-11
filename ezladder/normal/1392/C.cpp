#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;


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
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		ll ans = 0;

		for (int i = 0; i + 1 < n; ++i) {
			if (a[i] > a[i + 1]) {
				ans += a[i] - a[i + 1];
			}
		}

		cout << ans << "\n";

	}

}