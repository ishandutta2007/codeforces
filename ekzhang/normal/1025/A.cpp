#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

int N;
string S;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> S;
	for (char c = 'a'; c <= 'z'; c++) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (S[i] == c)
				++cnt;
		}
		if (N == 1 || cnt >= 2) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;
	return 0;
}