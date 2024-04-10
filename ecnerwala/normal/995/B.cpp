#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200;
int N;
int A[2 * MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N * 2; i++) {
		cin >> A[i];
	}
	int res = 0;
	for (int i = 0; i < 2 * N; i += 2) {
		int j = i+1;
		while (A[j] != A[i]) {
			j ++;
		}
		for (;j > i+1; j--) {
			A[j] = A[j-1];
			res++;
		}
		A[i+1] = A[i];
	}
	cout << res << '\n';

	return 0;
}