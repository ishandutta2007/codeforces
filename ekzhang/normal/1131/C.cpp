#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 113
int N;
int A[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	sort(A, A + N);

	for (int i = 0; i < N; i += 2) {
		cout << A[i] << ' ';
	}

	for (int i = (N - N % 2 - 1); i >= 0; i -= 2) {
		cout << A[i] << ' ';
	}

	cout << endl;
	return 0;
}