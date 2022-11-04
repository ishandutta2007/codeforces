#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	const ll INF = 1000000000000000;
	ll n;
	cin >> n;
	vector<vector<ll>> arr(n, vector<ll>(n, INF));
	vector<bool> used(n, false);
	vector<ll> ar(n, 0);
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			ll m;
			cin >> m;
			arr[i][j] = m;
		}
	}
	for (ll i = 0; i < n; i++) {
		cin >> ar[i];
		ar[i]--;
	}
	reverse(ar.begin(), ar.end());
	vector<ll> ans;
	for (ll i = 0; i < n; i++) {
		used[ar[i]] = true;
		ll sum = 0;
		for (ll a = 0; a < n; a++) {
			for (ll b = 0; b < n; b++) {
				arr[a][b] = min(arr[a][b], arr[a][ar[i]]+arr[ar[i]][b]);
				if (used[a] && used[b]) {
					sum += arr[a][b];
				}
			}
		}
		ans.push_back(sum);
	}
	reverse(ans.begin(), ans.end());
	for (auto i : ans) {
		cout << i << ' ';
	}
}