#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+9;
ll n,a,b,k;
ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2) return x*pw(x,y-1)%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}
char c[100001];
ll px[100001];
ll x;
int main(){
	cin >> n >> a >> b >> k;
	x=b*pw(a,mod-2)%mod;
	for(int i=0; i<k ;i++) cin >> c[i];
	n++;
	px[0]=1;
	for(int i=1; i<=k ;i++) px[i]=px[i-1]*x%mod;
	ll y=px[k];
	ll sum=0;
	for(int i=0; i<k ;i++){
		int len=n/k+(i<n%k);
		if(len==0) continue;
		ll res;
		if(y==1) res=len;
		else res=(pw(y,len)-1+mod)*pw((y+mod-1)%mod,mod-2)%mod;
		res=res*px[i]%mod;
		if(c[i]=='+') sum=(sum+res)%mod;
		else sum=(sum-res+mod)%mod;
	}
	cout << sum*pw(a,n-1)%mod << endl;
}