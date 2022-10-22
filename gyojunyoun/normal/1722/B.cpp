#include <bits/stdc++.h>
using namespace std;

bool solve() {
	int N;
	string A, B;
	cin >> N >> A >> B;
	for(int i = N; i--;) {
		if('G' == A[i]) A[i] = 'B';
		if('G' == B[i]) B[i] = 'B';
	}
	return A == B;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int T; cin >> T;
	while(T--) puts(solve() ? "YES" : "NO");
	return 0;
}