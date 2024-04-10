#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 998244353 
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,a[200005];
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
ll F[200005],R[200005];
void make(){
	F[0] = 1;
	for(int i=1;i<200005;i++) F[i] = F[i-1]*i%mod;
	R[200004] = modpow(F[200004],mod-2);
	for(int i=200003;i>=0;i--){
		R[i] = R[i+1] * 1LL * (i+1) % mod;
	}
}
ll C(int a,int b){
	return F[a]*R[b]%mod*R[a-b]%mod;
}
ll k;
int main(){
	cin >> n >> k;
	if(k == 1){
		puts("0");
		return 0;
	}
	rep(i,n) cin >> a[i];
	int x = 0, y = 0;
	make();
	rep(i,n){
		int p = a[i], q = a[(i+1)%n];
		if(p == q) x++;
		else y++;
	}
	//cout << k << x << y << endl;
	ll ans = modpow(k,x); 
	ll ans2 = 0;
	for(int i=0;2*i<=y;i++){
		ll add = modpow(k-2,y-2*i); //cout << add << endl;
		add = add*F[y]%mod; //cout << add << endl;
		//cout << i << y << endl;
		add = add*R[i]%mod;
		add = add*R[i]%mod;
		add = add*R[y-i-i]%mod;
		ans2 += add;
	}
	ans2%=mod;
	ans*=ans2;
	ll res = modpow(k,n);
	res -= ans;
	res %= mod;
	res *= (mod+1)/2;
	cout << (res%mod+mod)%mod << endl;
}