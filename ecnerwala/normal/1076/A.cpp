#include<bits/stdc++.h>
using namespace std;

int N;
char S[int(3e5)];
int main() {
	cin >> N >> S;
	for (int i = 0; i+1 < N; i++) {
		if (S[i+1] < S[i]) {
			S[i] = '\0';
			cout << S << (S+i+1) << '\n';
			return 0;
		}
	}
	S[N-1] = '\0';
	cout << S << '\n';

	return 0;
}