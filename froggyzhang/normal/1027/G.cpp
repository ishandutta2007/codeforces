#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,t;
ll ans;
ll get_phi(ll x){
	ll ans=x;
	for(ll i=2;i*i<=x;++i){
		if(x%i==0){
			ans=ans/i*(i-1);
			while(x%i==0)x/=i;
		}
	}	
	if(x>1)ans=ans/x*(x-1);
	return ans;
}
typedef long double ld;
const ld eps=1e-5;
inline ll Mul(ll a,ll b,ll mod){
	ll tmp=a*b-(ll)((ld)a/mod*b+eps)*mod;
	while(tmp<0)tmp+=mod;
	return tmp;
}
/*
ll qpow(ll a,ll b,ll mod){
	ll ans=1;
	a%=mod;
	while(b){
		if(b&1)ans=Mul(ans,a,mod);
		a=Mul(a,a,mod);
		b>>=1;
	}
	return ans;
}
*/
#define N 10001000
ll A[N],B[N];
int len;
vector<ll> fac;
ll lpow(ll b,ll mod){
	return Mul(A[b%len]%mod,B[b/len]%mod,mod);	
}
ll Solve(ll d){
	if(d==1)return 1;
	ll phi=get_phi(d);
	for(auto i:fac){
		if(phi%i==0&&lpow(i,d)==1){
			return phi/i;	
		}	
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>t;
	len=(int)ceil(sqrt(n));
	A[0]=1;
	for(int i=1;i<=len;++i){
		A[i]=Mul(A[i-1],t,n);
	}
	B[0]=1;
	for(int i=1;i<=len;++i){
		B[i]=Mul(B[i-1],A[len],n);	
	}
	ll _n=get_phi(n);
	for(ll i=1;i*i<=_n;++i){
		if(_n%i==0){
			fac.push_back(i);
			if(i*i!=_n)fac.push_back(_n/i);
		}	
	}
	sort(fac.begin(),fac.end());
	for(ll i=1;i*i<=n;++i){
		if(n%i==0){
			ans+=Solve(i);
			if(i*i!=n)ans+=Solve(n/i);
		}	
	}
	cout<<ans<<'\n';
	return 0;
}