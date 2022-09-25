#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
int n,a[N],p[N];
vector<int> G[N];
struct Union_Set{
public:
	int siz[N],f[N];
	inline int getf(int x){
		return f[x]==x?x:f[x]=getf(f[x]);
	}
	void init(int n){
		for(int i=1;i<=n;++i){
			siz[i]=1,f[i]=i;		
		}
	}
	void Merge(int x,int y){
		int fx=getf(x),fy=getf(y);
		if(fx==fy)return;
		f[fy]=fx,siz[fx]+=siz[fy];
	}
}S;
ll ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		p[i]=i;
	}
	sort(p+1,p+n+1,[&](int i,int j){return make_pair(a[i],i)<make_pair(a[j],j);});
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	S.init(n);
	for(int i=1;i<=n;++i){
		int u=p[i];
		int now=1;
		for(auto v:G[u]){
			if(make_pair(a[v],v)>make_pair(a[u],u))continue;
			ans+=1LL*now*S.siz[S.getf(v)]*a[u];
			S.Merge(u,v);
			now=S.siz[S.getf(u)];	
		}
	}
	S.init(n);
	for(int i=n;i>=1;--i){
		int u=p[i];
		int now=1;
		for(auto v:G[u]){
			if(make_pair(a[v],v)<make_pair(a[u],u))continue;
			ans-=1LL*now*S.siz[S.getf(v)]*a[u];
			S.Merge(u,v);
			now=S.siz[S.getf(u)];
		}
	}
	cout<<ans<<'\n';
	return 0;
}