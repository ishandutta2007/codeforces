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

int t;
map<int, int>cnt;

int f(int x) {
	return (int)to_string(x).size();
}

void solve() {
	int n;
	cin >> n;
	cnt.clear();
	for(int x, i = 1; i <= n; ++i) {
		cin >> x;
		cnt[x]++;
	}
	for(int x, i = 1; i <= n; ++i) {
		cin >> x;
		cnt[x]--;
	}
	int ans = 0;
	for(auto [a,b] : cnt) {
		if(a > 9) {
			ans += abs(b);
			cnt[f(a)] += b;
		}
	}
	for(auto [a, b] : cnt) {
		if(a <= 9 && a > 1) {
			ans += abs(b);
		}
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