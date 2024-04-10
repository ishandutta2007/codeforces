#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,L[N],R[N],num,a[N];
vector<int> G[N],ans;
struct Union_Set{
	int f[N];
public:
	void init(int n){
		for(int i=1;i<=n;++i){
			f[i]=i;
		}	
	}
	inline int getf(int x){
		return f[x]==x?x:f[x]=getf(f[x]);	
	}
}S;
int m;
struct Link{
	int x,y,w,id;	
}E[N];
void dfs(int u,int fa){
	L[u]=n+1;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
		L[u]=min(L[u],L[v]);
		R[u]=max(R[u],R[v]);
	}
	if(u^1&&G[u].size()==1)L[u]=R[u]=++num;
	E[++m]={L[u],R[u]+1,a[u],u};
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	S.init(num+1);
	sort(E+1,E+m+1,[&](Link a,Link b){return a.w<b.w;});
	ll sum=0;
	for(int i=1,j=1;i<=n;++i){
		if(S.getf(E[i].x)^S.getf(E[i].y)){
			ans.push_back(E[i].id);
		}
		if(E[i].w^E[i+1].w){
			while(j<=i){
				int fx=S.getf(E[j].x),fy=S.getf(E[j].y);
				if(fx^fy)S.f[fy]=fx,sum+=E[j].w;
				++j;	
			}
		}	
	}
	sort(ans.begin(),ans.end());
	cout<<sum<<' '<<ans.size()<<'\n';
	for(auto x:ans){
		cout<<x<<' ';
	}
	return 0;
}