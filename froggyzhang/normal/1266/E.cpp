#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,m,a[N];
int cnt;
ll ans;
map<pair<int,int>,int> mp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		ans+=a[i];
	}
	cin>>m;
	while(m--){
		int x,y,z;
		cin>>x>>y>>z;
		auto t=make_pair(x,y);
		if(mp.count(t)){
			ans-=max(0,a[mp[t]]);
			++a[mp[t]];
			ans+=max(0,a[mp[t]]);
			mp.erase(t);
		}
		if(z){
			mp[t]=z;
			ans-=max(0,a[z]);
			--a[z];
			ans+=max(0,a[z]);	
		}
		cout<<ans<<'\n';
	}
	return 0;
}