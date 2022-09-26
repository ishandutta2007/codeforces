#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define N 100010
const int mod=1e9+7;
typedef long long ll;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int T,n,m,p[N],siz[N];
vector<int> G[N];
vector<ll> t;
void dfs(int u,int fa){
	siz[u]=1;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
		siz[u]+=siz[v];
		t.push_back(1LL*siz[v]*(n-siz[v]));
	}
}
void Solve(){
	n=read();
	t.clear();
	for(int i=1;i<=n;++i){
		G[i].clear();
	}
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	m=read();
	for(int i=1;i<=m;++i){
		p[i]=read();
	}
	dfs(1,0);
	sort(p+1,p+m+1,greater<int>());
	sort(t.begin(),t.end(),greater<ll>());
	int ans=0;
	if(m<n){
		for(int i=m+1;i<n;++i)p[i]=1;
		for(int i=1;i<n;++i){
			ans=(ans+1LL*p[i]*t[i-1])%mod;
		}
	}
	else{
		int res=m-(n-2),tmp=1;
		for(int i=1;i<=res;++i){
			tmp=1LL*tmp*p[i]%mod;
		}
		ans=1LL*tmp*t[0]%mod;
		for(int i=2;i<n;++i){
			ans=(ans+1LL*p[res+i-1]*t[i-1])%mod;
		}
	}
	printf("%d\n",ans);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}