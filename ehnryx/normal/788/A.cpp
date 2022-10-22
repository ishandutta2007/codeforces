#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> diff;
	int a, t;
	cin >> t;
	for (int i = 1; i < n; i++) {
		cin >> a;
		diff.push_back(abs(a-t));
		t = a;
	}
	//
	
	ll ans1, ans2, sum1, sum2;
	ans1 = ans2 = 0;
	sum1 = sum2 = 0;
	for (int i = 0; i < n-1; i++) {
		if (i % 2 == 0) {
			sum1 += diff[i];
			sum2 -= diff[i];
		}
		else {
			sum1 -= diff[i];
			sum2 += diff[i];
		}
		if (sum1 < 0)
			sum1 = 0;
		if (sum2 < 0)
			sum2 = 0;
		if (sum1 > ans1)
			ans1 = sum1;
		if (sum2 > ans2)
			ans2 = sum2;
	}
	cout << max(ans1,ans2) << endl;
	
	return 0;
}