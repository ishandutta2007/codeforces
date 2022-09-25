#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
typedef pair<ll,ll> pll;
int K,n,m,ans;
ll a[N],b[N],c[N];
map<ll,int> X,Y;
map<pair<ll,ll>,ll> mp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>K;
	for(int i=1;i<=K;++i){
		cin>>a[i]>>b[i]>>c[i];
		++X[a[i]],++Y[b[i]];
		mp[pll(a[i],b[i])]=c[i];
	}
	n=X.size(),m=Y.size();
	for(auto [p,w]:X){
		if(w!=m){
			cout<<0<<'\n';return 0;
		}
	}
	for(auto [p,w]:Y){
		if(w!=n){
			cout<<0<<'\n';return 0;
		}
	}
	ll gX=c[1],gY=c[1];
	for(int i=2;i<=K;++i){
		if(c[i]!=(__int128)mp[pll(a[1],b[i])]*mp[pll(a[i],b[1])]/c[1]){
			cout<<0<<'\n';
			return 0;
		}
		if(a[1]==a[i])gX=__gcd(gX,c[i]);
		if(b[1]==b[i])gY=__gcd(gY,c[i]);
	}
	auto check=[&](ll x,ll y)->bool{
		return gX%x==0&&gY%y==0;	
	};
	for(ll i=1;i*i<=c[1];++i){
		if(c[1]%i==0){
			ans+=check(i,c[1]/i);
			if(i*i!=c[1])ans+=check(c[1]/i,i);
		}
	}
	cout<<ans<<'\n';
	return 0;
}