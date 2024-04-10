#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N=250001;
int n;
vector<int>adj[N];
int par[N][18];
int ptr=0;
int st[N],en[N];
void dfs(int id,int p){
	st[id]=++ptr;
	for(auto cur:adj[id]){
		if(cur==p) continue;
		par[cur][0]=id;
		for(int i=1; i<18 ;i++){
			par[cur][i]=par[par[cur][i-1]][i-1];
		}
		dfs(cur,id);
	}
	en[id]=ptr;
}
/*int bit[N];
void upd(int id,int v){
	for(int i=id; i<=n ;i+=i&-i) bit[i]+=v;
}
int qry(int id){
	int res=0;
	for(int i=id; i>=1 ;i+=i&-i) res+=bit[i]
	return res;
}*/
int dsu[N];
vector<int>aw,ax,ay,az;
int find(int u){
	if(dsu[u]!=u) dsu[u]=find(dsu[u]);
	return dsu[u];
}
void join(int u,int v){
	u=find(u);v=find(v);
	dsu[u]=v;
}
int get(int id,int r){
	for(int i=17; i>=0 ;i--){
		if(par[id][i]==0) continue;
		int duh=find(par[id][i]);
		if(st[r]<st[duh] && en[duh]<=en[r]) id=par[id][i];
	}
	return id;
}
void del(int u,int v){
	//cout << "del " << u << ' ' << v << endl;
	aw.push_back(u);ax.push_back(v);
	u=find(u);v=find(v);
	if(st[u]<=st[v] && en[u]>=en[v]){
		v=get(v,u);
		ay.push_back(v);az.push_back(par[v][0]);
		join(v,par[v][0]);
	}
	else{
		ay.push_back(u);az.push_back(par[u][0]);
		join(u,par[u][0]);
	}
	
}
vector<int>t2[N];
stack<int>s;
bool die[N];
int deg[N];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<n ;i++){
		int u,v;cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1; i<=n ;i++){
		dsu[i]=i;
	}
	for(int i=1; i<n ;i++){
		int u,v;cin >> u >> v;
		deg[u]++;deg[v]++;
		t2[u].push_back(v);
		t2[v].push_back(u);
	}
	for(int i=1; i<=n ;i++) if(deg[i]==1) s.push(i);
	for(int i=1; i<n ;i++){
		int u=s.top();
		s.pop();
		die[u]=true;
		int v;
		for(auto cur:t2[u]){
			if(!die[cur]){
				v=cur;break;
			}
		}
		del(u,v);
		deg[v]--;
		if(deg[v]==1) s.push(v);
	}
	cout << n-1 << endl;
	for(int i=0; i<n-1 ;i++) cout << ay[i] << ' ' << az[i] << ' ' << aw[i] << ' ' << ax[i] << '\n';
}