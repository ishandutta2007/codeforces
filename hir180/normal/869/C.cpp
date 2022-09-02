#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef pair<double,int>Q;
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
int a,b,c;
ll modpow(ll x,ll n)
{
	ll res=1;
	while(n>0)
	{
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
ll F[10005],R[10005];
void make(){
	F[0] = 1;
	for(int i=1;i<10005;i++) F[i] = F[i-1]*i%mod;
	for(int i=0;i<10005;i++) R[i] = modpow(F[i],mod-2);
}
ll C(int a,int b){
	return F[a]*R[b]%mod*R[a-b]%mod;
}
ll ret = 0,ret2 = 0,ret3 = 0;
int main(){
	cin>>a>>b>>c; make(); 
	for(int x=0;x<=min(a,b);x++){
		ret += C(a,x) * C(b,x) % mod * F[x] % mod;
		ret %= mod;
	}
	for(int x=0;x<=min(c,b);x++){
		ret2 += C(c,x) * C(b,x) % mod * F[x] % mod;
		ret2 %= mod;
	}
	for(int x=0;x<=min(a,c);x++){
		ret3 += C(a,x) * C(c,x) % mod * F[x] % mod;
		ret3 %= mod;
	}
	cout<<ret*ret2%mod*ret3%mod<<endl;
}