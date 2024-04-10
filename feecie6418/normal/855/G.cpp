#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> g[100005];
int n,fa[100005],p[100005],size[100005],tsize[100005],q,d[100005];
ll ans=0,sum[100005];
void dfs(int x,int f){
	p[x]=f,fa[x]=x,size[x]=tsize[x]=1,d[x]=d[f]+1,ans+=1ll*(n-2)*(n-1);
	for(int y:g[x]){
		if(y==f)continue;
		dfs(y,x),tsize[x]+=tsize[y],sum[x]+=1ll*tsize[y]*(tsize[y]-1);
	}
	ans-=1ll*(n-tsize[x])*(n-tsize[x]-1)+sum[x];
}
int gf(int x){
	return x==fa[x]?x:fa[x]=gf(fa[x]);
}
void Add(int x,ll dlt){
	//wx
	//1.x 
	ans+=dlt*size[x]*(1ll*(n-size[x])*(n-size[x]-1)-sum[x]-1ll*(n-tsize[x])*(n-tsize[x]-1));
	//2.x
	ans+=dlt*size[x]*(size[x]-1)*(n-size[x])*2;
	//3.x
	ans+=dlt*size[x]*(size[x]-1)*(size[x]-2);
}
void Merge(int x,int y){
	x=gf(x),y=gf(y);
	if(x==y)return ;
	Add(x,-1),Add(y,-1),fa[x]=y,size[y]+=size[x],sum[y]+=sum[x]-1ll*(tsize[x]-1)*tsize[x],Add(y,1);
}
int main(){
	cin>>n;
	for(int i=1,x,y;i<n;i++)cin>>x>>y,g[x].push_back(y),g[y].push_back(x);
	dfs(1,0),cout<<ans<<'\n',cin>>q;
	while(q--){
		int x,y;
		cin>>x>>y,x=gf(x),y=gf(y);
		while(x^y){
			if(d[gf(p[x])]<d[gf(p[y])])swap(x,y);
			Merge(x,p[x]),x=gf(p[x]),y=gf(y);
		}
		cout<<ans<<'\n';
	}
	return 0;
}