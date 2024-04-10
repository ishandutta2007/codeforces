#include <bits/stdc++.h>
using namespace std;

string A[3][1005];
int B[3];

void solve() {
	map<string, int> G;
	int N; cin >> N;
	for(int i = 3; i--;) for(int j = N; j--;) {
		string S; cin >> S;
		A[i][j] = S;
		G[S]++;
	}

	for(int i = 3; i--;) {
		B[i] = 0;
		for(int j = N; j--;) {
			int c = G[A[i][j]];
			if(1 == c) B[i] += 3;
			else if(2 == c) B[i]++;
		}
	}

	for(int i = 3; i--;) cout << B[i] << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int T; cin >> T;
	while(T--) solve();
	return 0;
}