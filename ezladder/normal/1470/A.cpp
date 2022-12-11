#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int k[300007];
ll c[300007];
ll pref[300007];
ll pref2[300007];

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
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; ++i) cin >> k[i], k[i]--;
		for (int i = 0; i < m; ++i) cin >> c[i];

		sort(k, k + n);


		pref[0] = 0;
		pref2[0] = 0;
		for (int i = 1; i <= n; ++i) {
			pref[i] = pref[i - 1] + c[k[i - 1]];
		}

		for (int i = 1; i <= m; ++i) {
			pref2[i] = pref2[i - 1] + c[i - 1];
		}

		ll res = 1e18;
		for (int i = 0; i <= n; ++i) {
			if (n - i <= m)
			res = min(res, pref[i] + pref2[n - i]);
		}


		/*vector<int> t;
		for (int i = 0; i < n; ++i) t.pb(i);
		sort(all(t), [](int w1, int w2) {
			return k[w1] < k[w2];
		});	
		int last = 0;
		ll res = 0;
		for (int v : t) {
			if (k[v] >= last) {
				last++;
			}
		}

		for (int i = 0; i <= last; ++i) {

		}

		for (int i = 0; i < n - last + 1; ++i) res += c[k[t[i]]]; */

		cout << res << "\n";
	}

}