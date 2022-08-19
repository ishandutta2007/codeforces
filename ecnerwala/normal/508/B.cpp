#include<bits/stdc++.h>
using namespace std;

int main() {
	string S;
	cin >> S;
	int N = S.size();
	assert((S[N - 1] - '0') % 2 == 1);

	int res = -1;
	for(int i = 0; i < N; i++) {
		if((S[i] - '0') % 2 == 0) {
			res = i;
			if(S[i] < S[N - 1]) {
				break;
			}
		}
	}

	if(res == -1) {
		cout << -1 << '\n';
	} else {
		swap(S[res], S[N - 1]);
		cout << S << '\n';
	}

	return 0;
}