#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int N, M;
int A[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N);
	long long res = 0;
	for (int i = 0; i < N-1; i++) { res += A[i];}
	int cur = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] > cur) {
			cur++;
		} else {
			res--;
		}
	}
	cout << res << '\n';

	return 0;
}