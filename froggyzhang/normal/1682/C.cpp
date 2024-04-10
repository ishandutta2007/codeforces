#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
map<int,int> mp;
void Solve(){
	cin>>n;
	mp.clear();
	for(int i=1,x;i<=n;++i){
		cin>>x;
		++mp[x];
	}
	int ans=0;
	for(auto [x,w]:mp)ans+=min(w,2);
	cout<<(ans+1)/2<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}