#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pr;
int T,n;
ll a[200005],b[200005],s[200005],ans[200005];
void Exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){
		x=1,y=0;
		return ;
	}
	ll xx,yy;
	Exgcd(b,a%b,xx,yy);
	x=yy,y=xx-(a/b)*yy;
}
map<ll,vector<pr>> mp;
int main(){
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),s[i]=s[i-1]+a[i];
	ll g=__gcd(s[n],(ll)T);
	for(int i=n;i;i--)a[i]=s[i]-a[1];
	ll tx,ty;
	Exgcd(s[n],T,tx,ty);
	for(int i=1;i<=n;i++){
		ll t=a[i]%g;
		__int128 u=tx,v=ty;
		u*=(a[i]-t)/g,v*=(a[i]-t)/g;
		u=(u%(T/g)+(T/g))%(T/g);
		mp[t].push_back(pr(u,n-i));
	}
	for(auto i:mp){
		auto v=i.second;
		sort(v.begin(),v.end());
		for(int j=0;j<v.size();j++){
			if(j+1<v.size())ans[n-v[j].second]=v[j+1].first-v[j].first;
			else ans[n-v[j].second]=v[0].first-v[j].first+(T/g);
		}
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
}