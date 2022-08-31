#include<bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	for(int i = 4; i <= 8; i+= 2) {
		if((N - i) % 3 == 0) {
			cout << i << ' ' << N - i << '\n';
			return 0;
		}
	}
	assert(false);
	return 0;
}