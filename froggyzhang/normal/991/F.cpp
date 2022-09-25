#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
map<ll,string> mp;
string ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	ans=to_string(n);
	for(ll i=2;i*i<=n;++i){
		for(ll x=i,j=1;x<=n;x*=i,++j){
			string jb=to_string(i)+"^"+to_string(j);
			if(!mp.count(x)||mp[x].length()>jb.length())mp[x]=jb;
		}
	}
	for(auto &[num,s]:mp){
		auto g=to_string(num);
		if(g.length()<s.length())s=g;	
	}
	for(auto [x,s]:mp){
		ll y=n/x,z=n%x;
		string t=s;
		if(y>1){
			t+="*";
			if(mp.count(y))t+=mp[y];
			else t+=to_string(y);
		}
		if(z>0){
			t+="+";
			if(mp.count(z))t+=mp[z];
			else t+=to_string(z);	
		}
		if(t.length()<ans.length())ans=t;
	}
	cout<<ans<<'\n';
	return 0;
}