#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL mod = 998244353;
#define maxn 1200000
LL f[maxn];
LL power(LL a, LL r){
	LL res = 1;
	for(; r; r >>= 1, a = a * a % mod)
		if(r & 1) res = res * a % mod;
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i <= n; i += 1) f[i] = i ? f[i - 1] * i % mod : 1;
	LL ans = 0;
	for(int i = 1; i < n; i += 1){
		LL k = f[n] * power(f[n - i], mod - 2) % mod;
		LL p = f[n - i] - 1;
		ans = (ans + k * p % mod) % mod;
	}
	cout << (ans + f[n]) % mod;
}