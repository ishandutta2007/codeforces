#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1.1e5;
int N;
int P[MAXN];
ll S[MAXN];
ll A[MAXN];

vector<int> ch[MAXN];

void FAIL() {
	cout << -1 << '\n';
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 2; i <= N; i++) cin >> P[i];
	P[1] = 0;
	S[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> S[i];
	}

	if (S[1] == -1) {
		FAIL();
	}

	for (int i = 2; i <= N; i++) {
		if ((S[i] == -1) == (S[P[i]] == -1)) {
			FAIL();
		}
	}

	for (int i = 2; i <= N; i++) {
		ch[P[i]].push_back(i);
	}

	ll totA = 0;
	for (int i = 1; i <= N; i++) {
		if (S[i] == -1) {
			if (ch[i].empty()) {
				S[i] = S[P[i]];
			} else {
				S[i] = S[ch[i][0]];
				for (int c : ch[i]) {
					S[i] = min(S[i], S[c]);
				}
			}
		}

		assert(S[i] != -1);
		if (S[i] - S[P[i]] < 0) {
			FAIL();
		}

		totA += (S[i] - S[P[i]]);
	}

	cout << totA << '\n';
	return 0;
}