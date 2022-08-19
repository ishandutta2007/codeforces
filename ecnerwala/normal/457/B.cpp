#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXM = 2e5, MAXN = 2e5;
int M;
ll A[MAXM];
int N;
ll B[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> M >> N;
	for(int i = 0; i < M; i++) {
		cin >> A[i];
	}
	for(int i = 0; i < N; i++) {
		cin >> B[i];
	}

	sort(A, A + M);
	sort(B, B + N);
	if(A[M - 1] < B[N - 1]) {
		for(int i = 0; i < max(M, N); i++) {
			swap(A[i], B[i]);
		}
		swap(M, N);
	}
	//a has bigger last one
	ll sb = 0;
	for(int i = 0; i < N; i++) sb += B[i];
	ll res = 0;
	res += sb;
	for(int i = 0; i < M - 1; i++) {
		res += min(A[i], sb);
	}
	cout << res << '\n';
	return 0;
}