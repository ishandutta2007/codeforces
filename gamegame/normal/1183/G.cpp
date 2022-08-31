#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n;
map<int,pair<int,int> >m;
vector<pair<int,int> >bin;
priority_queue<int>maxi;
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		int x,y;cin >> x >> y;
		m[x].fi++;m[x].se+=y;
	}
	for(auto it:m){
		bin.push_back(it.se);
	}
	sort(bin.begin(),bin.end());
	int ans=0,ans2=0;
	int cur=1e9;
	while(!bin.empty() || !maxi.empty()){
		while(!bin.empty() && bin.back().fi>=cur){
			maxi.push(bin.back().se);bin.pop_back();
		}
		if(maxi.empty()){
			cur=bin.back().fi;
			maxi.push(bin.back().se);
			bin.pop_back();
		}
		while(!bin.empty() && bin.back().fi>=cur){
			maxi.push(bin.back().se);bin.pop_back();
		}
		ans+=cur;
		ans2+=min(cur,maxi.top());
		maxi.pop();
		cur=max(0,cur-1);
	}
	m.clear();
	cout << ans << ' ' << ans2 << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    int t;cin >> t;while(t--) solve();
}