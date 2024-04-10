#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
inline int read(void) {
	int x = 0, c = 0, f = 1;
	for(;c<'0'||c>'9';c=getchar())f=c!='-';
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return f ? x : -x;
}
const int N = 200000,mod=1e9+7;
int inv[N+10],fac[N+10],facinv[N+10];
void init(void) {
	inv[1]=fac[0]=facinv[0]=1;
	for(int i=2;i<=N;i++)inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=N;i++)fac[i]=1LL*fac[i-1]*i%mod;
	for(int i=1;i<=N;i++)facinv[i]=1LL*facinv[i-1]*inv[i]%mod;
}
inline int C(int n,int m){
	if (n < m) return 0;
	return 1LL*fac[n]*facinv[m]%mod*facinv[n-m]%mod;
}
int n, a[N+20], b[N+20],c[N+20];
int main() {
	init();
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	if(n==1){cout<<a[1]<<endl;return 0;}
	else if(n==2){cout<<(a[1]+a[2])%mod<<endl;return 0;}
	b[1] = 1;
	int t=1;
	if (n%2==1)
		if (n % 4 == 3) {
			int m=n-1;
			c[1]=1;
			for (int i=2;i<=m;i++)
				c[i]=C(m/2-1,(i+1)/2-1);
			for (int i = 2; i <= n; i++,t^=1)
				if (t) b[i] = c[i]+c[i-1]; 
				else b[i]=c[i]-c[i-1];
		} else {
			for (int i=2;i<=n;i++)
				if (i%2) b[i] = C(n/2,i/2);
		}
	else {
		if (n % 4)
			for (int i=2;i<=n;i++)
				b[i]=C(n/2-1,(i+1)/2-1);
		else 
			for (int i =2; i <= n; i++)
				if (i % 2) b[i] = C(n/2-1,(i+1)/2-1);
				else b[i] = -C(n/2-1,(i+1)/2-1);
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += 1LL * a[i] * b[i] % mod;
		ans %= mod;
	}
	/*for (int i = 1; i <= n; i++)
		cout << b[i] << " \n"[i==n]; */
	cout << (ans%mod+mod)%mod << endl;
}