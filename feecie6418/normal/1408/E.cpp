#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=0;
int n,m,a[200005],b[200005],fa[200005];
struct P{int x,y,w;};
vector<P> v;
int gf(int x){
	return fa[x]==x?x:fa[x]=gf(fa[x]);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	for(int i=1;i<=n+m;i++)fa[i]=i;
	for(int i=1,s,x;i<=n;i++){
		cin>>s;
		while(s--)cin>>x,v.push_back({i,x+n,a[i]+b[x]});
	}
	sort(v.begin(),v.end(),[](P i,P j){return i.w>j.w;});
	for(P i:v){
		if(gf(i.x)==gf(i.y))ans+=i.w;
		else fa[gf(i.x)]=gf(i.y);
	}
	cout<<ans;
}