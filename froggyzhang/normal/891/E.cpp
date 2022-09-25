#include<bits/stdc++.h>
using namespace std;
#define N 5050
typedef long long ll;
const int mod=1e9+7;
int n,a[N],K,ans,all;
typedef vector<int> poly;
poly Mul(poly A,poly B){
	poly C(A.size()+B.size());
	for(int i=0;i<(int)A.size();++i){
		for(int j=0;j<(int)B.size();++j){
			C[i+j]=(C[i+j]+1LL*A[i]*B[j])%mod;
		}
	}
	return C;
}
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>K;
	all=1;
	for(int i=1;i<=n;++i)cin>>a[i],all=1LL*all*a[i]%mod;
	poly A({1});
	for(int i=1;i<=n;++i){
		A=Mul(A,poly({a[i],mod-1}));
	}
	for(int i=0,now=1;i<=min(n,K);++i){
		ans=(ans+1LL*qpow(n,K-i)*now%mod*A[i])%mod;
		now=1LL*now*(K-i)%mod;
	}
	cout<<(all-1LL*ans*qpow(qpow(n,K),mod-2)%mod+mod)%mod<<'\n';
	return 0;
}