#include<bits/stdc++.h>
using namespace std;
#define N 1005
typedef long long ll;
const int inf=1e9+1;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,n,m,a[N],b[N],p[N];
vector<pair<int,int> > E,G[N];
vector<int> V;
int st[N],top,ins[N],ok;
void dfs(int u,int fa,int now){
	if(ok)return;
	ins[u]=1;
	st[++top]=u;
	for(auto [v,id]:G[u]){
		if(fa==id)continue;
		if(ok)break;
		if(now>a[v]){
			if(ins[v]){
				for(int i=1;i<=top;++i){
					V.push_back(st[i]);
				}
				ok=1;
				break;
			}
			else dfs(v,id,min(inf,now+b[v]));
		}
	}
	ins[u]=0;
	--top;
}
bool check(int now){
	for(int i=1;i<=n;++i)p[i]=0;
	p[1]=1;
	int res=n-1;
	while(res){
		top=ok=0;
		V.clear();
		for(int i=1;i<=n;++i)G[i].clear();
		for(int i=0;i<(int)E.size();++i){
			int u=p[E[i].first]?1:E[i].first,v=p[E[i].second]?1:E[i].second;
			if(u^v){
				G[u].emplace_back(v,i);
				G[v].emplace_back(u,i);
			}
		}
		dfs(1,-1,now);
		if(!ok)return false;
		res-=V.size()-1;
		for(auto u:V)p[u]=1,now=min(inf,now+b[u]);
	}
	return true;
}
void Solve(){
	n=read(),m=read();
	E.clear();
	for(int i=2;i<=n;++i)a[i]=read();
	for(int i=2;i<=n;++i)b[i]=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		E.emplace_back(u,v);
	}
	int l=1,r=inf+1,ans=0;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=r=mid;
		}
		else{
			l=mid+1;
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