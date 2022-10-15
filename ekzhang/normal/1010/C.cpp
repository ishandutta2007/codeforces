#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
int N, K;
int A[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K;
	int g = K;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		g = __gcd(g, A[i]);
	}

	cout << K / g << '\n';
	for (int i = 0; i < K; i += g) {
		cout << i << ' ';
	}

	cout << endl;
	return 0;
}