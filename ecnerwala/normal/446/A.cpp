#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
int N;
int A[MAXN];

int maxL[MAXN];
int maxR[MAXN];

int main() {
	cin >> N;
	for(int i = 0; i < N; i++) cin >> A[i];

	if(N <= 2) {
		cout << N << '\n';
		return 0;
	}

	int res = 1;
	int val = maxL[0] = 1;
	for(int i = 1; i < N; i++) {
		if(A[i] > A[i - 1]) {
			val++;
		} else {
			val = 1;
		}
		maxL[i] = val;
		if(val > res) res = val;
	}
	val = maxR[N - 1] = 1;
	for(int i = N - 2; i >= 0; i--) {
		if(A[i] < A[i + 1]) {
			val++;
		} else {
			val = 1;
		}
		maxR[i] = val;
		if(val > res) res = val;
	}

	res++;
	if(res > N) {
		cout << N << '\n';
		return 0;
	}

	for(int i = 0; i + 2 < N; i++) {
		if(A[i] + 1 < A[i + 2]) {
			int v = maxL[i] + maxR[i + 2] + 1;
			if(v > res) res = v;
		}
	}

	cout << res << '\n';
	return 0;
}