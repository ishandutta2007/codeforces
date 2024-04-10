#include <iostream>
#include <cstdio>

using namespace std;

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)
const int MD = 1e9 + 7;

const int MN = 1e6 + 100;
const int MM = 1e6 + 100;

int N, M, A, B;
ll F[MM+MN][2];
ll I[MM+MN];

void pcpm() {
	I[0] = 0LL;
	I[1] = 1LL;
	for(int i = 2; i < MM+MN; ++i)
  I[i] = (MD - (MD/i) * I[MD%i] % MD) % MD;
	
	F[0][0] = 1LL, F[0][1] = 1LL;
	for(int i = 1;i < MM+MN;i++) F[i][0] = F[i-1][0]*i%MD, F[i][1] = F[i-1][1]*I[i]%MD;
}

ll ch(int n, int k) {
	return F[n][0]*F[k][1]%MD*F[n-k][1]%MD;
}

ll pw(ll b, ll p) {
	if(p < 0) return 1LL;
	ll r = 1LL;
	for(;p;b=b*b%MD,p>>=1) if(p&1)r=r*b%MD;
	return r;
}
ll dst(int n, int k) {
	return ch(n-1, k-1);
}
ll dst2(int n, int k) {
	return ch(n+k-1, k-1);
}

ll count(int n, int k) {
	if(n == k) return 1;
	return k*pw(n, n-k-1)%MD;
}

int main() {
	pcpm();
	
	scanf("%d%d%d%d", &N, &M, &A, &B);
	
	ll f = 0LL;
	for(int i = 0;i <= N-2;i++) {
		if(i >= M) break;
		ll t = dst(M, i+1);
		t = t*pw(M, N-i-2)%MD;		//fix edge lens
		t = t*count(N, i+2)%MD;
		t = t*ch(N-2, i)%MD*F[i][0]%MD;
		f = (f+t)%MD;
	}
	
	//cerr << dst(15, 4) << "\n";
	
	printf("%lld\n", f);
	
	return 0;
}