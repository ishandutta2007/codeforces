#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 6e5;
int N;
ll X, Y;

char S[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> X >> Y;
	cin >> S;

	S[N] = '1';
	ll nf = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == '0' && S[i+1] == '1') {
			nf ++;
		}
	}

	if (nf == 0) {
		cout << nf << '\n';
	} else {
		cout << Y + min(X, Y) * (nf - 1) << '\n';
	}

	return 0;
}