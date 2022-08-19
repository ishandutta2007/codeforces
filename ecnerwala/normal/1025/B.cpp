#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;

const int MAXN = 2e5;
int N;
ll A[MAXN][2];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i][0] >> A[i][1];
	}
	assert(N);
	ll g = 0;
	for (int i = 0; i < N; i++) {
		g = __gcd(g, A[i][0] * A[i][1]);
	}
	for (int i = 0; i < N; i++) {
		g = max(__gcd(g, A[i][0]), __gcd(g, A[i][1]));
	}
	if (g == 1) g = -1;
	cout << g << '\n';
	return 0;
}