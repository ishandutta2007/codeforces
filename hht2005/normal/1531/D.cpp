#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
string opt[maxn],Opt;
int las[maxn<<2];
struct Tree {
	int val[maxn<<2],tag[maxn<<2];
	Tree() {
		memset(tag,-1,sizeof(tag));
		memset(val,-1,sizeof(val));
	}
	void make_tag(int p,int f) {
		tag[p]=f;
		if(f==1)val[p]=las[p];
		else val[p]=-1;
	}
	void pushdown(int p) {
		if(~tag[p]) {
			make_tag(p<<1,tag[p]);
			make_tag(p<<1|1,tag[p]);
			tag[p]=-1;
		}
	}
	void updata(int p) {
		if(~val[p<<1|1])val[p]=val[p<<1|1];
		else val[p]=val[p<<1];
	}
	void change(int p,int l,int r,int x,int y,int v) {
		if(x>y)return;
		if(x<=l&&r<=y)return make_tag(p,v);
		pushdown(p);
		int mid=(l+r)>>1;
		if(x<=mid)change(p<<1,l,mid,x,y,v);
		if(y>mid)change(p<<1|1,mid+1,r,x,y,v);
		updata(p);
	}
	int qry(int p,int l,int r,int x) {
		if(x<=l)return val[p];
		pushdown(p);
		int mid=(l+r)>>1;
		if(x>mid)return qry(p<<1|1,mid+1,r,x);
		else if(~val[p<<1|1])return val[p<<1|1];
		else return qry(p<<1,l,mid,x);
	}
}color;
set<int>s; 
void build(int p,int l,int r) {
	las[p]=r;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
}
int main() {
	int n,x,q;
	scanf("%d",&n);
	n++;
	build(1,1,n);
	opt[0]="unlock"; 
	opt[1]="blue";
	s.insert(0);
	for(int i=2;i<=n;i++) {
		cin>>opt[i];
		if(opt[i]=="lock"||opt[i]=="unlock")s.insert(i);
	}
	s.insert(n+1);
	opt[n+1]="lock";
	int las=*s.begin();
	for(int i:s) {
		if(i==las)continue;
		if(opt[las]=="unlock")color.change(1,1,n,las+1,i-1,1);
		las=i;
	}
	cout<<opt[color.val[1]]<<endl;
	scanf("%d",&q);
	for(int i=1;i<=q;i++) {
		cin>>x>>Opt;
		x++;
		if(opt[x]=="lock"||opt[x]=="unlock") {
			int L=*--s.lower_bound(x),R=*s.upper_bound(x);
			if(opt[L]=="unlock")color.change(1,1,n,L+1,R-1,1);
			if(opt[L]=="lock")color.change(1,1,n,L,R,0);
			s.erase(x);
		}
		opt[x]=Opt;
		if(opt[x]=="lock"||opt[x]=="unlock") {
			int R=*s.upper_bound(x);
			if(opt[x]=="unlock")color.change(1,1,n,x+1,R-1,1);
			if(opt[x]=="lock")color.change(1,1,n,x,R,0);
			color.change(1,1,n,x,x,0);
			s.insert(x);
		}
		cout<<opt[color.val[1]]<<endl;
	}
	return 0;
}