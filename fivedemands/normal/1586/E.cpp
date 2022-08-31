#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,m;
int p[N];
int f[N];
int qu[N],qv[N];
int find(int x){
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}
bool join(int x,int y){
	x=find(x);y=find(y);
	if(x==y) return false;
	p[x]=y;
	return true;
}
vector<int>adj[N];

int ptr=0;
int st[N],en[N];
int par[N];
void dfs(int id,int p){
	st[id]=++ptr;
	for(auto c:adj[id]){
		if(c==p) continue;
		dfs(c,id);
	}
	en[id]=ptr;
	par[id]=p;
}
void bang(int u,int v,vector<int>&cur){
	cur.push_back(u);
	while(st[u]>st[v] || en[u]<en[v]){
		u=par[u];
		cur.push_back(u);
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n ;i++) p[i]=i;
	for(int i=1; i<=m ;i++){
		int u,v;cin >> u >> v;
		if(join(u,v)){
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}
	dfs(1,0);
	int q;cin >> q;
	for(int i=1; i<=q ;i++){
		cin >> qu[i] >> qv[i];
		f[qu[i]]^=1;f[qv[i]]^=1;
	}
	int s=0;
	for(int i=1; i<=n ;i++) s+=f[i];
	if(s!=0){
		cout << "NO\n" << s/2 << '\n';
		return 0;
	}
	cout << "YES\n";
	for(int i=1; i<=q ;i++){
		int u=qu[i];
		int v=qv[i];
		vector<int>cur,cur2;
		bang(u,v,cur);bang(v,u,cur2);
		cur2.pop_back();
		reverse(cur2.begin(),cur2.end());
		cout << cur.size()+cur2.size() << '\n';
		for(auto c:cur) cout << c << ' ';
		for(auto c:cur2) cout << c << ' ';
		cout << '\n';
	}
}