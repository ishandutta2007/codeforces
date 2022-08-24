#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=1e6+1;
const int ts=1<<21;
int n;
int eu[N],ev[N],ew[N];
vector<int>adj[N];
int e[N],d2[N];;
int st[N],en[N];
int ptr=0;
int seq[N];
void dfs(int id,int p){
	st[id]=++ptr;
	seq[ptr]=id;
	for(auto c:adj[id]){
		if(c==p) continue;
		e[c]=e[id]+1;
		dfs(c,id);
		seq[++ptr]=id;
	}
	en[id]=ptr;
}
array<int,9>a[ts];
bool lz[ts];
void putlz(int id){
	swap(a[id][1],a[id][2]);
	swap(a[id][3],a[id][4]);
	swap(a[id][5],a[id][6]);
	swap(a[id][7],a[id][8]);
}
void pull(int id){
	int lc=id*2,rc=id*2+1;
	for(int i=0; i<=8 ;i++){
		a[id][i]=max(a[lc][i],a[rc][i]);
	}
	a[id][3]=max(a[id][3],a[lc][1]+a[rc][0]);
	a[id][4]=max(a[id][4],a[lc][2]+a[rc][0]);
	a[id][5]=max(a[id][5],a[lc][0]+a[rc][1]);
	a[id][6]=max(a[id][6],a[lc][0]+a[rc][2]);
	a[id][7]=max(a[id][7],a[lc][1]+a[rc][5]);
	a[id][7]=max(a[id][7],a[lc][3]+a[rc][1]);
	a[id][8]=max(a[id][8],a[lc][2]+a[rc][6]);
	a[id][8]=max(a[id][8],a[lc][4]+a[rc][2]);
}
void push(int id){
	if(!lz[id]) return;
	putlz(id*2);
	putlz(id*2+1);
	lz[id*2]^=1;lz[id*2+1]^=1;
	lz[id]=false;
}
void build(int id,int l,int r){
	for(int i=0; i<=8 ;i++) a[id][i]=-1e6;
	if(l==r){
		int d=e[seq[l]];
		a[id][0]=-2*d;
		a[id][1]=d;
		a[id][3]=-d;
		a[id][5]=-d;
		a[id][7]=0;
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	pull(id);
}
void upd(int id,int l,int r,int ql,int qr){
	if(l>qr || r<ql) return;
	if(ql<=l && r<=qr){
		putlz(id);lz[id]^=1;return;
	}
	push(id);
	int mid=(l+r)/2;
	upd(id*2,l,mid,ql,qr);
	upd(id*2+1,mid+1,r,ql,qr);
	pull(id);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for(int i=1; i<n ;i++){
		cin >> eu[i] >> ev[i] >> ew[i];
		int u=eu[i],v=ev[i];
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0);
	build(1,1,2*n-1);
	for(int i=1; i<n ;i++){
		if(st[eu[i]]>st[ev[i]]) swap(eu[i],ev[i]);
		if(ew[i]) upd(1,1,2*n-1,st[ev[i]],en[ev[i]]);
	}
	int q;cin >> q;
	for(int i=1; i<=q ;i++){
		int x;cin >> x;
		upd(1,1,2*n-1,st[ev[x]],en[ev[x]]);
		ew[x]^=1;
		cout << max(a[1][7],a[1][8]) << '\n';
	}
}