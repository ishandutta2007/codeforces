#include<bits/stdc++.h>
using namespace std;
#define N 233
typedef long long ll;
typedef pair<int,int> pii;
int ans[N],n;
pii E[N];
vector<pii> G[N];
bool ban[N];
int Ask(int x,int y){
	cout<<"? "<<x<<" "<<y<<endl;
	cin>>x;
	return x;
}
void Find(int u,int fa,pii &t){
	for(auto [v,id]:G[u]){
		if(ban[id]||v==fa)continue;
		t=max(t,pii(ans[id],id));
		Find(v,u,t);
	}
}
__int128 b[N];
__int128 Solve(vector<pair<__int128,int> > A){
	static int rk[N][N],p[N][N];
	static bool ok[N];
	int m=A.size();
	for(int i=0;i<m;++i)rk[0][i]=p[0][i]=i;
	memset(ok,false,sizeof(ok));
	for(int i=1;i<=n;++i){
		int c0=0,c1=0;
		for(int j=0;j<m;++j)c1+=!(A[j].first>>i&1);
		for(int j=0;j<m;++j){
			int u=p[i-1][j];
			if(A[u].first>>i&1)rk[i][u]=c1++;
			else rk[i][u]=c0++;
		}
		for(int j=0;j<m;++j){
			p[i][rk[i][j]]=j;
		}
	}
	__int128 zz=0;
	auto check=[&](int o)->bool{
		for(int j=0;j<m;++j){
			if(!ok[j]&&A[j].first>>o&1)return false;
		}
		static bool _ok[N];
		memcpy(_ok,ok,sizeof(ok));
		for(int i=o-1;i>=1;--i){
			int cnt=0;
			for(int j=0;j<m;++j){
				if(!_ok[j]&&A[j].first>>i&1){
					++cnt;
				}
			}
			if(cnt>=2)return false;
			for(int j=m-1;j>=0;--j){
				int u=p[i][j];
				if(!_ok[u]){
					if(!(A[u].first>>i&1))_ok[u]=1;
					break;
				}
			}
		}
		for(int i=0;i<m;++i){
			if(!_ok[i])return false;
		}
		return true;
	};
	for(int i=n;i>=1;--i){
		if(!check(i)){
			zz|=(__int128)1<<i;
			for(int j=m-1;j>=0;--j){
				int u=p[i][j];
				if(!ok[u]){
					if(!(A[u].first>>i&1)){
						ok[u]=1;
						ans[A[u].second]=i;
					}
					break;
				}
			}
		}
	}
	return zz;
}
void dfs(int u,int fa){
	vector<pair<__int128,int> > A;
	for(auto [v,id]:G[u]){
		if(v==fa)continue;
		dfs(v,u);
		A.emplace_back(b[v],id);
	}
	b[u]=Solve(A);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].emplace_back(v,i);
		G[v].emplace_back(u,i);
		E[i]=pii(u,v);
	}
	dfs(1,0);
	int now=1;
	while(true){
		pii t=pii(-1,-1);
		Find(now,0,t);
		if(~t.first){
			int id=t.second;
			now=Ask(E[id].first,E[id].second);
			ban[id]=1;
		}
		else{
			cout<<"! "<<now<<endl;
			return 0;
		}
	}
	return 0;
}