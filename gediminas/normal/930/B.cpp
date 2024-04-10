/*input
technocup
tictictactac
bbaabaabbb
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string a;

	cin >> a;
	long double ats = 0;

	int kiek[26][50000][26] = {};
	int kiekv[26] = {};

	for (int k = 0; k < a.size(); k++) {
		int kk = a[k] - 'a';
		kiekv[kk]++;

		for (int i = 0; i < a.size(); i++) {
			kiek[kk][i][a[(i + k) % a.size()] - 'a']++;
		}
	}

	for (int i = 0; i < 26; i++) {

		long double ma = 0;

		if (kiekv[i] > 0) {
			for (int j = 0; j < a.size(); j++) {
				long double t = 0;

				for (int k = 0; k < 26; k++) {
					if (kiek[i][j][k] == 1) {
						t += 1.0l / kiekv[i];
					}
				}

				ma = max(ma, t);
			}

			ats += ma * kiekv[i];
		}
	}

	cout << fixed << setprecision(16) << ats / a.size() << endl;
	return 0;
}