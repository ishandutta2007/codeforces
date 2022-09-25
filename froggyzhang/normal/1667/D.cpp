#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
vector<int> G[N];
int n,dep[N],pei[N],f[N],vis[N];
vector<pair<int,int> > ans;
int dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	f[u]=fa;
	vector<int> A,B;
	for(auto v:G[u]){
		if(v==fa)continue;
		int t=dfs(v,u);
		if(t==-1)return -1;
		if(dep[t]&1)A.push_back(t);
		else B.push_back(t);
	}
	if(G[u].size()%2==1){
		if(dep[u]&1)A.push_back(u);
		else B.push_back(u);
	}
	while(!A.empty()&&!B.empty()){
		pei[A.back()]=B.back();
		pei[B.back()]=A.back();
		A.pop_back();
		B.pop_back();
	}
	if(u==1){
		if(A.empty()&&B.empty())return 0;
		else return -1;
	}
	if(A.size()==1)return A[0];
	if(B.size()==1)return B[0];
	return -1;
}
void Do(int x,int y){
	int _x=x,_y=y;
	vector<int> L,R;
	while(x^y){
		if(dep[x]>=dep[y]){
			L.push_back(x);
			x=f[x];
		}
		else{
			R.push_back(y);
			y=f[y];
		}
	}
	reverse(R.begin(),R.end());
	L.insert(L.end(),R.begin(),R.end());
	for(auto u:L){
		if(u==_x||u==_y)continue;
		if(G[u].size()%2==1&&!vis[u]){
			Do(u,pei[u]);
			vis[u]=vis[pei[u]]=1;
		}
	}
	if(x^_x&&x^_y&&G[x].size()%2==1&&!vis[x]){
		Do(x,pei[x]);
		vis[x]=vis[pei[x]]=1;
	}
	for(int i=1;i<(int)L.size();i+=2){
		ans.emplace_back(L[i],f[L[i]]);
	}
	for(int i=0;i<(int)L.size();i+=2){
		ans.emplace_back(L[i],f[L[i]]);
	}
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i)G[i].clear(),pei[i]=vis[i]=0;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(dfs(1,0)==-1){
		cout<<"NO\n";;
		return;
	}
	cout<<"YES\n";
	ans.clear();
	for(int i=1;i<=n;++i){
		if(vis[i]||!pei[i])continue;
		Do(i,pei[i]);
		vis[i]=vis[pei[i]]=1;
	}
	assert((int)ans.size()==n-1);
	static int d[N];
	for(int i=1;i<=n;++i){
		d[i]=G[i].size()&1;
	}
	for(auto [x,y]:ans){
		if(d[x]^d[y]){
			assert(false);
		}
		d[x]^=1,d[y]^=1;
	}
	for(auto [x,y]:ans){
		cout<<x<<' '<<y<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}