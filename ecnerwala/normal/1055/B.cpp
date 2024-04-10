#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 2e5;
int N, Q; ll L;
ll A[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> Q >> L;
	A[0] = -1;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	A[N+1] = -1;
	int cost = 0;
	for (int i = 1; i <= N; i++) {
		cost += (A[i-1] <= L && A[i] > L);
	}
	for (int q = 0; q < Q; q++) {
		int t; cin >> t;
		if (t == 0) {
			cout << cost << '\n';
		} else if (t == 1) {
			int p; ll d; cin >> p >> d;
			cost -= (A[p-1] <= L && A[p] > L);
			cost -= (A[p] <= L && A[p+1] > L);
			A[p] += d;
			cost += (A[p-1] <= L && A[p] > L);
			cost += (A[p] <= L && A[p+1] > L);
		} else assert(false);
	}

	return 0;
}