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
	vector<vector<int> > t;
	vector<int> now;
	now.pb(a[0]);
	for (int i = 1; i < n; ++i) {
		if (a[i - 1] < a[i]) {
			now.pb(a[i]);
		} else {
			t.pb(now);
			now.clear();
			now.pb(a[i]);
		}
	}
	t.pb(now);
	int last = -1;

	for (int i = 0; i < t.size(); ++i) {
		int f = 0;
		for (int x : t[i]) {
			if (x > last) {
				last = x;
				f = 1;
				break;
			}
		}
		if (f == 0) return 0;
	}

	return 1;
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		if (a[0] < a[n - 1]) cout << "YES\n"; else cout << "NO\n";
	}

}