#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    vector <int> t(n), b(n);
    for (int i = 0; i < n; ++i) cin >> t[i] >> b[i];
    vector <int> id(n);
	iota(id.begin(), id.end(), 0);
	sort(id.begin(), id.end(), [&] (int i, int j) {
		return b[i] > b[j];
	});
	ll ans = 0;
	multiset <int> mx;
	ll sum = 0;
	for (int i : id) {
		mx.insert(t[i]);
		sum += t[i];
		if (mx.size() > k) {
			sum -= *mx.begin();
			mx.erase(mx.begin());
		}
		ans = max(ans, sum * b[i]);
	}
	cout << ans << '\n';
}