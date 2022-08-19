#include<bits/stdc++.h>

using namespace std;

int main() {
	long double N, M;
	cin >> N >> M;
	long double res;
	if(N == 1 && M == 1) {
		res = 1;
	} else {
		res = 1 / N + (N - 1) / N * (M - 1) / (M * N - 1);
	}
	cout << fixed << setprecision(20) << res << '\n';
	return 0;
}