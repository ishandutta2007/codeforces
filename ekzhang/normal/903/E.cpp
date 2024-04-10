#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 5013
int N, K;
string S[MAXN];
string P;
vector<int> diffs[MAXN];
bool hasDouble = false;

bool chk(int a, int b) {
	bool ok = true;
	swap(P[a], P[b]);
	for (int i = 0; i < K; i++) {
		vector<int> diff(diffs[i]);
		auto it = find(diff.begin(), diff.end(), a);
		if (it != diff.end()) diff.erase(it);
		if (P[a] != S[i][a])
			diff.push_back(a);

		it = find(diff.begin(), diff.end(), b);
		if (it != diff.end()) diff.erase(it);
		if (P[b] != S[i][b])
			diff.push_back(b);

		if (diff.size() == 2) {
			int x = diff[0];
			int y = diff[1];
			if (P[x] != S[i][y] || P[y] != S[i][x]) {
				ok = false;
			}
		}
		else if (diff.size() == 0) {
			if (!hasDouble) ok = false;
		}
		else {
			ok = false;
		}
		if (!ok) break;
	}
	swap(P[a], P[b]);
	return ok;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> S[i];
		for (int j = 0; j < N; j++) {
			if (S[i][j] != S[0][j])
				diffs[i].push_back(j);
		}
		if (diffs[i].size() > 4) {
			cout << -1 << endl;
			return 0;
		}
	}

	P = string(S[0]);

	for (int a = 0; a < N; a++) {
		for (int b = a + 1; b < N; b++) {
			if (P[a] == P[b]) hasDouble = true;
		}
	}

	if (N <= K) {
		for (int a = 0; a < N; a++) {
			for (int b = a + 1; b < N; b++) {
				if (chk(a, b)) {
					swap(P[a], P[b]);
					cout << P << endl;
					return 0;
				}
			}
		}
		cout << -1 << endl;
		return 0;
	}

	int firstdiff = 0;
	while (firstdiff < K) {
		if (S[0] == S[firstdiff])
			firstdiff++;
		else break;
	}
	if (firstdiff == K) {
		swap(P[0], P[1]);
		cout << P << endl;
		return 0;
	}

	for (int i = 0; i < K; i++) {
		P = S[i];
		for (int j = i + 1; j < K; j++) {
			// compare S[i] and S[j]
			vector<int> v;
			for (int k = 0; k < N; k++) {
				if (S[i][k] != S[j][k]) {
					v.push_back(k);
				}
			}
			for (int a = 0; a < v.size(); a++) {
				for (int b = a + 1; b < v.size(); b++) {
					if (chk(v[a], v[b])) {
						swap(P[v[a]], P[v[b]]);
						cout << P << endl;
						return 0;
					}
				}
			}
		}
	}

	cout << -1 << endl;
	return 0;
}