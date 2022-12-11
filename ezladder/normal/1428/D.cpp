#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int a[200007];

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> a[i];

	vector<pair<int, int> > ans;

	vector<pair<int, int> > free1;
	vector<int> freeo;

	int y = n - 1;
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] == 0) {

		} else if (a[i] == 1) {
			ans.pb({y, i});
			free1.pb({y, i});
		} else if (a[i] == 2) {
			if (free1.size() == 0) cout << -1, exit(0);
			auto v = free1.back().x; free1.pop_back();
			ans.pb({v, i});
			freeo.pb(i);
		} else {
			if (freeo.size() == 0 && free1.size() == 0) cout << -1, exit(0);
			int v;
			if (freeo.size() == 0) {
				v = free1.back().y; free1.pop_back();
			} else {
				v = freeo.back(); freeo.pop_back();
			}
			ans.pb({y, i});
			ans.pb({y, v});
			freeo.pb(i);
		}
		--y;
	}


	cout << ans.size() << endl;
	for (auto [w1, w2] : ans) cout << w1 + 1 << ' ' << w2 + 1 << "\n";
}