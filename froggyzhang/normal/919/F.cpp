#include<bits/stdc++.h>
using namespace std;
#define N 333333
typedef long long ll;
typedef array<int,8> a8;
int n,type[N],d[N],vis[N];
map<pair<a8,a8>,int> id;
pair<a8,a8> c[N];
vector<a8> V;
void dfs(int u,a8 p,int lim){
	if(u==8){
		V.push_back(p);
		return;
	}
	for(int i=lim;i<5;++i){
		a8 t=p;
		t[u]=i;
		dfs(u+1,t,i);	
	}
}
vector<int> G[N];
queue<int> q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	array<int,8> emp={};
	dfs(0,emp,0);
	for(auto x:V){
		for(auto y:V){
			id[make_pair(x,y)]=++n;
			c[n]=make_pair(x,y);	
		}
	}
	for(int i=1;i<=n;++i){
		auto [x,y]=c[i];
		if(x==emp){type[i]=1;q.push(i);continue;}
		if(y==emp){q.push(i);continue;}
		static set<int> to;
		to.clear();
		for(int j=0;j<8;++j){
			for(int k=0;k<8;++k){
				if(!x[j]||!y[k])continue;
				a8 nx=x;
				nx[j]=(x[j]+y[k])%5;
				sort(nx.begin(),nx.end());
				to.insert(id[make_pair(y,nx)]);
			}
		}
		for(auto v:to){
			G[v].push_back(i);	
		}
		d[i]=to.size();
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto v:G[u]){
			type[v]|=!type[u];
			if(!--d[v]||type[v])q.push(v);
		}	
	}
	int T;
	cin>>T;
	while(T--){
		int fir;
		static a8 A,B;
		cin>>fir;
		for(int i=0;i<8;++i)cin>>A[i];
		for(int i=0;i<8;++i)cin>>B[i];
		sort(A.begin(),A.end());
		sort(B.begin(),B.end());
		int ans=0;
		if(!fir){
			int u=id[make_pair(A,B)];
			ans=type[u]?1:(vis[u]?0:-1);
		}
		else{
			int u=id[make_pair(B,A)];
			ans=type[u]?0:(vis[u]?1:-1);
		}
		cout<<(~ans?(ans?"Alice\n":"Bob\n"):"Deal\n");
	}
	return 0;
}