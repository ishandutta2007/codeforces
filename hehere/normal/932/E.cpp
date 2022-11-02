#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL P = 1000000007;
const int maxN = 1000000000 + 233;
const int maxK = 5000 + 5;
LL qpow(LL a, LL b) {
	LL r = 1;
	while(b) {
		if(b & 1) (r *= a) %= P;
		(a *= a) %= P; b >>= 1;
	}
	return r;
}
int N, K, S[maxK][maxK];
#ifdef DEBUG
LL bf() {
	static LL fac[maxK], ifac[maxK];
	int n = N, k = K;
	fac[0] = 1;
	for(int i = 1; i <= n; ++ i) fac[i] = fac[i - 1] * i % P;
	ifac[n] = qpow(fac[n], P - 2);
	for(int i = n - 1; i >= 0; -- i) ifac[i] = ifac[i + 1] * (i + 1) % P;
	LL sum = 0;
	for(int x = 1; x <= n; ++ x) {
		(sum += qpow(x, k) * fac[n] % P * ifac[x] % P * ifac[n - x]) %= P;
	}
	return sum;
}
#endif

int main() {
	cin >> N >> K;
	memset(S, 0, sizeof(S));
	S[0][0] = 1;
	for(int n = 1; n <= K; ++ n)
		for(int k = 1; k <= K; ++ k)
			S[n][k] = (S[n - 1][k - 1] + (LL)S[n - 1][k] * k) % P;
//	for(int n = 0; n <= K; ++ n)
//		for(int k = 0; k <= K; ++ k)
//			printf("%d%c", S[n][k], " \n"[k == K]);
	LL ans = 0;
	LL falling = 1;
	for(int i = 1; i <= K && i <= N; ++ i) {
		(falling *= (N - i + 1)) %= P;
		(ans += S[K][i] * falling % P * qpow(2, N - i)) %= P;
	}
	cout << ans << endl;
#ifdef DEBUG
	cerr << bf() << endl;
#endif
	return 0;
}