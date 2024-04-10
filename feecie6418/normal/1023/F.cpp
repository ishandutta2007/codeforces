#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353,inf=0x3f3f3f3f;
int fa[500005],n,m1,m2,v[500005],d[500005],f[500005],is[500005],u[500005];
ll sum=0;
struct E{
	int x,y,z;
}e[500005];
vector<pr> g[500005];
int gf(int x){
	return x==fa[x]?x:fa[x]=gf(fa[x]);
}
void dfs(int x,int fa_){
	d[x]=d[fa_]+1,fa[x]=x,f[x]=fa_;
	for(pr i:g[x]){
		int y=i.first;
		if(y^f[x])is[y]=i.second,dfs(y,x);
	}
}
int main(){
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=n;i++)v[i]=inf,fa[i]=i;
	for(int i=1,x,y;i<=m1;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back({y,1}),g[y].push_back({x,1}),fa[gf(x)]=gf(y);
	}
	for(int i=1,x,y,z;i<=m2;i++){
		scanf("%d%d%d",&x,&y,&z),e[i]={x,y,z};
		if(gf(x)==gf(y))continue;
		g[x].push_back({y,0}),g[y].push_back({x,0}),fa[gf(x)]=gf(y),u[i]=1;
	}
	dfs(1,0);
	for(int i=1;i<=m2;i++){
		if(u[i])continue;
		int x=gf(e[i].x),y=gf(e[i].y),z=e[i].z;
		while(x!=y){
			if(d[x]<d[y])swap(x,y);
			v[x]=z,x=fa[x]=gf(f[x]);
		}
	}
	for(int i=2;i<=n;i++){
		if(!is[i])continue;
		if(v[i]>1e9)return puts("-1"),0;
		sum+=v[i];
	}
	cout<<sum;
}