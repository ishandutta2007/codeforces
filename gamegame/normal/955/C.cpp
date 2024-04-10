#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=1e6+1;
ll q[63];
ll s[63];
int n,m;
ll pwr(ll x,ll y){
	ll res=1;
	for(int i=1; i<=y ;i++) res=res*x;
	return res;
}
ll pf(ll x){
	if(x==0) return 0;
	if(x==1) return 1;
	ll ans=1;
	for(int i=2; i<=62 ;i++){
		if(q[i]==0) continue;
		int c=i;
		ll r=s[i];
		ll l=0;
		if(c==2) r=1e9;
		if(c==3) r=1e6;
		while(l<r){
			ll mid=(l+r+1)/2;
			if(pwr(mid,c)<=x) l=mid;
			else r=mid-1;
		}
	//	cout << "!!! " << c << ' ' << r << endl;
		ans+=(l-1)*q[i];
	}
	return ans;
}
ll solve(){
	ll l,r;cin >> l >> r;
	return pf(r)-pf(l-1);
}
bool np[63];
int main(){
	ios::sync_with_stdio(false);
	for(int i=2; i<=62 ;i++) q[i]=1;
	for(int i=2; i<=62 ;i++){
		for(int j=2*i; j<=62 ;j+=i){
			q[j]-=q[i];
		}
	}
	for(int i=2; i<=8 ;i++){
		ll cur=1;
		for(int x=1; x<=62 ;x++){
			cur*=i;
			if(cur>1e18) break;
			s[x]=i;
		}
	}
	s[2]=1e9;
	s[3]=1e6;
	s[4]=4e4;
	s[5]=5e3;
	s[6]=1e3;
	for(int i=7; i<=19 ;i++){
		for(int j=1; j<=1000 ;j++){
			if(pwr(j,i)>1e18) break;
			s[i]=j;
		}
	}
	int t;cin >> t;while(t--) cout << solve() << '\n';
}