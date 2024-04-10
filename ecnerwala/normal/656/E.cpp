#include<bits/stdc++.h>
using namespace std;

int N;
int d[200][200];

int read_input(int i = 0) {
	return (i == N * N) ? 0 : (
			cin >> d[i / N][i % N],
			read_input(i + 1)
			);
}

int asp(int v = 0) {
	int k = v / N / N;
	int i = v / N % N;
	int j = v % N;
	return (v == N * N * N) ? 0 : (
			d[i][j] = min(d[i][j], d[i][k] + d[k][j]),
			asp(v + 1)
			);
}

int res(int v = 0) {
	return (v == N * N) ? 0 : max(d[v / N][v % N], res(v + 1));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	read_input();
	asp();
	cout << res() << '\n';
	return 0;
}