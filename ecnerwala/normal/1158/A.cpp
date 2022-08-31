#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1.1e5;
const int MAXM = 1.1e5;
int N;
ll B[MAXN];
int M;
ll G[MAXM];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> B[i];
	for (int j = 0; j < M; j++) cin >> G[j];
	sort(B, B + N);
	sort(G, G + M);
	if (B[N-1] > G[0]) {
		cout << -1 << '\n';
		exit(0);
	}
	assert(N >= 2 && M >= 2);
	ll res = 0;
	for (int i = 0; i < N; i++) {
		res += B[i] * M;
	}
	for (int i = 0; i < M; i++) {
		res += G[i];
	}
	res -= B[N-1] * (M-1);
	if (G[0] == B[N-1]) {
		res -= B[N-1];
	} else {
		res -= B[N-2];
	}
	cout << res << '\n';

	return 0;
}