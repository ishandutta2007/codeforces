#include<bits/stdc++.h>
using namespace std;

const int MAXN = 4000;
const int MAXL = 4000;
int N;
int L[MAXN];
char W[MAXN][2][MAXL+1];
int diff[MAXN];

const pair<char, char> BAD(-1, -1);

string S, T;

bool testOffset(int l) {
	bool found = false;
	char curS = 0;
	char curT = 0;
	for (int i = 0; i < N; i++) {
		if (diff[i] == -1) continue;
		int ind = diff[i] + l;
		if (!(0 <= ind && ind < L[i])) {
			return false;
		}
		if (!found) {
			curS = W[i][0][ind];
			curT = W[i][1][ind];
			found = true;
		}
		if (curS != W[i][0][ind]) {
			return false;
		}
		if (curT != W[i][1][ind]) {
			return false;
		}
	}
	assert(found);
	S += curS;
	T += curT;
	return true;
}

int z[MAXL][26];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) { cin >> W[i][0]; }
	for (int i = 0; i < N; i++) { cin >> W[i][1]; }
	for (int i = 0; i < N; i++) {
		L[i] = int(strlen(W[i][0]));
		assert(L[i] = int(strlen(W[i][1])));
	}
	for (int i = 0; i < N; i++) {
		diff[i] = -1;
		for (int j = 0; j < L[i]; j++) {
			if (W[i][0][j] != W[i][1][j]) {
				diff[i] = j;
				break;
			}
		}
	}
	for (int l = 0; true; l++) {
		if (!testOffset(-l)) {
			break;
		}
	}
	if (S.empty()) {
		cout << "NO\n";
		return 0;
	}
	reverse(S.begin(), S.end());
	reverse(T.begin(), T.end());
	for (int l = 1; true; l++) {
		if (!testOffset(l)) {
			break;
		}
	}
	memset(z, 0, sizeof(z));
	for (int i = 0; i < int(S.size()); i++) {
		int v = S[i] - 'a';
		int p = z[i][v];
		z[i][v] = i+1;
		memcpy(z[i+1], z[p], sizeof(z[i+1]));
	}
	for (int i = 0; i < N; i++) {
		int cur = 0;
		for (int j = 0; j < L[i]; j++) {
			cur = z[cur][W[i][0][j] - 'a'];
			if (cur == int(S.size())) {
				assert(j >= int(S.size()) - 1);
				int st = j - (int(S.size()) - 1);
				for (int k = 0; k < int(S.size()); k++) {
					assert(W[i][0][st+k] == S[k]);
					W[i][0][st+k] = T[k];
				}
				break;
			}
		}
		for (int j = 0; j < L[i]; j++) {
			if (W[i][0][j] != W[i][1][j]) {
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
	cout << S << '\n';
	cout << T << '\n';
	return 0;
}