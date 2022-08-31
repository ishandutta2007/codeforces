#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const ll N=2e6+1;
ll n,m,h,l,z;
ll pn,pm,in,im;
ll a[N],b[N];
ll f[N],g[N];
ll gcd(ll x,ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}
ll phi(ll z){
	ll ans=z;
	for(int i=2; i<=z ;i++){
		if(z%i==0){
			while(z%i==0) z/=i;
			ans=ans/i*(i-1);
		}
	}
	return ans;
}
ll pw(ll x,ll y,ll z){
	if(y==0) return 1%z;
	if(y%2) return x*pw(x,y-1,z)%z;
	ll res=pw(x,y/2,z);
	return res*res%z;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m >> z;
	h=gcd(n,m);
	l=n*m/h;
	pn=phi(n/h);pm=phi(m/h);
	in=pw(n/h,pm-1,m/h);
	im=pw(m/h,pn-1,n/h);
	int k=2*max(n,m);
	
	for(int i=1; i<=k ;i++) f[i]=g[i]=-1;
	for(int i=0; i<n ;i++){
		cin >> a[i];
		f[a[i]]=i;
	}
	for(int i=0; i<m ;i++){
		cin >> b[i];
		g[b[i]]=i;
	}
	vector<ll>gay;
	for(int i=1; i<=k ;i++){
		if(f[i]!=-1 && g[i]!=-1){
			if(f[i]%h!=g[i]%h) continue;
			ll da=f[i]/h;
			ll db=g[i]/h;
			ll dc=l/h;
			ll tmp=((da*im%l*m%l+db*in%l*n%l)+f[i]%h)%l;
			gay.push_back(tmp);
		}
	}
	sort(gay.begin(),gay.end());
	ll p=l-gay.size();
	gay.push_back(l);
	z--;
	ll ans=(z/p)*l;z%=p;
	for(int i=0; i<gay.size() ;i++){
		if(z<gay[i]-i){
			cout << ans+z+i+1 << '\n';
			return 0;
		}
	}
}