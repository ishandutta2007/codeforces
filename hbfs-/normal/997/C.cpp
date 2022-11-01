#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
typedef long long LL;
LL n;
inline LL qp(LL a, LL b) {
	LL ret = 1LL;
	while (b) {
		if (b&1) ret = ret * a % mod;
		b >>= 1, a = a * a % mod;
	}
	return ret;
}

int main() {
	cin >> n;
	LL ans = ((qp(3,n*n)-qp(qp(3,n)-3, n))<<1) % mod, C = n;
	for (int i=1;i<=n;i++) {
		LL x = qp(3, n-i);
		LL t = (C * (qp(x, n) - qp(x-1, n)) %mod * 3LL) % mod;
		ans+=i&1?-t:t, ans%=mod;
		C = C*(n-i)%mod*qp(i+1,mod-2)%mod;
	}
	ans<0?ans+=mod:0;
	cout << ans << endl;
	return 0;
}