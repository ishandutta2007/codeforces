#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N; cin >> N;
	vector<string> a(N + 2);
	for (int i = 1; i <= N; ++i)
		cin >> a[i], a[i] = " " + a[i];

	vector<int> row(N + 2, 0), col(N + 2, 0);
	reverse(a.begin() + 1, a.begin() + N + 1);

	int sol = 0;
	for (int i = 1; i < N; ++i)
		for (int j = 1; j <= N - i; ++j) {
			int v = a[i][j] - '0';
			v ^= row[i] ^ col[j];
			if (v == 1) {
				++sol;
				row[i] ^= 1;
				col[j] ^= 1;
				//cerr << N - i + 1 << " " << j << "\n";
			}
		}
	for (int i = 1; i <= N; ++i) {
		int v = a[i][N - i + 1] - '0';
		v ^= row[i] ^ col[N - i + 1];
		a[i][N - i + 1] = v + '0';
	}

	row = col = vector<int>(N + 2, 0);

	for (int i = N; i > 1; --i)
		for (int j = N; j > N - i + 1; --j) {
			int v = a[i][j] - '0';
			v ^= row[i] ^ col[j];
			if (v == 1) {
				++sol;
				row[i] ^= 1;
				col[j] ^= 1;
				//cerr << N - i + 1 << " " << j << "\n";
			}
		}
	
	for (int i = 1; i <= N; ++i) {
		int v = a[i][N - i + 1] - '0';
		v ^= row[i] ^ col[N - i + 1];
		if (v == 1) {
			++sol;
			//cerr << N - i + 1 << " " << N - i + 1<< "\n";
		}
	}
	cout << sol;
}