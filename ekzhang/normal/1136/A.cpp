#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 103
int N;
int L[MAXN], R[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> L[i] >> R[i];
	int k; cin >> k;

	for (int i = 0; i < N; i++) {
		if (k <= R[i]) {
			cout << N - i << endl;
			break;
		}
	}

	cout.flush();
	return 0;
}