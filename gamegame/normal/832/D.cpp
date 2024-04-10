#include<iostream>
#include<vector>
using namespace std;
int n,p,q,x,y,z;
int d[100001];
int anc[18][100001];
vector<int>c[100001];
bool vis[100001];
void build(int id){
	vis[id]=true;
	d[id]=d[anc[0][id]]+1;
	for(int i=1; i<18 ;i++){
		anc[i][id]=anc[i-1][anc[i-1][id]];
	}
	for(int i=0; i<c[id].size() ;i++){
		build(c[id][i]);
	}
}
int k_anc(int id,int cnt){
	for(int i=0; i<18 ;i++){
		if(cnt&(1<<i)){
			id=anc[i][id];
		}
	}
	return id;
}
int lca(int u,int v){
	if(d[u]>d[v]) swap(u,v);
	int dif=d[v]-d[u];
	v=k_anc(v,dif);
	if(u==v) return u;
	for(int i=17; i>=0; i--){
		if(anc[i][u]!=anc[i][v]){
			u=anc[i][u];
			v=anc[i][v];
		}
	}
	u=anc[0][u];
	return u;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for(int i=2; i<=n ;i++){
		cin >> p;
		anc[0][i]=p;
		c[p].push_back(i);
	}
	build(1);
	for(int i=1; i<=q ;i++){
		cin >> x >> y >> z;
		int m1=d[x]-max(d[lca(x,y)],d[lca(x,z)])+1;
		int m2=d[y]-max(d[lca(x,y)],d[lca(y,z)])+1;
		int m3=d[z]-max(d[lca(z,y)],d[lca(x,z)])+1;
		if(lca(y,x)==lca(z,x)) m1+=d[lca(y,z)]-max(d[lca(x,y)],d[lca(x,z)]);
		if(lca(y,x)==lca(z,y)) m2+=d[lca(x,z)]-max(d[lca(x,y)],d[lca(y,z)]);
		if(lca(y,z)==lca(z,x)) m3+=d[lca(y,x)]-max(d[lca(z,y)],d[lca(x,z)]);
		cout << max(m1,max(m2,m3)) << '\n';
	}
}