#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAX (1<<18)
int N, R;
int A[MAX];
LL sum = 0;

void go() {
	cout << fixed << setprecision(8) << (long double) 1 * sum / (1<<N) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> R;
	for (int i = 0; i < (1<<N); i++) {
		cin >> A[i];
		sum += A[i];
	}

	go();
	while (R--) {
		int i, z;
		cin >> i >> z;
		sum += z - A[i];
		A[i] = z;
		go();
	}

	cout.flush();
	return 0;
}