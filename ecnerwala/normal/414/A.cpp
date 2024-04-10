#include<iostream>

using namespace std;

int main() {
	int N, K; cin >> N >> K;
	if(N/2 > K) {
		cout << -1 << '\n'; 
	} else if (N == 1) {
		if(K == 0) cout << 1 << '\n';
		else cout << -1 << '\n';
	} else { 
		int v = K - N / 2 + 1;
		cout << v << ' ' << 2 * v << '\n';
		K -= v;
		N -= 2;
		v *= 2;
		while(N >= 2) {
			v += 2;
			cout << v << ' ' << v + 1 << '\n';
			N -= 2;
		}
		if(N) cout << v + 2 << '\n';
	}
	return 0;
}