#include <bits/stdc++.h>
using namespace std;

#define MAXLEN 100

string S1, S2, V;
string dp[MAXLEN + 1][MAXLEN + 1][MAXLEN]; // exclusive
int aux[MAXLEN][26];
vector<int> aux2[MAXLEN];
bool tozero[MAXLEN][26];

int main() {

	// freopen("input.txt", "r", stdin);

	cin >> S1 >> S2 >> V;
	int size1 = S1.size();
	int size2 = S2.size();
	int sizeV = V.size();

	// calculate auxillary stuff
	// not very efficient but doesn't really matter!
	for (int i = 0; i < sizeV; i++) {
		for (int j = 0; j < 26; j++) {
			char c = 'A' + j;
			for (int postest = 0; postest < i; postest++) {
				if (V[i - postest] != c) {
					continue;
				}
				bool good = true;
				for (int idx = 0; idx < i - postest; idx++) {
					if (V[idx] != V[idx + postest]) {
						good = false;
						break;
					}
				}
				if (good) {
					aux[i][j] = i - postest + 1;
					break;
				}
			}
			if (aux[i][j] == 0 && c == V[0]) {
				aux[i][j] = 1;
			}
		}
	}

	// make second auxillary using first auxillary array
	for (int i = 0; i < sizeV; i++) {
		for (int j = 0; j < 26; j++) {
			if (aux[i][j] != 0 && aux[i][j] != sizeV) {
				aux2[aux[i][j]].push_back(i);
			}
			else if (aux[i][j] == 0) {
				tozero[i][j] = true;
			}
		}
	}

	string ans = "";
	for (int i = 1; i <= size1; i++) {
		for (int j = 1; j <= size2; j++) {
			for (int k = 0; k < sizeV; k++) {
				if (dp[i-1][j][k].size() > dp[i][j-1][k].size()) {
					dp[i][j][k] = dp[i-1][j][k];
				}
				else {
					dp[i][j][k] = dp[i][j-1][k];
				}
				if (k == 0) {
					if (S1[i - 1] == S2[j - 1] && S1[i - 1] != V[0]) {
						for (int from = 0; from < sizeV; from++) {
							if (tozero[from][S1[i - 1] - 'A']) {
								string next = dp[i-1][j-1][from] + string(1, S1[i - 1]);
								if (next.size() > dp[i][j][k].size()) {
									dp[i][j][k] = next;
								}
							}
						}
					}
				}
				else {
					if (S1[i - 1] == S2[j - 1] && S1[i - 1] == V[k - 1]) {
						for (int from : aux2[k]) {
							string next = dp[i-1][j-1][from] + string(1, V[k - 1]);
							if (next.size() > dp[i][j][k].size()) {
								dp[i][j][k] = next;
							}
						}
					}
				}

				if (dp[i][j][k].size() > ans.size()) {
					ans = dp[i][j][k];
				}
			}
		}
	}

	if (ans.size() != 0) {
		cout << ans << endl;
	}
	else {
		cout << 0 << endl;
	}
	return 0;
}