#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=3e6+2;
typedef array<ll,2> arin;
arin zero,one;
arin operator+(arin x,arin y){
	arin z=zero;
	for(int i=0; i<2 ;i++){
		z[i]=(x[i]+y[i])%mod;
	}
	return z;
}
arin operator*(arin x,arin y){
	arin z=zero;
	ll z0=x[0]*y[0];
	ll z1=x[0]*y[1]+x[1]*y[0];
	ll z2=x[1]*y[1];
	z0=((z0-z2)%mod+mod)%mod;
	z1=((z1-z2)%mod+mod)%mod;
	z={z0,z1};
	return z;
}
arin pw(arin x,ll y){
	if(y==0) return {1,0};
	if(y%2) return x*pw(x,y-1);
	arin res=pw(x,y/2);
	return res*res;
}
int n,q;
ll f[N],inf[N];
ll ans[N];
ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2) return x*pw(x,y-1)%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}
ll C(ll x,ll y){
	return f[x]*inf[y]%mod*inf[x-y]%mod;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> q;
	f[0]=1;int iu=3*n+1;
	for(int i=1; i<=iu ;i++) f[i]=f[i-1]*i%mod;
	inf[iu]=pw(f[iu],mod-2);
	for(int i=iu; i>=1 ;i--) inf[i-1]=inf[i]*i%mod;
	one={1,0};
	arin f1=one;
	ll f0;
	ll diu=pw(3,mod-2);
	for(int i=1; i<=3*n ;i++){
		ll tmp=C(3*n+1,i);
		f1=(f1+arin{mod-tmp,0});
		f1=(f1*arin{0,1});
		f1=f1*arin{diu*2%mod,diu};
		f0=C(3*n+1,i+1);
		ans[i]=(f0+f1[0]+f1[0]-f1[1]+mod)%mod;
		//cout << f0 << ' ' << f1[0] << ' ' << f1[1] << ' ' << tmp << ' ' << ans[i] << endl;
		ans[i]=ans[i]*diu%mod;
	}
	for(int i=1; i<=q ;i++){
		int x;cin >> x;
		cout << ans[x] << '\n';
	}
	cout << endl;
}