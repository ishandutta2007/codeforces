#include<bits/stdc++.h>
using namespace std;
const int N=4.5e5+10;
int ls[N*30],rs[N*30],siz[N*30],tag[N*30],rt,tot;
void make_tag(int &p,int v,int L) {
	if(!p)p=++tot;
	siz[p]=v*L;
	tag[p]=v;
}
void push_down(int p,int L) {
	if(tag[p]!=-1) {
		make_tag(ls[p],tag[p],L-L/2);
		make_tag(rs[p],tag[p],L/2);
		tag[p]=-1;
	}
}
void add(int &p,int l,int r,int x,int y,int v) {
	if(!p)p=++tot;
	if(x<=l&&r<=y)return make_tag(p,v,r-l+1);
	push_down(p,r-l+1);
	int mid=(l+r)>>1;
	if(x<=mid)add(ls[p],l,mid,x,y,v);
	if(y>mid)add(rs[p],mid+1,r,x,y,v);
	siz[p]=siz[ls[p]]+siz[rs[p]];
}
int qry(int p,int l,int r,int x,int y) {
	if(!p)return 0;
	if(x<=l&&r<=y)return siz[p];
	push_down(p,r-l+1);
	int mid=(l+r)>>1,ans=0;
	if(x<=mid)ans+=qry(ls[p],l,mid,x,y);
	if(y>mid)ans+=qry(rs[p],mid+1,r,x,y);
	return ans;
}
signed main() {
	memset(tag,-1,sizeof(tag));
	int n,q,l,r,k;
	scanf("%d%d",&n,&q);
	add(rt,1,n,1,n,1);
	while(q--) {
		scanf("%d%d%d",&l,&r,&k);
		add(rt,1,n,l,r,k-1);
		printf("%d\n",siz[rt]);
	}
	return 0;
}