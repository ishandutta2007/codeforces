#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 200013
int N;
LL A[MAXN];
LL B[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N / 2; i++)
		cin >> B[i];

	LL lastf = 0, lasts = 1000000000000000000;
	for (int i = 0; i < N / 2; i++) {
		LL f = 0, s = B[i];
		if (lastf > f) {
			s -= lastf - f;
			f += lastf - f;
		}
		if (lasts < s) {
			f += s - lasts;
			s -= s - lasts;
		}
		A[i] = lastf = f;
		A[N - 1 - i] = lasts = s;
	}

	for (int i = 0; i < N; i++)
		cout << A[i] << ' ';

	cout << endl;
	return 0;
}