#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 5e5;

int N;
int A[MAXN];

int gcd[MAXN];

int is_max[MAXN];
int cnt[MAXN];

int main() {
	ios_base::sync_with_stdio(0);

	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		A[i + N] = A[i];
	}

	ll res = 0;

	for(int g = 1; g <= N; g++) {
		if(N % g) continue;
		for(int j = g; j <= N; j += g) {
			gcd[j] = g;
		}
	}

	for(int g = 1; g <= N; g++) {
		if(N % g) continue;
		for(int i = 0; i < g; i++) {
			int m = 0;
			for(int j = i; j < N; j += g) {
				m = max(m, A[j]);
			}
			for(int j = i; j < N * 2; j += g) {
				is_max[j] = (A[j] == m);
			}
		}
		for(int j = 1; j < N * 2; j++) {
			if(is_max[j]) is_max[j] += is_max[j - 1];
		}
		cnt[0] = 0;
		for(int i = 1; i < N; i++) {
			cnt[i] = cnt[i - 1] + (gcd[i] == g);
		}
		for(int j = N; j < N * 2; j++) {
			res += cnt[min(is_max[j], N - 1)];
		}
	}

	cout << res << '\n';

	return 0;
}