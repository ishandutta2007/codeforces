#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,d[N];
vector<int> G[N];
set<int> S;
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i)G[i].clear();
	S.clear();
	for(int i=1;i<=n;++i){
		int k,x;
		cin>>k;
		d[i]=k;
		while(k--){
			cin>>x;
			G[x].push_back(i);
		}
	}
	for(int i=1;i<=n;++i)if(!d[i])S.insert(i);
	int ans=1,u=1;
	while(!S.empty()){
		if(u>*S.rbegin()){u=1;++ans;}
		u=*S.lower_bound(u);
		S.erase(u);
		for(auto v:G[u]){
			if(!--d[v])S.insert(v);	
		}
	}
	for(int i=1;i<=n;++i){
		if(d[i]){
			cout<<-1<<'\n';return;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}