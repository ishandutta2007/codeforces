#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;
ll A, B, C, D;

int main() {
	cin >> N >> A >> B >> C >> D;
	// the range is 1 <= sum - A - B <= N
	ll mi = 1 + max(A, D) + max(B, C);
	ll ma = N + min(A, D) + min(B, C);
	cout << N * max(ma - mi + 1, 0ll) << '\n';
	return 0;
}