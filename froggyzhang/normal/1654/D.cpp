#include<bits/stdc++.h>
using namespace std;
#define N 200020
const int mod=998244353;
typedef long long ll;
int inv[N],ans[N];
bool ntp[N];
vector<int> fac[N];
struct Data{
	int to,x,y;
};
vector<Data> G[N];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
inline void Plus(int &x,int y){
	(x+=y)>=mod?x-=mod:233;
}
void init(int n){
	inv[1]=1;
	for(int i=2;i<=n;++i){
		inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;
	}
	for(int i=2;i<=n;++i){
		if(!ntp[i]){
			for(int j=i;j<=n;j+=i){
				int zz=j;while(zz%i==0)zz/=i,fac[j].push_back(i);
			}
			for(int j=i+i;j<=n;j+=i)ntp[j]=1;
		}
	}
}
int n,a[N],b[N];
void dfs1(int u,int fa){
	for(auto [v,x,y]:G[u]){
		if(v==fa)continue;
		for(auto c:fac[x])--a[c];for(auto c:fac[y])++a[c];
		for(auto c:fac[x])b[c]=min(b[c],a[c]);for(auto c:fac[y])b[c]=min(b[c],a[c]);
		dfs1(v,u);
		for(auto c:fac[x])++a[c];for(auto c:fac[y])--a[c];
	}
}
void dfs2(int u,int fa){
	for(auto [v,x,y]:G[u]){
		if(v==fa)continue;
		ans[v]=ans[u];
		for(auto c:fac[x])ans[v]=1LL*ans[v]*inv[c]%mod;for(auto c:fac[y])ans[v]=1LL*ans[v]*c%mod;
		dfs2(v,u);
	}
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		G[i].clear();
		a[i]=b[i]=0;
	}
	for(int i=1;i<n;++i){
		int u,v,x,y;
		cin>>u>>v>>x>>y;
		G[u].push_back({v,x,y});
		G[v].push_back({u,y,x});
	}
	dfs1(1,0);
	ans[1]=1;
	for(int i=1;i<=n;++i){
		if(b[i]<0)ans[1]=1LL*ans[1]*qpow(i,-b[i])%mod;
	}
	dfs2(1,0);
	int tot=0;
	for(int i=1;i<=n;++i){
		Plus(tot,ans[i]);
	}
	cout<<tot<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init(200000);
	int T;
	cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}