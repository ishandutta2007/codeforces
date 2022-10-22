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
	pi mx = {-1, 0};
	for(int x, i = 1; i <= n; ++i) {
		cin >> x;
		if(x > mx.ST) {
			mx = {x, i};
		}
	}
	cout << mx.ND << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		solve();
	}
}