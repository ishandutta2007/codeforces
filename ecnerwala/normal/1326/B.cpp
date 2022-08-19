#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	ll X = 0;
	for (int i = 0; i < N; i++) {
		ll b; cin >> b;
		ll a = b + X;
		X = max(X, a);
		cout << a << " ";
	}
	cout << '\n';

	return 0;
}