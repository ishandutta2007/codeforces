#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
typedef __int128 i128;
const long double eps=0.1;
const int mod=1e9+7;
int n;
ll a[N],b[N];
ll smod(ll a,ll b){
	while(a%b==0)a/=b;
	return a;	
}
ll sdiv(ll a,ll b){
	int tmp=0;
	while(a%b==0)a/=b,++tmp;
	return tmp;	
}
ll sgcd(ll a,ll b){
	if(a<b)swap(a,b);
	if(b==1)return a;
	if(a%b)return -1;
	return sgcd(b,smod(a,b));
}
int qpow(ll a,ll b){
	a%=mod;
	int ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;	
	}
	return ans;
}
#define NO (void)(cout<<-1<<'\n')
i128 exgcd(i128 a,i128 b,i128 &x,i128 &y){
	if(b==0){
		x=1,y=0;return a;	
	}
	i128 g=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return g;
}
i128 Mul(i128 a,i128 b,i128 mod){
	return a*b%mod;
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i];
	}
	ll s=1;
	for(int i=1;i<=n;++i){
		s=sgcd(s,b[i]);
		if(s==-1){
			ll k;
			auto check = [&](int i) -> bool{
				ll z=b[i]==1?0:round((log(a[1])+k*log(b[1])-log(a[i]))/log(b[i]));
				return z>=0&&a[1]%mod*qpow(b[1]%mod,k)%mod==a[i]%mod*qpow(b[i]%mod,z)%mod;
			};
			for(k=0;k<=2333;++k){
				if(check(i))break;
			}
			if(k>2333)return NO;
			for(int j=2;j<=n;++j){
				if(!check(j))return NO;
			}
			cout<<a[1]%mod*qpow(b[1]%mod,k)%mod<<'\n';
			return;
		}
	}
	if(s==1){
		for(int i=1;i<=n;++i){
			if(a[1]^a[i])return NO;
		}
		cout<<a[1]%mod<<'\n';
		return;
	}
	ll jb=smod(a[1],s);
	for(int i=2;i<=n;++i){
		if(jb^smod(a[i],s))return NO;
	}
	for(int i=1;i<=n;++i){
		a[i]=sdiv(a[i],s),b[i]=sdiv(b[i],s);
	}
	jb%=mod;
	for(int i=1;i<=n;++i){
		if(!b[i]){
			for(int j=1;j<=n;++j){
				if(b[i]==b[j]?a[i]^a[j]:(a[i]-a[j])%b[j])return NO;	
			}
			cout<<jb*qpow(s,a[i])%mod<<'\n';
			return;
		}	
	}
	i128 ans=a[1],Lcm=b[1];
	for(int i=2;i<=n;++i){
		i128 B=((a[i]-ans)%b[i]+b[i])%b[i];
		i128 x,y;
		i128 g=exgcd(Lcm,b[i],x,y);
		if(B%g)return NO;
		x=x*(B/g)%(b[i]/g);
		i128 tmp=Lcm;
		Lcm=Lcm/g*b[i];
		ans=((ans+tmp*x%Lcm)%Lcm+Lcm)%Lcm;
	}
	for(int i=1;i<=n;++i){
		if(ans<a[i])ans+=((a[i]-ans-1)/Lcm+1)*Lcm;	
	}
	cout<<jb*qpow(s,ans%(mod-1))%mod<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	Solve();
	return 0;
}