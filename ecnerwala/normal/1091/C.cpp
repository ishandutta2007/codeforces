#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll N; cin >> N;
	vector<ll> f;
	for (ll i = 1; i * i <= N; i++) {
		if (N % i) continue;

		f.push_back(i * (N + 2 - N / i) / 2);

		f.push_back((N / i) * (N + 2 - i) / 2);
	}

	sort(f.begin(), f.end());
	f.resize(size_t(unique(f.begin(), f.end()) - f.begin()));
	for (int i = 0; i < int(f.size()); i++) {
		if (i) cout << ' ';
		cout << f[i];
	}
	cout << '\n';

	return 0;
}