#include<bits/stdc++.h>
using namespace std;

int ans[2000][2000];

const int A4[4][4] = {
	{8, 9, 1, 13},
	{3, 12, 7, 5},
	{0, 2, 4, 11},
	{6, 10, 15, 14},
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	assert(N % 4 == 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans[i][j] = A4[i % 4][j % 4] | (((i/4) * (N/4) + (j/4)) * 16);
			cout << ans[i][j] <<  " \n"[j+1==N];
		}
	}

	/*
	for (int i = 0; i < N; i++) {
		int v = 0; 
		int u = 0;
		for (int j = 0; j < N; j++) {
			v ^= ans[i][j];
			u ^= ans[j][i];
		}
		cerr << v << ' ' << u << '\n';
	}
	*/

	return 0;
}