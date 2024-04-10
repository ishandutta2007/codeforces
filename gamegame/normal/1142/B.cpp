#include<iostream>
#include<queue>
using namespace std;
int n,m,q;
int p[200001];
int l[200001];
int par[200001];
int god[200001];
vector<int>c[200001];
vector<int>v;
void dfs(int id){
	v.push_back(id);
	if(v.size()>=n) god[id]=v[v.size()-n];
	for(auto cur:c[id]) dfs(cur);
	v.pop_back();
}
int maxi[524288];
void build(int id,int l,int r){
	if(l==r){
		maxi[id]=god[l];
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	maxi[id]=max(maxi[id*2],maxi[id*2+1]);
}
int qry(int id,int l,int r,int ql,int qr){
	if(l>qr || r<ql) return 0;
	if(ql<=l && r<=qr) return maxi[id];
	int mid=(l+r)/2;
	return max(qry(id*2,l,mid,ql,qr),qry(id*2+1,mid+1,r,ql,qr));
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> q;
	for(int i=1; i<=n ;i++){
		int pp;cin >> pp; p[pp]=i;
	}
	for(int i=1; i<=m ;i++){
		int a;cin >> a;a=p[a];
		int prv=(a+n-2)%n+1;
		par[i]=l[prv];
		c[par[i]].push_back(i);
		l[a]=i;
	}
	for(int i=1; i<=m ;i++){
		if(par[i]==0) dfs(i);
	}
	build(1,1,m);
	for(int i=1; i<=q ;i++){
		int ql,qr;cin >> ql >> qr;
		cout << (qry(1,1,m,ql,qr)>=ql);
	}
}