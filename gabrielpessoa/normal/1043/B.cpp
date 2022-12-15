#include <bits/stdc++.h>
using namespace std;

const int ms = 1e5+5;

int a[ms];
vector<int> ans;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i+1];
	}
	for(int k = 1; k <= n; k++) {
		bool valid = true;
		for(int i = 0; i < n; i++) {
			if(a[i+1] - a[i] != a[i%k + 1] - a[i%k]) {
				valid = false;
			}
		}
		if(valid) ans.push_back(k);
	}
	cout << ans.size() << '\n';
	for(int x : ans) cout << x << ' ';
}