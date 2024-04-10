#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef unsigned long long ull;
const ull base=1145141;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,Q,a[N],tot;
ull pw[N];
struct Data{
	ull hl,hr;
	int cl,cr;
	bool ok;
	void init(){
		ok=false;cl=cr=hl=hr=0;
	}
};
struct node{
	int l,r;
	int ch[2];
	Data p;
}tree[N<<3];
#define ls tree[i].ch[0]
#define rs tree[i].ch[1]
ull Getl(int i,int len){
	if(!len)return 0;
	if(i<=(n<<2)&&tree[i].l==tree[i].r)return tree[i].p.hl;
	if(tree[ls].p.cl>=len)return Getl(ls,len);
	int zyk=len-tree[ls].p.cl;
	return tree[ls].p.hl*pw[zyk]+Getl(rs,zyk+tree[ls].p.cr)-tree[ls].p.hr*pw[zyk];
}
ull Getr(int i,int len){
	if(!len)return 0;
	if(i<=(n<<2)&&tree[i].l==tree[i].r)return tree[i].p.hr;
	if(tree[rs].p.cr>=len)return Getr(rs,len);
	int zyk=len-tree[rs].p.cr;
	return tree[rs].p.hr*pw[zyk]+Getr(ls,zyk+tree[rs].p.cl)-tree[rs].p.hl*pw[zyk];
}
inline void update(int i){
	if(!tree[ls].p.ok||!tree[rs].p.ok){
		tree[i].p.ok=false;
		return;
	}
	if(tree[ls].p.cr<=tree[rs].p.cl){
		ull z=Getl(rs,tree[ls].p.cr);
		if(z^tree[ls].p.hr){
			tree[i].p.ok=false;return;
		}
		int zyk=tree[rs].p.cl-tree[ls].p.cr;
		tree[i].p.cl=tree[ls].p.cl+zyk;
		tree[i].p.cr=tree[rs].p.cr;
		tree[i].p.hr=tree[rs].p.hr;
		tree[i].p.hl=tree[ls].p.hl*pw[zyk]+tree[rs].p.hl-z*pw[zyk];
	}
	else{
		ull z=Getr(ls,tree[rs].p.cl);
		if(z^tree[rs].p.hl){
			tree[i].p.ok=false;return;
		}
		int zyk=tree[ls].p.cr-tree[rs].p.cl;
		tree[i].p.cl=tree[ls].p.cl;
		tree[i].p.cr=tree[rs].p.cr+zyk;
		tree[i].p.hl=tree[ls].p.hl;
		tree[i].p.hr=tree[rs].p.hr*pw[zyk]+tree[ls].p.hr-z*pw[zyk];
	}
	tree[i].p.ok=true;
}
void build(int i,int l,int r){
	tree[i].l=l;
	tree[i].r=r;
	ls=i<<1;
	rs=i<<1|1;
	if(l==r){
		if(a[l]<0)tree[i].p.cl=1,tree[i].p.hl=-a[l];
		  else    tree[i].p.cr=1,tree[i].p.hr=a[l];
		tree[i].p.ok=true;
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	update(i);
}
void Change(int i,int pos){
	if(tree[i].l==tree[i].r){
		if(a[pos]<0)tree[i].p.cl=1,tree[i].p.cr=tree[i].p.hr=0,tree[i].p.hl=-a[pos];
		  else		tree[i].p.cl=tree[i].p.hl=0,tree[i].p.cr=1,tree[i].p.hr=a[pos];
		return;
	}
	int mid=(tree[i].l+tree[i].r)>>1;
	if(pos<=mid){
		Change(ls,pos);
	}
	else{
		Change(rs,pos);
	}
	update(i);
}
int Query(int i,int l,int r){
	if(tree[i].l>=l&&tree[i].r<=r){
		return i;
	}
	int mid=(tree[i].l+tree[i].r)>>1;
	int k=++tot;
	tree[k].ch[0]=tree[k].ch[1]=0;
	if(l<=mid&&r>mid){
		tree[k].ch[0]=Query(ls,l,r);
		tree[k].ch[1]=Query(rs,l,r);
		update(k);
		return k;
	}
	else if(l<=mid){
		return Query(ls,l,r);
	}
	else{
		return Query(rs,l,r);
	}
}
int main(){
	n=read(),m=read();
	pw[0]=1;
	for(int i=1;i<=n;++i){
		pw[i]=pw[i-1]*base;
		a[i]=read();
	}
	build(1,1,n);
	Q=read();
	while(Q--){
		int opt=read(),x=read(),y=read();
		if(opt==1){
			a[x]=y;
			Change(1,x);
		}
		else{
			tot=n<<2;
			Data tmp=tree[Query(1,x,y)].p;
			printf(tmp.ok&&!tmp.cl&&!tmp.cr?"Yes\n":"No\n");
		}
	}
	return 0;
}