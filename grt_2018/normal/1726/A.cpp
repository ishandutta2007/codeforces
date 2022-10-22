//GRT_2018
#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 2000 + 10, INF = 1e9;
int t, n;
int a[nax];

void solve() {
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	if(n == 1) {
		cout << "0\n";
		return;
	}
	int ans = a[n] - a[1];
	for(int i = 1; i < n; ++i) {
		ans = max(ans, a[n] - a[i]);
	}
	for(int i = 2; i <= n; ++i) {
		ans = max(ans, a[i] - a[1]);
	}
	for(int i = 1; i < n; ++i) {
		ans = max(ans, a[i] - a[i + 1]);
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		solve();
	}
}