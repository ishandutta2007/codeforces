#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 200013
int N;
int A[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum += A[i];
	}

	int k = 0;
	for (int i = 0; i < N; i++) {
		k += A[i];
		if (2 * k >= sum) {
			cout << i + 1 << endl;
			return 0;
		}
	}

	cout.flush();
	return 0;
}