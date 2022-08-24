#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[1000001];
bool vis[1000001];
bool mg[1000001];
vector<int>ans;
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		a[i]=-a[i]+i;
		vis[i]=false;
		mg[i]=false;
	}
	int cur=1;
	vis[cur]=true;
	while(!vis[a[cur]]){
		cur=a[cur];
		if(vis[cur]) exit(0);
		vis[cur]=true;
	}
	ans.reserve(n);
	ans.push_back(cur);
	while(a[cur]!=ans[0]){
		cur=a[cur];
		ans.push_back(cur);
	}
	cout << ans.size() << '\n';
	for(auto cur:ans) cout << cur << ' ';
	cout << '\n';
	ans.clear();
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}