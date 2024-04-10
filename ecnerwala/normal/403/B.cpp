#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 1e4;
const int MAXM = 1e4;

int N, M;
int A[MAXN];
int B[MAXM];
int G[MAXN];

int P;
int primes[4000];

bool isPrime(int v) {
	for(int i = 2; i * i <= v; i++) {
		if(v % i == 0) return false;
	}
	return true;
}

void precomp() {
	P = 0;
	for(int i = 2; P < 4000; i ++) {
		if(isPrime(i)) primes[P++] = i;
	}
}

int gcd(int a, int b) {
	return a ? gcd(b % a, a) : b;
}

int f(int v) {
	int res = 0;
	for(int i = 0; i < P && primes[i] * primes[i] <= v; i++) {
		if(v % primes[i] == 0) {
			int cnt = 0;
			while(v % primes[i] == 0) v /= primes[i], cnt++;
			if(binary_search(B, B + M, primes[i])) res -= cnt;
			else res += cnt;
		}
	}
	if(v != 1) {
		if(binary_search(B, B + M, v)) res --;
		else res++;
	}
	return res;
}

int main() {
	precomp();
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for(int i = 0; i < M; i++) {
		cin >> B[i];
	}
	G[0] = A[0];
	for(int i = 1; i < N; i++) {
		G[i] = gcd(G[i - 1], A[i]);
	}
	int res = 0;
	for(int i = 0; i < N; i++) res += f(A[i]);
	//cerr << res << '\n';
	int v = 1;
	for(int i = N - 1; i >= 0; i--) {
		//cerr << G[i] / v << '\n';
		//cerr << f(G[i] / v) << '\n';
		if(f(G[i] / v) < 0) {
			res += (-f(G[i] / v)) * (i + 1);
			v = G[i];
		}
	}
	cout << res << '\n';
	return 0;
}