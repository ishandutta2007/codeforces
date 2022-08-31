#include<bits/stdc++.h>
#define maxn 234000
#define M 998244353
using namespace std;
typedef long long ll;
struct node{
	int l,r;

	node operator +(node const &u){
		return {min(l,u.l),max(r,u.r)};
	}
	node operator ^(node const &u){
		return {max(l,u.l),min(r,u.r)};
	}
};

struct cmp{
	inline bool operator () (node u,node v) {
		if (u.r!=v.r) return u.r<v.r;
		return u.l<v.l;
	}
};

bool it(node u,node v){
	if (u.r<v.l||v.r<u.l) return false; else return true;
}

set<node,cmp>h[maxn];
set<node,cmp>::iterator t,_t;

struct tree{
	int l,r;
	ll val,mut,add;
}a[maxn*4];
int n,q,p;

void pass(int o){
	a[o].val=(a[o].val*a[o].mut+a[o].add*(a[o].r-a[o].l+1))%M;
	if (a[o].l==a[o].r){
		a[o].mut=1; a[o].add=0;
		return;
	}
	a[o<<1].mut=a[o].mut*a[o<<1].mut%M;
	a[(o<<1)|1].mut=a[o].mut*a[(o<<1)|1].mut%M;
	a[o<<1].add=(a[o].mut*a[o<<1].add+a[o].add)%M;
	a[(o<<1)|1].add=(a[o].mut*a[(o<<1)|1].add+a[o].add)%M;
	a[o].mut=1; a[o].add=0;
}

void _merge(int o){
    pass(o);
    if (o==1) return;
	a[o>>1].val=(a[o].val+a[o^1].val)%M;
}

void update_add(int o,int l,int r,int v){
    _merge(o);
    //if (o==1) cout<<'+'<<o<<' '<<l<<' '<<r<<' '<<v<<endl;
	if (a[o].r<l||a[o].l>r) return;
	if (a[o].l>=l&&a[o].r<=r){
		(a[o].add+=v)%=M;
		_merge(o);
		return;
	}
	update_add(o<<1,l,r,v);
	update_add((o<<1)|1,l,r,v);
	_merge(o);
}

void update_mut(int o,int l,int r,int v){
    _merge(o);
    //cout<<'*'<<o<<' '<<l<<' '<<r<<' '<<v<<endl;
	if (a[o].r<l||a[o].l>r) return;
	if (a[o].l>=l&&a[o].r<=r){
		(a[o].mut*=v)%=M;
		_merge(o);
		return;
	}
	update_mut(o<<1,l,r,v);
	update_mut((o<<1)|1,l,r,v);
	_merge(o);
}

int qry(int o,int l,int r){
	pass(o);
	if (a[o].r<l||a[o].l>r) return 0;
	if (a[o].l>=l&&a[o].r<=r) return a[o].val;
	return (qry(o<<1,l,r)+qry((o<<1)|1,l,r))%M;
}

void build(int o,int l,int r){
    a[o].l=l; a[o].r=r; a[o].mut=1;
    if (l==r) return;
    int mid=(l+r)>>1;
    build(o<<1,l,mid);
    build((o<<1)|1,mid+1,r);
}

int main(){
	cin >> n >> q;
	build(1,1,n);

	while (q--){
		int o,l,r,w;
		scanf("%d%d%d",&o,&l,&r);
		if (o==1){
			scanf("%d",&w);
			node tmp={l,r};
			update_add(1,l,r,1);
			t=h[w].lower_bound(node{0ll,l});
			while (t!=h[w].end()&&it(*t,tmp)){
				node tt=*t,ins=tmp^tt;
				update_add(1,ins.l,ins.r,-1);
				update_mut(1,ins.l,ins.r,2);
				tmp=tmp+tt; t++;
				h[w].erase(tt);
			}
			h[w].insert(tmp);
		}
		else printf("%d\n",qry(1,l,r));
	}

	return 0;
}