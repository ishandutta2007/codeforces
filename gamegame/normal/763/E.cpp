#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
int n,k;
vector<int>adj[N],rev[N];
typedef array<int,5> ar;
ar lp[N],rp[N];
int pw[N];
int cp;
int p[N];
int g[N];
int h[N];
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
void build(int id,int l,int r){
	if(l==r){
		pw[id]=1;
		p[l]=l;
		lp[id][0]=rp[id][0]=l;
		return;
	}
	bool debug=false;
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	pw[id]=pw[id*2]+pw[id*2+1];
	for(int i=max(l,mid-4); i<=mid ;i++){
		for(auto c:adj[i]){
			if(c>mid && c<=r){
				if(debug) cout << "in " << find(i) << ' ' << find(c) << ' ' << i << ' ' << c << '\n';
				if(join(i,c)) pw[id]--;
				if(debug) cout << "out "<< find(i) << ' ' << find(c) << ' ' << i << ' ' << c << '\n';
			}
		}
	}
	for(int i=l; i<=min(r,l+4) ;i++){
		h[i]=find(i);
		g[h[i]]=i;
	}
	for(int i=max(l,r-4); i<=r ;i++){
		h[i]=find(i);
		g[h[i]]=i;
	}
	for(int i=l; i<=min(r,l+4) ;i++) p[i]=g[h[i]];
	for(int i=max(l,r-4); i<=r ;i++) p[i]=g[h[i]];
	for(int i=l; i<=min(r,l+4) ;i++) lp[id][i-l]=p[i];
	for(int i=max(l,r-4); i<=r ;i++) rp[id][r-i]=p[i];
	if(debug){
		cout << id << ' ' << l << ' ' << r << ' ' << pw[id] << '\n';
		for(int i=l; i<=r ;i++){
			cout << p[i] << ' ';
		}
		cout << '\n';
	}
}
vector<int>wash;
void qry(int id,int l,int r,int ql,int qr){
	if(l>qr || r<ql) return;
	if(ql<=l && r<=qr){
		for(int i=l; i<=min(r,l+4) ;i++) p[i]=lp[id][i-l];
		for(int i=max(l,r-4); i<=r ;i++) p[i]=rp[id][r-i];
		for(int i=l; i<=min(r,l+4) ;i++) wash.push_back(i);
		for(int i=max(l,r-4); i<=r ;i++) wash.push_back(i);
		cp+=pw[id];
		
		for(int i=l; i<=min(r,l+4) ;i++){
			for(auto c:rev[i]){
				if(c>=ql && c<l){
					if(join(c,i)) cp--;
				}
			}
		}
		for(int i=max(l,r-4); i<=r ;i++){
			h[i]=find(i);
			g[h[i]]=i;
		}
		for(int i=max(l,r-4); i<=r ;i++) p[i]=g[h[i]];
		return;
	}
	int mid=(l+r)/2;
	qry(id*2,l,mid,ql,qr);
	qry(id*2+1,mid+1,r,ql,qr);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> k;
	int m;cin >> m;
	for(int i=1; i<=m ;i++){
		int u,v;cin >> u >> v;
		if(u>v) swap(u,v);
		adj[u].push_back(v);
		rev[v].push_back(u);
	}
	build(1,1,n);
	for(int i=1; i<=n ;i++) p[i]=0;
	int q;cin >> q;
	for(int i=1; i<=q ;i++){
		int l,r;cin >> l >> r;
		cp=0;
		qry(1,1,n,l,r);
		cout << cp << '\n';
		for(auto c:wash) p[c]=0;
		wash.clear();
	}
}