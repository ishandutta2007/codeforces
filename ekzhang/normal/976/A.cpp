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
	sort(S.begin() + 1, S.end());

	int i;
	for (i = 1; i < N; i++) {
		if (S[i] == '1')
			break;
	}

	cout << S.substr(0, i) << endl;
	return 0;
}