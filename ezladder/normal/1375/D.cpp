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
int a[1111];
int b[1111];

int get_mex() {
	std::copy(a, a + n, b);
	sort(b, b + n);
	int dd = 0;
	for (int i = 0; i < n; ++i) {
		if (b[i] == dd) ++dd;
	}
	return dd;
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		vector<int> ans;


		while (true) {
			bool ok = 1;
			for (int j = 1; j < n; ++j) if (a[j - 1] > a[j]) {
				ok = 0;
			}
			if (ok) break;

			int me = get_mex();
		
			if (me == n) {
				for (int j = 0; j < n; ++j) if (a[j] != j) {
					a[j] = n; 
					ans.pb(j);
					break;
				}
			} else {
				ans.pb(me);
				a[me] = me;
			}

		//	cout << me << endl;
		//	for (int j = 0; j < n; ++j) cout << a[j] << ' ';
		//	cout << endl;
		}


		cout << ans.size() << "\n";
		for (int x : ans) cout << x + 1 << ' ';
		cout << "\n";
	}
}