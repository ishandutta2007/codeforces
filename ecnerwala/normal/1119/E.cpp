#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 3.1e5;
int N;
ll A[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];

	ll tot = 0;
	ll carry = 0; // <= 3
	for (int i = 0; i < N; i++) {
		ll v = min(A[i] / 2, carry);
		tot += v;
		carry -= v;
		A[i] -= 2 * v;

		assert(A[i] <= 1 || carry == 0);

		tot += A[i] / 3;
		A[i] %= 3;

		carry += A[i];
	}
	cout << tot << '\n';

	return 0;
}