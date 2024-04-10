#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
const int mod=998244353;
int n,cnt[N],phi[N],fac[N],ifac[N];
bool ntp[N];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=1LL*fac[i-1]*i%mod;
	}
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i){
		ifac[i]=1LL*ifac[i+1]*(i+1)%mod;
	}
	for(int i=1;i<=n;++i)phi[i]=i;
	for(int i=2;i<=n;++i){
		if(!ntp[i]){
			for(int j=i+i;j<=n;j+=i)ntp[j]=1;
			for(int j=i;j<=n;j+=i)phi[j]=phi[j]/i*(i-1);
		}
	}
}
inline int C(int n,int m){
	if(n<0||n<m||m<0)return 0;
	return 1LL*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i)cnt[i]=0;
	for(int i=1,x;i<=n;++i){
		cin>>x;
		++cnt[x];
	}
	int g=n;
	vector<int> col;
	for(int i=1;i<=n;++i){
		if(cnt[i])g=__gcd(g,cnt[i]),col.push_back(cnt[i]);
	}
	if(col.size()==1){
		cout<<1<<'\n';
		return;
	}
	int ans0=0,ans1=0;
	for(int d=1;d<=g;++d){
		if(g%d==0){
			int w0=fac[n/d],w1=1;
			for(auto x:col){
				w0=1LL*w0*ifac[x/d]%mod;
				w1=(w1+1LL*(mod-C(n/d-2,x/d-2))*qpow(C(n/d,x/d),mod-2))%mod;
			}
			ans0=(ans0+1LL*phi[d]*w0)%mod;
			ans1=(ans1+1LL*phi[d]*w1%mod*w0%mod*n)%mod;
		}
	}
	// ans0/=n,ans1/=n;
	cout<<1LL*ans1*qpow(ans0,mod-2)%mod<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init(1000000);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}