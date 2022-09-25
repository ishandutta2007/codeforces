#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,m,t[N],p[N],lim[N];
set<pair<int,int> > q;
set<int> s[N];
vector<tuple<int,int,int> > ans;
int sum;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		p[i]=i;
		int k;
		cin>>k;
		t[i]=k;
		static int vis[50];
		for(int i=1;i<=m;++i)vis[i]=0;
		while(k--){
			int x;
			cin>>x;
			s[i].insert(x);
		}
		sum+=t[i];
	}
	sort(p+1,p+n+1,[&](int i,int j){return t[i]>t[j];});
	for(int i=1;i<=n;++i){
		lim[p[i]]=sum/n+(i<=(sum%n));
	}
	for(int i=1;i<=n;++i){
		if(lim[i]^t[i])q.insert(make_pair(t[i],i));
	}
	while(!q.empty()){
		int u=q.rbegin()->second;
		int v=q.begin()->second;
		q.erase(--q.end());
		q.erase(q.begin());
		vector<int> D;
		for(auto x:s[u]){
			if(t[u]==lim[u]||t[v]==lim[v])break;
			if(!s[v].count(x)){
				D.push_back(x);
				--t[u],++t[v];
			}
		}
		for(auto x:D){
			ans.emplace_back(u,v,x);
			s[u].erase(x);
			s[v].insert(x);
		}
		if(t[u]^lim[u])q.insert(make_pair(t[u],u));
		if(t[v]^lim[v])q.insert(make_pair(t[v],v));
	}
	cout<<ans.size()<<'\n';
	for(auto [x,y,z]:ans){
		cout<<x<<" "<<y<<" "<<z<<'\n';
	}
	return 0;
}