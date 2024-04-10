#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
int p[200001];
int h,n;
vector<pair<int,int> >v;
void solve(){
	cin >> h >> n;
	for(int i=n; i>=1 ;i--){
		cin >> p[i];
	}
	v.clear();
	v.push_back({0,0});
	int prv=0;
	for(int i=1; i<=n ;i++){
		if(p[i]!=prv+1) v.push_back({p[i]-prv-1,0});
		if(v.back().se==1) v.back().fi++;
		else v.push_back({1,1});
		prv=p[i];
	}
	int ans=0;
	reverse(v.begin(),v.end());
	v[0].fi++;
	for(int i=0; i<v.size() ;i++){
		if(v[i].se==0) continue;
		if(i==(int)v.size()-2) break;
		if(v[i].fi%2==1) ans++;
	}
	ans=min(ans,h-n);
	cout << ans << '\n';
}
int main(){
	int t;cin >> t;
	while(t--) solve();
}