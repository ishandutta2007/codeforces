#include<bits/stdc++.h>
using namespace std;
#define N 500010
const int mod=998244353;
typedef long long ll;
int n,a[N];
int fac[N],ifac[N];
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
}
inline int C(int n,int m){
	return 1LL*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
mt19937 rnd(time(0));
inline int rd(int l,int r){
	return rnd()%(r-l+1)+l;
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	while(n>1){
		if(!a[n-1])break;
		int pos=n;
		while(a[pos])--pos;
		pos=max(pos,1);
		for(int i=pos;i<n;++i){
			a[i]=a[i+1]-a[i];
		}
		sort(a+pos,a+n);
		--n;
	}
	cout<<a[n]<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}