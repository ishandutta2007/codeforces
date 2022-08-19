#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 4e5;
int N;
ll V[MAXN];
uint64_t M[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)  {
		cin >> V[i] >> M[i];
	}
	ll sum = 0;
	for (int i = 0; i < N; i++) {
		sum += V[i];
	}
	if (sum > 0) {
		for (int i = 0; i < N; i++) {
			V[i] = -V[i];
		}
		sum = -sum;
	}
	assert(sum < 0);
	// want anything positive

	uint64_t s = 0;
	for (int b = 0; b < 62; b++) {
		ll ev1 = 0;
		for (int i = 0; i < N; i++) {
			if (M[i] >> (b+1)) {
				// 0 ev
			} else {
				if (__builtin_popcountll(M[i] & (s | (1ull << b))) & 1) {
					ev1 -= V[i];
				} else {
					ev1 += V[i];
				}
			}
		}
		if (ev1 > 0) {
			s |= (1ull << b);
		}
	}
	cout << s << '\n';
	ll final_sum = 0;
	for (int i = 0; i < N; i++) {
		final_sum += __builtin_popcountll(M[i] & s) & 1 ? -V[i] : V[i];
	}
	//cerr << final_sum << '\n';

	return 0;
}