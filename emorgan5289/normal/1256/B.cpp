#include <fstream>
#include <iostream>

using namespace std;

int Q, N, data[100];

void solve(int l, int h) {
	// cout << l << " " << h << endl;
	if (h == l)
		return;
	int x = 101, m = -1;
	for (int i = l; i < h; i++) {
		if (data[i] < x) {
			x = data[i];
			m = i;
		}
	}
	if (m == l) {
		solve(l+1, h);
		return;
	}
	int sto = data[m];
	data[m] = data[m-1];
	data[m-1] = sto;
	solve(l, m);
	solve(m, h);
}

int main() {
	cin >> Q;
	for (int q = 0; q < Q; q++) {
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> data[i];
		solve(0, N);
		for (int i = 0; i < N-1; i++) {
			cout << data[i] << " ";
		}
		cout << data[N-1] << endl;
	}
}