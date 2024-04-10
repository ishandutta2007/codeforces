#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
int n;
ll m;
ll p[100002];
ll a[100002];
int f1[100002];
int first1;
ll phi(ll num){
	ll bnd=sqrt(num);
	ll ans=num;
	for(int i=2; i<=bnd ;i++){
		if(num%i==0){
			ans=ans/i*(i-1);
			while(num%i==0) num/=i;
		}
	}
	if(num!=1) ans=ans/num*(num-1);
	return ans;
}
ll pow(ll x,ll y,ll mod){
	if(y==0) return 1;
	ll res=pow(x,y/2,mod);
	res=res*res%mod;
	if(y%2==1) res=res*x%mod;
	return res;
}
bool big=false;
ll cal(int id,int l,int r){
	if(l+id-1>r) return 1;
	if(a[l+id-1]==1) return 1;
	if(p[id]==1 && min(f1[l+id-1],r+1)-id>4){
		big=true;
		return 0;
	}
	ll res=cal(id+1,l,r);
	if(big){
		return pow(a[l+id-1],res+p[id+1],p[id]);
	}
	if(res>=32){
		big=true;
		return pow(a[l+id-1],res,p[id]);
	}
	ll num=1;
	for(int i=0; i<res ;i++){
		num=num*a[l+id-1];
		if(num>1e9) big=true;
		if(big) num%=p[id];
	}
	return num;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	first1=n+1;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		if(a[i]==1 && first1==n+1) first1=i; 
	}
	p[1]=m;
	for(int i=2; i<=n+1 ;i++){
		p[i]=phi(p[i-1]);
	}
	f1[n+1]=n+1;
	for(int i=n; i>=1 ;i--){
		if(a[i]==1) f1[i]=i;
		else f1[i]=f1[i+1];
	}
	int q;
	cin >> q;
	for(int i=1; i<=q ;i++){
		int l,r;
		cin >> l >> r;
		big=false;
		cout << cal(1,l,r)%m << endl;
	}
}