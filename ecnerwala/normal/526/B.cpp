#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 20;
const int MAXS = 1e6;

int N;
int S;
ll A[MAXS];
int main() {
	cin >> N;
	S = (1 << N);
	for(int i = 2; i < S * 2; i++) {
		cin >> A[i];
	}
	ll res = 0;
	for(int i = S - 1; i; i--) {
		res += abs(A[2 * i] - A[2 * i + 1]);
		A[i] += max(A[2 * i], A[2 * i + 1]);
	}
	cout << res << '\n';
	return 0;
}