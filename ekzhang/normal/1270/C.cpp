#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
int T;
int N, A[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> T;
	while (T--) {
		cin >> N;
		LL s = 0, x = 0;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
			s += A[i];
			x ^= A[i];
		}

		LL a = x;
		LL b = s + a;
		cout << 2 << '\n' << a << ' ' << b << '\n';
	}

	cout.flush();
	return 0;
}