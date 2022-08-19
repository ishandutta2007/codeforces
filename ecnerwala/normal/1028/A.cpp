#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	long long tx = 0, ty = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		string S; cin >> S;
		assert(int(S.size()) == M);
		for (int j = 0; j < M; j++) {
			if (S[j] == 'B') {
				tx += i, ty += j;
				cnt ++;
			}
		}
	}
	assert(tx % cnt == 0 && ty % cnt == 0);
	cout << (tx / cnt) + 1 << ' ' << (ty / cnt) + 1 << '\n';

	return 0;
}