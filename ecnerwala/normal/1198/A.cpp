#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 1.1e6;
ll A[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll N, I; cin >> N >> I;
	for (int i = 0; i < N; i++) cin >> A[i];


	I *= 8;
	I = I / N;
	I = min(I, 30ll);
	ll L = (1ll << I);
	map<ll, int> mp;
	for (int i = 0; i < N; i++) mp[A[i]]++;
	vector<int> pref({0});
	for (auto it : mp) {
		pref.push_back(pref.back() + it.second);
	}

	ll ans = N;
	L = min(L, ll(pref.size()) - 1);
	for (int i = 0; i + L < int(pref.size()); i++) {
		ans = min(ans, N - (pref[i+L] - pref[i]));
	}
	cout << ans << '\n';

	return 0;
}