#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=1e6+1;
int n,m;
ll f[N],inf[N];
const ll mod=998244353;
ll pw(ll x,ll y ){
	if(y==0) return 1;
	if(y%2) return x*pw(x,y-1)%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	f[0]=1;
	for(int i=1; i<=m ;i++){
		f[i]=f[i-1]*i%mod;
	}
	inf[m]=pw(f[m],mod-2);
	for(int i=m; i>=1 ;i--){
		inf[i-1]=inf[i]*i%mod;
	}
	ll ways=f[m]*inf[n-1]%mod*inf[m-n+1]%mod;
	ll m1=ways*(n-2);
	for(int i=1; i<=n-3 ;i++) m1=m1*2%mod;
	cout << (m1)%mod << endl;
}