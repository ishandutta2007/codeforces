#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5;
int N, M;
int A[MAXN];
int B[MAXN];
int S = 0;
int V[MAXN];

pair<int, int> score (int d) {
	int a = 3 * N - (upper_bound(A, A + N, d) - A);
	int b = 3 * M - (upper_bound(B, B + M, d) - B);
	//cerr << d << ' ' << a << ' ' << b << '\n';
	return make_pair(a - b, a);
}

int main() {
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		V[S++] = A[i];
	}
	cin >> M;
	for(int j = 0; j < M; j++) {
		cin >> B[j];
		V[S++] = B[j];
	}
	sort(A, A + N);
	sort(B, B + M);
	sort(V, V + S);
	S = unique(V, V + S) - V;
	pair<int, int> res = score(0);
	for(int i = 0; i < S; i++) {
		res = max(res, score(V[i]));
	}
	cout << res.second << ':' << res.second - res.first << '\n';
	return 0;
}