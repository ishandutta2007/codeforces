#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int n2 = n;
	long long ans = 0;
	vector<int> ct(25);
	while (n2--) {
		int x;
		cin >> x;
		for (int i = 0; i < 25; ++i) ct[i] += ((x & (1<<i)) > 0);
	}
	for (int i = 0; i < n; ++i) {
		long long sum = 0;
		for (int j = 0; j < 25; ++j) {
			if (i <= ct[j] - 1) sum += (1 << j);
		}
		ans += sum * sum;
	}
	cout << ans;
}