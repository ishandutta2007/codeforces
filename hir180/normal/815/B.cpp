#include <bits/stdc++.h>
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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define mod 1000000007
int n;
ll a[200005];
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
ll F[300005],R[300005];
void make(){
	F[0] = 1;
	for(int i=1;i<300005;i++) F[i] = F[i-1]*i%mod;
	for(int i=0;i<300005;i++) R[i] = modpow(F[i],mod-2);
}
ll C(int a,int b){
	return F[a]*R[b]%mod*R[a-b]%mod;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	int m = (n-1)/4; m *= 4; make();
	vector<ll>hoge;
	if(m > 0){
		for(int i=1;i<=4;i++){
			if(i+m > n) break;
			int x = m/2,y = 0;
			ll v = 0;
			for(int j=i;j<=i+m;j+=2){
				v = (v+C(x,y)*a[j]%mod)%mod;
				y++;
			}
			hoge.pb(v);
		}
	}
	else{
		for(int i=1;i<=n;i++) hoge.pb(a[i]);
	}int C = 0;
	while(hoge.size() > 1){
		vector<ll>hoge2;
		for(int i=1;i<hoge.size();i++){
			if(C%2 == 0){
				hoge2.pb( (hoge[i-1]+hoge[i])%mod );
			}
			else{
				hoge2.pb( (hoge[i-1]+mod-hoge[i])%mod );
			}C++;
		}
		hoge = hoge2;
	}
	cout << hoge[0] << endl;
}