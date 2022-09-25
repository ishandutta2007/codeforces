#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
const int mod=998244353;
int fac[N],inv[N],n,a[N];
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=1LL*fac[i-1]*i%mod;
	}
	inv[1]=1;
	for(int i=2;i<=n;++i){
		inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
	}
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	int mx=*max_element(a+1,a+n+1);
	int c1=0,c2=0;
	for(int i=1;i<=n;++i){
		c1+=a[i]==mx;
		c2+=a[i]==mx-1;
	}
	if(c1>=2){
		cout<<fac[n]<<'\n';
	}
	else{
		cout<<1LL*fac[n]*inv[c2+1]%mod*c2%mod<<'\n';	
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init(200000);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}