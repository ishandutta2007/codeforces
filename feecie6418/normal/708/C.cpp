#include<bits/stdc++.h>
using namespace std;
int n,sz[400005],bel[400005],mn=1e9,ct;
vector<int> g[400005];
void dfs(int x,int f){
	sz[x]=1;
	int mx=0;
	for(int y:g[x]){
		if(y==f)continue;
		dfs(y,x),sz[x]+=sz[y],mx=max(mx,sz[y]);
	}
	mx=max(mx,n-sz[x]);
	if(mx<mn)mn=mx,ct=x;
}
void dfs2(int x,int f,int b){
	bel[x]=b,sz[x]=1;
	for(int y:g[x]){
		if(y==f)continue;
		if(x==ct)dfs2(y,x,y);
		else dfs2(y,x,b);
		sz[x]+=sz[y];
	}
}
int main(){
	cin>>n;
	if(n<=3){
		for(int i=1;i<=n;i++)cout<<"1 ";
		return 0;
	}
	for(int i=1,x,y;i<n;i++)cin>>x>>y,g[x].push_back(y),g[y].push_back(x);
	dfs(1,0);
	if(mn*2==n){
		for(int i=1;i<=n;i++)cout<<"1 ";
		return 0;
	}
	dfs2(ct,0,0);
	multiset<int> s;
	for(int i:g[ct])s.insert(sz[i]);
	for(int i=1;i<=n;i++){
		if(i==ct){
			cout<<"1 ";
			continue;
		}
		int t=bel[i],sum;
		s.erase(s.find(sz[t]));
		sum=n-sz[i]-*--s.end();
		if(sum*2<=n)cout<<"1 ";
		else cout<<"0 ";
		s.insert(sz[t]);
	}
}