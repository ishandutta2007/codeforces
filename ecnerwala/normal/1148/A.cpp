#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll A, B, C; cin >> A >> B >> C;
	cout << min(min(A, B) * 2 + 1, A+B) + C * 2 << '\n';

	return 0;
}