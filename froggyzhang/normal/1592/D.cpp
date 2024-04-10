#include<bits/stdc++.h>
using namespace std;
#define N 2020
typedef long long ll;
int n,m;
vector<int> G[N];
vector<pair<int,int> > E;
void dfs(int u,int fa){
	for(auto v:G[u]){
		if(v==fa)continue;
		E.emplace_back(u,v);
		dfs(v,u);	
		E.emplace_back(u,v);
	}
}
int Ask(vector<int> &v){
	cout<<"? "<<v.size()<<' ';
	for(auto x:v)cout<<x<<' ';
	cout<<endl;
	int t;
	cin>>t;
	return t;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;	
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	vector<int> all;
	for(int i=1;i<=n;++i){
		all.push_back(i);
	}
	int mx=Ask(all);
	int l=0,r=E.size(),ans=0;
	while(l<r){
		int mid=(l+r)>>1;
		vector<int> A;
		for(int i=l;i<=mid;++i){
			A.push_back(E[i].first);
			A.push_back(E[i].second);
		}
		sort(A.begin(),A.end());
		A.erase(unique(A.begin(),A.end()),A.end());
		if(Ask(A)==mx){
			ans=r=mid;
		}
		else{
			l=mid+1;
		}
	}
	cout<<"! "<<E[ans].first<<" "<<E[ans].second<<endl;
	return 0;
}