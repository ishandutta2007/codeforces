#include<bits/stdc++.h>
using namespace std;
#define N 14
typedef long long ll;
vector<vector<int> > all[10];
vector<vector<int> > H[10];
int n,m,k,G[N][N];
ll ans,C[N][N],fac[N];
void check(vector<pair<int,int> > &V){
	vector<int> p(n/2);
	for(int i=0;i<n/2;++i)p[i]=i;
	bool ok=false;
	do{
		bool qwq=true;
		for(int i=1;i<n/2;++i){
			if(!(G[V[p[i-1]].first][V[p[i]].first]&G[V[p[i-1]].second][V[p[i]].second])&&
			   !(G[V[p[i-1]].first][V[p[i]].second]&G[V[p[i-1]].second][V[p[i]].first])){
			   qwq=false;break;
			}
		}
		if(!G[V[p.back()].first][V[p.back()].second])qwq=false;
		if(qwq){ok=true;break;}
	}while(next_permutation(p.begin(),p.end()));
	if(!ok)return;
	for(int i=1;i<=n/2;++i){
		for(auto v:H[i]){
			vector<int> c(n);
			for(int j=0;j<n/2;++j){
				c[V[j].first-1]=c[V[j].second-1]=v[j];
			}
			all[i].push_back(c);
		}	
	}
}
void dfs1(int u,int mx,vector<int> &V){
	if(u==n/2+1){
		H[mx].push_back(V);
		return;	
	}
	for(int i=1;i<=mx+1;++i){
		auto A=V;
		A.push_back(i);
		dfs1(u+1,max(mx,i),A);	
	}
}
void dfs2(vector<int> &A,vector<pair<int,int> > &V){
	if(A.empty()){
		check(V);
		return;	
	}
	int x=A.back();
	A.pop_back();
	for(int i=0;i<(int)A.size();++i){
		vector<int> B;
		auto T=V;
		T.emplace_back(x,A[i]);
		for(auto z:A){
			if(z^A[i])B.push_back(z);
		}
		dfs2(B,T);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	vector<int> myh;
	dfs1(1,0,myh);
	C[0][0]=fac[0]=1;
	for(int i=1;i<=k;++i){
		C[i][0]=1;
		fac[i]=fac[i-1]*i;
		for(int j=1;j<=i;++j){
			C[i][j]=C[i-1][j-1]+C[i-1][j];
		}
	}
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		G[u][v]=G[v][u]=1;
	}
	vector<int> X;
	vector<pair<int,int> > jb;
	for(int i=n;i>=1;--i){
		X.push_back(i);
	}
	dfs2(X,jb);
	for(int i=1;i<=min(k,n/2);++i){
		sort(all[i].begin(),all[i].end());
		int sz=unique(all[i].begin(),all[i].end())-all[i].begin();
		ans+=C[k][i]*sz*fac[i];	
	}
	cout<<ans<<'\n';
	return 0;
}