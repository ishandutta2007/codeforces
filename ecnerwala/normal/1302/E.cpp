#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1.1e5;
int N;
int A[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	int unique_bits = 0;
	int all_bits = 0;
	for (int i = 0; i < N; i++) {
		unique_bits = (unique_bits & ~A[i]) | ((all_bits | A[i]) - all_bits);
		all_bits |= A[i];
	}
	if (unique_bits) {
		for (int i = 0; i < N; i++) {
			if ((A[i] & unique_bits) && __builtin_clz(A[i] & unique_bits) == __builtin_clz(unique_bits)) {
				swap(A[i], A[0]);
				break;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << A[i] << " \n"[i+1==N];
	}

	return 0;
}