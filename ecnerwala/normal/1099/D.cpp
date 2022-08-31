#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1.1e5;
int N;
int P[MAXN];
ll S[MAXN];
vector<int> ch[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 2; i <= N; i++) cin >> P[i];
	for (int i = 1; i <= N; i++) cin >> S[i];

	S[0] = -1;
	for (int i = 1; i <= N; i++) {
		if ((S[i] == -1) == (S[P[i]] == -1)) {
			cout << -1 << '\n';
			return 0;
		}
	}
	long long res = 0;
	S[0] = 0;

	for (int i = 1; i <= N; i++) {
		ch[P[i]].push_back(i);
	}

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
		if (S[i] < S[P[i]]) {
			cout << -1 << '\n';
			return 0;
		}
		res += S[i] - S[P[i]];
	}
	cout << res << '\n';
	return 0;
}