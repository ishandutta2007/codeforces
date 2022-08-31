#include<bits/stdc++.h>
using namespace std;

const int MAXN = 4e5;
int N;
int X[MAXN];
int Y[MAXN];

int solve3() {
	int res = 0;
	for (int z = 0; z < 2; z++) {
		for (int w = 0; w < 2; w++) {
			int val = X[0] + Y[0];
			for (int i = 1; i < N; i++) {
				val = max(val, X[i] + Y[i]);
			}
			res = max(res, 2 * (val - *min_element(X, X + N) - *min_element(Y, Y + N)));
			for (int i = 0; i < N; i++) Y[i] *= -1;
		}
		for (int i = 0; i < N; i++) X[i] *= -1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i];
	}

	int xmi = *min_element(X, X + N);
	int xma = *max_element(X, X + N);
	int ymi = *min_element(Y, Y + N);
	int yma = *max_element(Y, Y + N);

	int s4 = 2 * (xma - xmi) + 2 * (yma - ymi);

	int s3 = solve3();

	assert(3 <= N);
	cout << s3;
	for (int i = 4; i <= N; i++) {
		cout << ' ' << s4;
	}
	cout << endl;

	return 0;
}