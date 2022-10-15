#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

int T, N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> T;
	while (T--) {
		string S; cin >> S >> N;
		int rem = stoi(S);
		reverse(S.begin(), S.end());
		vector<int> counts(S.size(), 0);
		int total = 0;
		for (int i = 0; i < S.length(); i++) {
			counts[i] = S[i] - '0';
			total += counts[i];
		}

		while (total < N) {
			for (int k = 1; k < S.length(); k++) {
				if (counts[k] > 0) {
					counts[k]--;
					counts[k - 1] += 10;
					total += 9;
					break;
				}
			}
		}

		int output = 0;
		int num = 1;
		for (int k = 0; k < S.length(); k++) {
			for (int l = 0; l < counts[k]; l++) {
				if (++output == N) break;
				cout << num << ' ';
				rem -= num;
			}
			if (output == N) break;
			num *= 10;
		}
		cout << rem << '\n';
	}

	cout.flush();
	return 0;
}