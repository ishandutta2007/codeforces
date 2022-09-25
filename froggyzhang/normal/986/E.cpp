#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define M 10000010
const int mod=1e9+7;
typedef long long ll;
typedef pair<int,int> pii;
int n,m,p[M>>2],a[N],emm[M],ans1[N],ans2[N],pn;
bool ntp[M];
vector<int> G[N],cnt[M>>2],num[M>>2];
vector<pii> t[N];
vector<tuple<int,int,int> > q[N];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
void init(int n){
	ntp[1]=1;
	for(int i=2;i<=n;++i){
		if(!ntp[i])p[++pn]=i,emm[i]=pn;
		for(int j=1;j<=pn&&p[j]*i<=n;++j){
			ntp[p[j]*i]=true;
			if(i%p[j]==0)break;
		}
	}
	for(int i=1;i<=pn;++i){
		int j,x;
		num[i].push_back(i);
		for(j=1,x=p[i];;++j,x*=p[i]){
			num[i].push_back(x);
			if(x>n/p[i])break;
		}
		cnt[i].resize(j+1);
	}
}
vector<pii> Split(int x){
	vector<pii> fac;
	for(int i=1;p[i]*p[i]<=x;++i){
		if(x%p[i]==0){
			int jb=0;
			while(x%p[i]==0)x/=p[i],++jb;
			fac.emplace_back(i,jb);
		}
	}	
	if(x>1){
		fac.emplace_back(emm[x],1);
	}
	return fac;
}
int top[N],son[N],siz[N],dep[N],f[N];
void dfs1(int u){
	siz[u]=1;
	for(auto v:G[u]){
		if(v==f[u])continue;
		f[v]=u;
		dep[v]=dep[u]+1;
		dfs1(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]){
			son[u]=v;
		}
	}
}
void dfs2(int u,int topf){
	top[u]=topf;
	if(!son[u])return;
	dfs2(son[u],topf);
	for(auto v:G[u]){
		if(v==f[u]||v==son[u])continue;
		dfs2(v,v);
	}
}
inline int LCA(int u,int v){
	while(top[u]^top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		u=f[top[u]];
	}
	if(dep[u]>dep[v])swap(u,v);
	return u;
}
void dfs3(int u){
	for(auto [x,z]:t[u]){
		++cnt[x][z];	
	}
	for(auto v:G[u]){
		if(v==f[u])continue;
		dfs3(v);	
	}
	for(auto [x,z,id]:q[u]){
		for(int i=1;i<(int)cnt[x].size();++i){
			if(z>0)ans1[id]=1LL*ans1[id]*qpow(num[x][min(i,z)],cnt[x][i])%mod;
			else ans2[id]=1LL*ans2[id]*qpow(num[x][min(i,-z)],cnt[x][i])%mod;
		}
	}
	for(auto [x,z]:t[u]){
		--cnt[x][z];	
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init(10000000);
	cin>>n;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;++i){
		cin>>a[i];
		t[i]=Split(a[i]);
	}
	dfs1(1);
	dfs2(1,1);
	cin>>m;
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		int lca=LCA(u,v);
		auto V=Split(w);
		for(auto [x,z]:V){
			q[u].emplace_back(x,z,i);
			q[v].emplace_back(x,z,i);
			q[lca].emplace_back(x,-z,i);
			q[f[lca]].emplace_back(x,-z,i);
		}
		ans1[i]=ans2[i]=1;
	}
	dfs3(1);
	for(int i=1;i<=m;++i){
		cout<<1LL*ans1[i]*qpow(ans2[i],mod-2)%mod<<'\n';
	}
	return 0;
}