#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,m,p[N];
ll d[N];
vector<tuple<int,int,ll> > ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1,u,v,w;i<=m;++i){
		cin>>u>>v>>w;
		d[u]+=w,d[v]-=w;
	}
	for(int i=1;i<=n;++i){
		p[i]=i;
	}
	sort(p+1,p+n+1,[&](int i,int j){return d[i]>d[j];});
	int i=1,j=n;
	while(i<j){
		if(!d[p[i]]){++i;continue;}
		if(!d[p[j]]){--j;continue;}
		ll z=min(d[p[i]],-d[p[j]]);
		ans.emplace_back(p[i],p[j],z);
		d[p[i]]-=z,d[p[j]]+=z;
	}
	cout<<ans.size()<<'\n';
	for(auto [x,y,z]:ans){
		cout<<x<<" "<<y<<" "<<z<<'\n';
	}
	return 0;
}