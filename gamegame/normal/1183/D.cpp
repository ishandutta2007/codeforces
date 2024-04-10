#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n;
map<int,int>m;
multiset<int>m2;
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		int x;cin >> x;
		m[x]++;
	}
	for(auto it:m){
		m2.insert(it.second);
	}
	int ans=0;
	int cur=1e9;
	while(!m2.empty()){
		auto it=m2.end();
		--it;
		ans+=min(cur,*it);
		cur=min(cur,*it) -1;
		cur=max(cur,0);
		m2.erase(it);
	}
	m.clear();m2.clear();
	cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    int t;cin >> t;while(t--) solve();
}