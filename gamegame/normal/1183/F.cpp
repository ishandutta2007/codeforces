#include<bits/stdc++.h>
using namespace std;
typedef long double ll;
int n;
vector<int>v,u,w;
void solve(){
	cin >> n;v.clear();u.clear();w.clear();
	for(int i=1; i<=n ;i++){
		int x;cin >> x;v.push_back(x);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	reverse(v.begin(),v.end());
	for(auto cur:v){
		if(v[0]%cur==0) u.push_back(cur);
		else w.push_back(cur);
	}
	int ans=v[0];
	if(v.size()==1){
		cout << v[0] << '\n';
		return;
	}
	int vs=v.size(),v0=v[0],v1=v[1],v2=v[2];
	for(auto cur:w){
		ans=max(ans,v0+cur);
	}
	if(vs==2){
		cout << ans << '\n';
		return;
	}
	for(auto cur:w){
		if(w[0]%cur!=0) ans=max(ans,v0+w[0]+cur);
	}
	if(u.size()>=4 && u[1]==v0/2 && u[2]==v0/3 && u[3]==v0/5) ans=max(ans,u[1]+u[2]+u[3]);
	cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false);
	int t;cin >> t;while(t--) solve();
}