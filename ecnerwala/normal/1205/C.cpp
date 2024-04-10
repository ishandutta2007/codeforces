#include<bits/stdc++.h>
using namespace std;

const int MAXN = 60;
int N;
int V[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	memset(V, -1, sizeof(V));
	V[0][0] = 1;
	V[N-1][N-1] = 0;

	V[0][1] = 1; // just some dummy value

	auto query = [&](int x1, int y1, int x2, int y2) {
		if (V[x1][y1] != -1 && V[x2][y2] != -1) return;

		assert(x2 + y2 == 2 + x1 + y1);
		cout << "? " << x1+1 << ' ' << y1+1 << ' ' << x2+1 << ' ' << y2+1 << '\n' << flush;
		int v; cin >> v;

		assert((V[x1][y1] == -1) != (V[x2][y2] == -1));
		if (V[x1][y1] == -1) {
			swap(x1, x2); swap(y1, y2);
		}
		assert(V[x2][y2] == -1);

		V[x2][y2] = v ? V[x1][y1] : !V[x1][y1];
	};

	for (int j = 2; j < N; j++) {
		query(0, j-2, 0, j);
	}
	for (int i = 1; i < N; i++) {
		query(i-1, 0, i, 1);
		query(i-1, 1, i, 2);
		query(i, 0, i, 2);
		for (int j = 3; j < N; j++) {
			query(i, j-2, i, j);
		}
	}

	bool swapOdd = false;
	for (int i = 0; i+2 < N; i++) {
		if ((V[i][i+1] != V[i+1][i+2]) == (V[i][i] != V[i+1][i+1])) {
			cout << "? " << i+1 << ' ' << i+1 << ' ' << (i+1)+1 << ' ' << (i+2)+1 << '\n' << flush;
			int v; cin >> v;
			swapOdd = ((v == 1) != (V[i][i] == V[i+1][i+2]));
			break;
		}
		if ((V[i][i+1] != V[i+1][i+2]) == (V[i+1][i+1] != V[i+2][i+2])) {
			cout << "? " << i+1 << ' ' << (i+1)+1 << ' ' << (i+2)+1 << ' ' << (i+2)+1 << '\n' << flush;
			int v; cin >> v;
			swapOdd = ((v == 1) != (V[i][i+1] == V[i+2][i+2]));
			break;
		}
	}
	if (swapOdd) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i % 2 != j % 2) V[i][j] = !V[i][j];
			}
		}
	}

	cout << "!" << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << V[i][j];
		}
		cout << '\n';
	}
	
	return 0;
}