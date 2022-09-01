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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
ll dp[55][55][25],t[55][55];
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}

ll n,k;
vector<pair<ll,int> >vec;
ll ans;
void rec(int cur,ll num){
	if(cur == vec.size()) {
		ans += num;
		return;
	}
	ll mul = 1;
	for(int i=0;i<=vec[cur].sc;i++){
		rec(cur+1,num*mul%mod*t[vec[cur].sc][i]%mod);
		mul = mul*vec[cur].fi%mod;
	}
}
int main(){
	for(int i=0;i<55;i++) for(int j=0;j<55;j++) if(i>=j) dp[i][j][0] = modpow(i+1,mod-2);
	for(int x=0;x<24;x++){
		for(int i=0;i<55;i++) for(int k=0;k<55;k++) for(int j=0;j<55;j++) dp[i][j][x+1] += dp[i][k][x]*dp[k][j][x]%mod;
		for(int i=0;i<55;i++) for(int j=0;j<55;j++) dp[i][j][x+1]%=mod;
	}
	for(int i=0;i<55;i++) for(int j=0;j<55;j++) if(i==j) t[i][j]=1;
	cin>>n>>k;
	for(int ii=0;ii<25;ii++){
		if(((k>>ii)&1)){
			ll tt[55][55]={};
			for(int i=0;i<55;i++) for(int k=0;k<55;k++) for(int j=0;j<55;j++) tt[i][j] += dp[i][k][ii]*t[k][j]%mod;
			for(int i=0;i<55;i++) for(int j=0;j<55;j++) t[i][j] = tt[i][j]%mod;
		}
	}
	for(ll i=2;i*i<=n;i++){
		if(n%i != 0) continue;
		int C = 0;
		while(n%i == 0){
			C++;
			n/=i;
		}
		vec.pb(mp(i,C));
	}
	if(n != 1) vec.pb(mp(n,1));
	rec(0,1);
	cout<<(ans%mod+mod)%mod<<endl;
}