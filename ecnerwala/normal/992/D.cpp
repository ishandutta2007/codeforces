#include <iostream>
using namespace std;

typedef long long ll;

ll INF = ll(3e18);

const int MAXN = 4e5;
const int MAXK = 2e5;
int N, K;
const int MAXM = MAXN;
int M;
ll A[MAXM];
ll C1[MAXM];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		if (a == 1) {
			C1[M] ++;
		} else {
			A[M++] = a;
		}
	}
	ll res = 0;
	for (int i = 0; i <= M; i++) {
		if (K == 1) res += C1[i];
	}
	for (int i = 0; i < M; i++) {
		ll p = 1;
		ll s = 0;
		for (int j = i; j < M; j++) {
			if (j > i) s += C1[j];
			if (!(p <= INF / A[j])) break;
			p *= A[j], s += A[j];
			ll n1 = p - (K * s);
			if (n1 < 0) continue;
			if (n1 % K != 0) continue;
			n1 /= K;
			if (n1 <= C1[i] + C1[j+1]) {
				// we want to pick a so that
				// 0 <= a <= C[i]
				// 0 <= n1-a <= C[j+1]
				// so 
				// max(0, n1 - C[j+1]) <= a <= min(n1, C[i])
				res += min(n1, C1[i]) - max(0ll, n1 - C1[j+1]) + 1;
			}
		}
	}
	cout << res << '\n';
	return 0;
}