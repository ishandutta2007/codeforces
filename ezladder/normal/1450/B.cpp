#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n, k;
int x[111];
int y[111];

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

		int can = 0;

		for (int i = 0; i < n; ++i) {
			int ok = 1;
			for (int j = 0; j < n; ++j) {
				if (abs(x[i] - x[j]) + abs(y[i] - y[j]) > k) {
					ok = 0;
					break;
				}
			}
			if (ok) {
				can = 1;
				break;
			}
		}


		if (can) cout << "1\n"; else cout << "-1\n";
	}

}