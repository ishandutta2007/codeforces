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

int t, n, m;

void solve() {
	cin >> n >> m;
	if(m < n) {
		cout << "NO\n";
		return;
	}
	if(n % 2 == 1) {
		cout << "YES\n";
		for(int i = 1; i < n; ++i) {
			cout << "1 ";
		}
		cout << m - (n - 1) << "\n";
		return;
	}
	if(m % 2 != 0) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for(int i = 1; i <= n - 2; ++i) {
		cout << "1 ";
	}
	cout << (m - (n - 2)) / 2 << " " << (m - (n - 2)) / 2 << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		solve();
	}
}