#include<bits/stdc++.h>

using namespace std;

typedef long double ld;

ld intpow(ld v, int a) {
	ld r = 1;
	while(a) {
		if(a % 2) r *= v;
		a /= 2;
		v *= v;
	}
	return r;
}

int main() {
	int M, N;
	cin >> M >> N;
	ld res = M;
	for(int i = 1; i < M; i++) {
		res -= intpow(ld(i) / M, N);
	}
	cout << fixed << setprecision(12) << res << '\n';
	return 0;
}