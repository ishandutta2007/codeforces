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
int a[100007];
int cnt[100007];

ll calc_func(ll a, ll k) {
	if (a < k) return 0;
	ll main = a / k;
	ll ost = a % k;
	ll ans = (k - ost) * main * main;
	ans += ost * (main + 1) * (main + 1);
	return ans;
}

ll inc(int v) {
	return calc_func(a[v], cnt[v]) - calc_func(a[v], cnt[v] + 1);
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> a[i];

	set<pair<ll, int> > se;

	for (int i = 0; i < n; ++i) {
		cnt[i] = 1;
		if (a[i] > 1) {
			se.insert({-inc(i), i});
		}
	}

	for (int it = 0; it < k - n; ++it) {
		auto [_, v] = *se.begin();
		se.erase(se.begin());
		//cout << v << endl;
		++cnt[v];
		if (cnt[v] < a[v]) se.insert({-inc(v), v});
	}

	ll ans = 0;
	for (int v = 0; v < n; ++v) ans += calc_func(a[v], cnt[v]);
	cout << ans;
}