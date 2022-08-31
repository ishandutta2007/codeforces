#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e6;
int N;
ll P[MAXN];
ll d2[MAXN];
ll v[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P[i];
		P[i] --;
	}
	for (int i = 0; i < N; i++) {
		assert(0 <= P[i] && P[i] < N);
		v[0] += abs(P[i] - i);
		// abs(k + i - P[i])
		if (i >= P[i]) {
			d2[0] += 1;
		} else {
			d2[0] -= 1;
			d2[P[i] - i] += 2;
		}
		// k+i = N-1, k+i = N
		v[N - i] += abs(P[i]) - abs(N - 1 - P[i]) - 1;
		// abs(k + i - N - P[i])
		d2[N - i] -= 2;
		if (i >= P[i]) {
			d2[N + P[i] - i] += 2;
		}
	}
	ll slope = 0;
	for (int i = 0; i < N; i++) {
		v[i+1] += v[i];
		slope += d2[i];
		v[i+1] += slope;
	}
	assert(v[N] == v[0]);
	//for (int i = 0; i < N; i++) { cerr << v[i] << ' '; } cerr << '\n';
	if (N < 100) {
		for (int k = 0; k < N; k++) {
			ll val = 0;
			for (int i = 0; i < N; i++) {
				val += abs(P[i] - (k + i) % N);
			}
			assert(val == v[k]);
		}
	}
	int best = 0;
	for (int i = 1; i < N; i++) {
		if (v[i] < v[best]) {
			best = i;
		}
	}
	cout << v[best] << ' ' << best << '\n';
	return 0;
}