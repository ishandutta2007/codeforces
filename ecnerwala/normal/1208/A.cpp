#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int a, b, n; cin >> a >> b >> n;
		cout << vector<int>({a,b,a^b})[n%3] << '\n';
	}

	return 0;
}