#include<bits/stdc++.h>
using namespace std;
#define N 300010
typedef long long ll;
typedef pair<int,int> pii;
int n,m,zz,mat[N],a[N],del[N],exi[N];
map<int,int> pos[666];
vector<int> G[N];
vector<pii> E;
inline void adde(int u,int v){
	E.emplace_back(u,v);
}
bitset<N> vis;
mt19937 rnd(time(0));
int dfs(int u){
	shuffle(G[u].begin(),G[u].end(),rnd);
	vis[u]=1;
	for(auto v:G[u]){
		if(vis[mat[v]])continue;
		int t=mat[v];
		mat[u]=v,mat[t]=0,mat[v]=u;
		if(!t||dfs(t))return 1;
		mat[u]=0,mat[t]=v,mat[v]=t;
	}
	return 0;
}
int Solve(){
	int jb=3;
	int ans=0;
	while(jb--){
		for(int i=1;i<=m;++i){
			if(!mat[i]){
				vis.reset();
				ans+=dfs(i);
			}
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	m=600;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1,j=0;i<=n;++i){
		if(a[i]){
			exi[a[i]]=1;
			if(j+1==i){
				if(a[i]==a[j]){
					del[a[i]]=1;
				}	
			}
			else{
				zz+=(i-j)/2-1;
				if((i-j)&1){
					++m;
					adde(m,a[i]),adde(m,m+1),adde(m+1,a[j]);
					pos[a[i]][m]=i-1,pos[a[j]][m+1]=j+1;
					++m;
				}
				else{
					++m;
					pos[a[i]][m]=i-1,pos[a[j]][m]=j+1;
					adde(m,a[i]),adde(m,a[j]);
				}
			}
			j=i;
		}
	}
	del[0]=1;
	for(auto [u,v]:E){
		if(!del[u]&&!del[v]){
			G[u].push_back(v);
			G[v].push_back(u);
		}
	}
	Solve();
	for(int i=1;i<=600;++i){
		if(mat[i]&&pos[i][mat[i]]){
			a[pos[i][mat[i]]]=i;
		}
	}
	int kk=1;
	for(int i=1;i<=n;++i){
		if(!a[i]){
			while(exi[kk])++kk;
			a[i]=kk;
			if(!a[i+1])a[i+1]=kk,++i;
			++kk;	
		}
	}
	for(int i=1;i<=n;++i){
		cout<<a[i]<<' ';
	}
	cout<<'\n';
	//cout<<Solve()+zz<<'\n';
	return 0;
}