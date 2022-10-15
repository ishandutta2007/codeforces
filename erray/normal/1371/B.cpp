#include<bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		long long n, r;
		cin >> n >> r;
		long long mn = min(n - 1, r);
		cout << mn * (mn + 1) / 2 + (r >= n) << '\n'; 
	}
}