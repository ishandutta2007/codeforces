#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge{
	int x,y,z;
}e[200005];
int n,m,fa[200005],sz[200005],tmp[200005],cnte[200005];
ll ans=0,O=0;
vector<Edge> g[200005];
set<int> s;
int gf(int x){
	return x==fa[x]?x:fa[x]=gf(fa[x]);
}
void Merge(int x,int y){
	x=gf(x),y=gf(y);
	if(x==y)return ;
	fa[x]=y;
	s.erase(x);
	sz[y]+=sz[x];
}
int tf[200005],isin[200005];
int main(){
	scanf("%d%d",&n,&m);
//	n=100000,m=200000;
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
//		x=((rand()<<15)|rand())%n+1;
//		y=((rand()<<15)|rand())%n+1;
//		while(x==y){
//			x=((rand()<<15)|rand())%n+1;
//			y=((rand()<<15)|rand())%n+1;
//		}
//		z=((rand()<<15)|rand());
		e[i]={x,y,z};
		g[x].push_back({x,y,z});
		g[y].push_back({y,x,z});
		O^=z;
	}
	//cout<<"P:"<<O<<'\n';
	for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1,s.insert(i);
	for(int i=1;i<=n;i++){
		for(Edge j:g[i])tmp[gf(j.y)]++;
		tmp[gf(i)]++;
		vector<int> o;
		for(int j:s){
			if(tmp[j]!=sz[j])o.push_back(j);
		}
		for(Edge j:g[i])tmp[gf(j.y)]--;
		tmp[gf(i)]--;
		for(int j:o)Merge(i,j);
	}
	for(int i=1;i<=n;i++){
		for(Edge j:g[i])if(gf(j.y)==gf(i))cnte[gf(i)]++,O=min(O,(ll)j.z);
	}
	for(int i=1;i<=n;i++){
		if(gf(i)!=i)continue;
		if(1ll*sz[i]*(sz[i]-1)/2-cnte[i]/2>sz[i]-1){
			O=0;
		}
	}
	sort(e+1,e+m+1,[](Edge x,Edge y){return x.z<y.z;});
	for(int i=1;i<=n;i++)tf[i]=i;
	for(int i=1;i<=m;i++){
		int x=gf(e[i].x),y=gf(e[i].y);
		if(x!=y){
			fa[x]=y,ans+=e[i].z,isin[i]=1;
			//cout<<e[i].x<<' '<<e[i].y<<'\n';
		}
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int x=gf(e[i].x),y=gf(e[i].y);
		if(isin[i])fa[x]=y;//,cout<<x<<' '<<y<<'\n';
	}
	for(int i=1;i<=m;i++){
		int x=gf(e[i].x),y=gf(e[i].y);
		if(x!=y)O=min(O,(ll)e[i].z);//,cout<<"PP:"<<i<<' '<<e[i].z<<'\n';
	}
	cout<<ans+O;
}