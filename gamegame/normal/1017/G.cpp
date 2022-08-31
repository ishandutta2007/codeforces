#include<iostream>
#include<queue>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second

int n,q;
int p[100001];
int sz[100001];
int bc[100001];
int top[100001];
int newi[100001];
int sr[100001];
vector<int>c[100001];
pii zero={0,-1e9};
pii f(pii x,pii y){
	return {x.fi+y.fi,max(y.se,x.se+y.fi)};
}

pii info[262144];
bool tag[262144];
int lazy[262144];
void put(int id,int l,int r,int v){
	tag[id]=true;lazy[id]=v;
	info[id]={v*(r-l+1),max(v*(r-l+1),v)};
}
void push(int id,int l,int r){
	if(!tag[id]) return;
	int mid=(l+r)/2;
	put(id*2,l,mid,lazy[id]);
	put(id*2+1,mid+1,r,lazy[id]);
	tag[id]=false;
}
void upd1(int id,int l,int r,int ql,int qr,int v){
	if(ql>r || qr<l) return;
	if(ql<=l && r<=qr){
		put(id,l,r,v);
		return;
	}
	push(id,l,r);
	int mid=(l+r)/2;
	upd1(id*2,l,mid,ql,qr,v);upd1(id*2+1,mid+1,r,ql,qr,v);
	info[id]=f(info[id*2],info[id*2+1]);
}
void upd2(int id,int l,int r,int pos,int v){
	if(l==r){
		info[id]={info[id].fi+v,info[id].se+v};
		return;
	}
	push(id,l,r);
	int mid=(l+r)/2;
	if(pos<=mid) upd2(id*2,l,mid,pos,v);
	else upd2(id*2+1,mid+1,r,pos,v);
	info[id]=f(info[id*2],info[id*2+1]);
}
pii qry(int id,int l,int r,int ql,int qr){
	if(ql>r || qr<l) return zero;
	if(ql<=l && r<=qr) return info[id];
	push(id,l,r);
	int mid=(l+r)/2;
	return f(qry(id*2,l,mid,ql,qr),qry(id*2+1,mid+1,r,ql,qr));
}
int g(int id){
	pii res=zero;
	while(id!=0){
 		res=f(qry(1,1,n,newi[top[id]],newi[id]),res);
		id=p[top[id]];
	}
	return res.se;
}
void dfs(int id){
	sz[id]=1;
	for(auto cur:c[id]){
		dfs(cur);
		sz[id]+=sz[cur];
		if(sz[bc[id]]<sz[cur]) bc[id]=cur;
	}
}
int ptr=0;
void dfs2(int id){
	newi[id]=++ptr;
	sr[id]=ptr;
	if(c[id].empty()) return;
	top[bc[id]]=top[id];
	dfs2(bc[id]);
	sr[id]=sr[bc[id]];
	for(auto cur:c[id]){
		if(cur!=bc[id]){
			top[cur]=cur;
			dfs2(cur);
			sr[id]=sr[cur];
		}
		
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for(int i=2; i<=n ;i++){
		cin >> p[i];
		c[p[i]].push_back(i);
	}
	dfs(1);
	top[1]=1;
	dfs2(1);
	upd1(1,1,n,1,n,-1);
	for(int i=1; i<=q ;i++){
		int t,u;
		cin >> t >> u;
		if(t==1) upd2(1,1,n,newi[u],1);
		else if(t==2){
			upd1(1,1,n,newi[u],sr[u],-1);
			int num=g(u);
			if(num>=0) upd2(1,1,n,newi[u],-num-1);
		}
		else{
			int num=g(u);
			if(num>=0) cout << "black\n";
			else cout << "white\n";
		}
	}
}