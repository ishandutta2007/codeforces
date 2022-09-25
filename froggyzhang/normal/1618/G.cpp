#include<bits/stdc++.h>
using namespace std;
#define N 400010
typedef long long ll;
typedef pair<int,int> pii;
int n,m,Q,a[N],c[N],p[N];
ll ans[N],s[N];
vector<pii> q;
class Union_Set{
public:
	int f[N],siz[N];
	void init(int n){
		for(int i=1;i<=n;++i){
			f[i]=i;
		}
	}
	inline int getf(int x){
		return f[x]==x?x:f[x]=getf(f[x]);
	}
}S;
pii ge[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>Q;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=m;++i){
		cin>>a[n+i];	
	}
	for(int i=1;i<=n+m;++i){
		p[i]=i;
	}
	sort(p+1,p+n+m+1,[&](int i,int j){return a[i]<a[j];});
	for(int i=1;i<=n+m;++i){
		c[i]=a[p[i]];
	}
	for(int i=1;i<n+m;++i){
		ge[i]=pii(c[i+1]-c[i],i);
	}
	sort(ge+1,ge+n+m);
	for(int i=1;i<=Q;++i){
		int k;
		cin>>k;
		q.emplace_back(k,i);
	}
	ll now=0;
	sort(q.begin(),q.end());
	int i=1;
	S.init(n+m);
	for(int i=1;i<=n+m;++i){
		if(p[i]<=n)S.siz[i]=1,now+=c[i];
		s[i]=s[i-1]+c[i];
	}
	for(auto [k,id]:q){
		while(i<n+m&&ge[i].first<=k){
			int u=ge[i].second,v=S.getf(ge[i].second+1);
			S.f[u]=v;
			now-=s[u]-s[u-S.siz[u]];
			now-=s[v]-s[v-S.siz[v]];
			S.siz[v]+=S.siz[u];
			now+=s[v]-s[v-S.siz[v]];
			++i;
		}
		ans[id]=now;
	}
	for(int i=1;i<=Q;++i){
		cout<<ans[i]<<'\n';
	}
	return 0;
}