#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve(){
	set<int> L,R;
	int n,a,b;
	cin>>n>>a>>b;
	static int vis[233];
	memset(vis,0,sizeof(vis));
	if(a>b+1){
		cout<<-1<<'\n';
		return;
	}
	vis[a]=vis[b]=1;
	L.insert(a),R.insert(b);
	for(int i=1;i<a;++i){
		if(i==b)continue;
		R.insert(i);
		vis[i]=1;
	}
	for(int i=b+1;i<=n;++i){
		if(i==a)continue;
		L.insert(i);
		vis[i]=1;
	}
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		if(L.size()<n/2)L.insert(i);
		else R.insert(i);	
	}
	if(L.size()==n/2){
		for(auto x:L)cout<<x<<' ';
		for(auto x:R)cout<<x<<' ';
		cout<<'\n';	
	}
	else{
		cout<<-1<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}