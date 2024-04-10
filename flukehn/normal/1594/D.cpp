#include<bits/stdc++.h>
using namespace std;
const int N=2e5+11,M=5e5+11;
int n,m;
int f[N],sz[N];
int fa(int i){return f[i]==i?i:f[i]=fa(f[i]);}
vector<int> g[N];
int c[N];
int tot1,tot2;
int dfs(int x){
	tot1+=sz[x];
	if(c[x]==1)tot2+=sz[x];
	for(int y:g[x]){
		if(!c[y]){
			c[y]=-c[x];
			if(!dfs(y))return 0;
		}else{
			if(c[y]==c[x])return 0;
		}
	}
	return 1;
}
int work(){
	for(int i=1;i<=n;++i)f[i]=i,sz[i]=1;
	vector<pair<int,int> >E;
	for(int i=1;i<=m;++i){
		int x,y;
		string s;
		cin>>x>>y>>s;
		if(s=="crewmate"){
			x=fa(x),y=fa(y);
			if(x!=y)f[x]=y,sz[y]+=sz[x];
		}else{
			E.push_back(make_pair(x,y));
		}
	}
	for(int i=1;i<=n;++i)g[i].clear();
	for(auto e:E){
		int x=fa(e.first),y=fa(e.second);
		if(x==y) return -1;
		else{
			g[x].push_back(y);
			g[y].push_back(x);
		}
	}
	for(int i=1;i<=n;++i)c[i]=0;
	int ans=0;
	for(int i=1;i<=n;++i)if(i==fa(i) && !c[i]){
		c[i]=1;
		tot1=tot2=0;
		if(!dfs(i)) {
			//cerr<<i<<" "<<sz[i]<<"\n";
			return -1;
		}
		ans+=max(tot2,tot1-tot2);
	}
	return ans;
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;cin>>T;
	while(cin>>n>>m){
		cout<<work()<<"\n";
	}
}