#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ms = 1e5+5;

int a[ms];
vector<int> ans;

int main() {
	int n, k;
	cin >> n >> k;
	int total = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		total += a[i];
	}
	if(total % k) {
		cout << "No\n";
		return 0;
	}
	int sz = total / k;
	int lo = 0, hi = 0;
	int cur = 0;
	while(hi < n) {
		//cout << lo << ' ' << hi << ' ' << cur << endl;
		if(cur > sz) {
			cout << "No\n";
			return 0;
		} else if(cur == sz) {
			ans.push_back(hi - lo);
			cur = 0;
			lo = hi;
		} else {
			cur += a[hi++];
		}
	}
	if(cur == sz) {
		ans.push_back(hi - lo);
		cout << "Yes\n";
		for(int x : ans) {
			cout << x << ' ';
		}
		cout << '\n';
	} else {
		cout << "No\n";
	}
}