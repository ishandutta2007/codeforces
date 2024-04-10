#include<bits/stdc++.h>
using namespace std;

int N;
int main() {
	cin >> N;
	int g = 1;
	while (N > 1) {
		int d = N / (N / 2);
		for (int i = 0; i < N - N/2; i++) {
			cout << g << ' ';
		}
		N /= 2;
		g *= d;
	}
	cout << g << '\n';
	cout << '\n';
	return 0;
}