#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	long long sum = 0, maxi = 0;
	for(int i = 0; i < n; i++){
		long long x;
		cin >> x;
		sum += x;
		maxi = max(maxi, x);
	}
	cout << max(maxi, (sum + n - 2)/(n - 1)) << '\n';

	return 0;
}