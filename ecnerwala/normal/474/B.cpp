#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int N;
int A[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	for(int i = 0; i < N; i++) cin >> A[i];
	for(int i = 0; i < N; i++) {
		A[i + 1] += A[i];
	}
	int M; cin >> M;
	for(int i = 0; i < M; i++) {
		int q; cin >> q;
		cout << lower_bound(A, A + N, q) - A + 1 << '\n';
	}
	return 0;
}