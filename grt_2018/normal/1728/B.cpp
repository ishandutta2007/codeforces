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

void solve() {
	int n;
	cin >> n;
	if(n % 2 == 0) {
		for(int i = n - 2; i >= 1; --i) {
			cout << i << " ";
		}
		cout << n-1 << " " << n << "\n";
	} else {
		cout << n-1 << " ";
		for(int i = n - 3; i >= 2; --i) {
			cout << i << " ";
		}
		cout << 1 << " " << n-2 << " " << n << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		solve();
	}
}