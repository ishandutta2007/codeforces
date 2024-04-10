#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=0;
int n,m,fa[200005],cyc[200005];
struct P{int x,y,w;};
vector<P> v;
int gf(int x){
	return fa[x]==x?x:fa[x]=gf(fa[x]);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1,x,y,z;i<=m;i++)cin>>x>>y>>z,v.push_back({x,y,z});
	sort(v.begin(),v.end(),[](P i,P j){return i.w>j.w;});
	for(P i:v){
		if(gf(i.x)==gf(i.y)){if(!cyc[gf(i.x)])cyc[gf(i.x)]=1,ans+=i.w;}
		else if(!(cyc[gf(i.x)]&&cyc[gf(i.y)]))cyc[gf(i.y)]|=cyc[gf(i.x)],fa[gf(i.x)]=gf(i.y),ans+=i.w;
	}
	cout<<ans;
}