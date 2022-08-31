#include<iostream>

using namespace std;

int N, M, K;

int main() {
	cin >> N >> M >> K;
	cout << (M * (M - 1) / 2) << '\n';
	for(int i = 0; i < M; i++) {
		for(int j = 1; j <= M - 1 - i; j++) {
			if(K) cout << j + 1 << ' ' << j << '\n';
			else  cout << j << ' ' << j + 1 << '\n';
		}
	}

	return 0;
}