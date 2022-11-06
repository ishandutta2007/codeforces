#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
inline int read(void){
	int x = 0, c = 0, f = 1;
	for (;c<'0'||c>'9';c=getchar())f=c!='-';
	for (;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return f ? x : -x;
}
const int N = 301000, mod = 1000000007;
int n, a[N];
LL ans;
int pw(int n,int m){
	int ret=1;
	for(;m;m>>=1,n=1LL*n*n%mod)
		if(m&1)ret=1LL*ret*n%mod;
	return ret;
}
int main() {
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	sort(a+1,a+n+1);
	for (int i = 1; i <= n; i++) {
		int x = a[i];
		ans += 1LL * x * (pw(2, i - 1)-pw(2, n - i)) % mod;
	}
	cout << (ans % mod + mod) % mod << endl;
}