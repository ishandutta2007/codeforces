#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10;
vector<int>S[N];
int col[N],tag[N<<2],dfn[N],siz[N],pos[N],dfns;
long long t[N<<2];
void build(int p,int l,int r) {
	if(l==r) {
		t[p]=1ll<<col[pos[l]];
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	t[p]=t[p<<1]|t[p<<1|1];
}
void make_tag(int p,int v) {
	tag[p]=v;
	t[p]=1ll<<v;
}
void push_down(int p) {
	if(tag[p]) {
		make_tag(p<<1,tag[p]);
		make_tag(p<<1|1,tag[p]);
		tag[p]=0;
	}
}
void modify(int p,int l,int r,int x,int y,int v) {
	if(x<=l&&r<=y)return make_tag(p,v);
	push_down(p);
	int mid=(l+r)>>1;
	if(x<=mid)modify(p<<1,l,mid,x,y,v);
	if(y>mid)modify(p<<1|1,mid+1,r,x,y,v);
	t[p]=t[p<<1]|t[p<<1|1];
}
long long qry(int p,int l,int r,int x,int y) {
	if(x<=l&&r<=y)return t[p];
	push_down(p);
	int mid=(l+r)>>1;
	long long sum=0;
	if(x<=mid)sum|=qry(p<<1,l,mid,x,y);
	if(y>mid)sum|=qry(p<<1|1,mid+1,r,x,y);
	return sum;
}
void dfs(int x,int fa) {
	pos[dfn[x]=++dfns]=x;
	siz[x]++;
	for(int y:S[x])
		if(y!=fa) {
			dfs(y,x);
			siz[x]+=siz[y];
		}
}
int get_bit(long long x) {
	int cnt=0;
	while(x) {
		cnt++;
		x-=x&-x;
	}
	return cnt;
}
int main() {
	int n,m,a,b,opt;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",col+i);
	for(int i=1;i<n;i++) {
		scanf("%d%d",&a,&b);
		S[a].push_back(b);
		S[b].push_back(a);
	}
	dfs(1,0);
	build(1,1,n);
	while(m--) {
		scanf("%d%d",&opt,&a);
		if(opt==1) {
			scanf("%d",&b);
			modify(1,1,n,dfn[a],dfn[a]+siz[a]-1,b);
		} else printf("%d\n",get_bit(qry(1,1,n,dfn[a],dfn[a]+siz[a]-1)));
	}
	return 0;
}