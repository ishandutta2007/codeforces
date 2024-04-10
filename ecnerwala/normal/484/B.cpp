#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;
int N;

int A[MAXN];

int main() {
	cin >> N;
	for(int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);
	N = unique(A, A + N) - A;

	int res = 0;
	for(int i = 0; i < N; i++) {
		int v = A[i];
		for(int x = v; x <= A[N - 1]; x+=v) {
			int a = *(lower_bound(A, A + N, x + v) - 1);
			if(a < x) continue;
			res = max(res, a - x);
		}
	}
	cout << res << '\n';

	return 0;
}