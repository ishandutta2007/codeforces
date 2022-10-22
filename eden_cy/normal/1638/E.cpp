#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N=1e6+50;
const int Mod=1e9+7;
ll val[N];
#define ls p<<1
#define rs p<<1|1
#define lson L,mid,ls
#define rson mid+1,R,rs
ll add[N<<2];
int tag[N<<2],col[N<<2];
void Down(int p) {
	if(add[p]) {
		add[ls]+=add[p];
		add[rs]+=add[p];
		add[p]=0;
	}
	if(tag[p]) {
		tag[ls]=col[ls]=tag[p];
		tag[rs]=col[rs]=tag[p];
		tag[p]=0;
	}
}
void Up(int p) {
	col[p]=(col[ls]==col[rs])?col[ls]:0;
}
void build(int L,int R,int p) {
	col[p]=1;
	if(L==R) return ;
	int mid=L+R>>1;
	build(lson);
	build(rson);
	Up(p);
}
void Modify(int L,int R,int p,int l,int r,int c) {
	int mid=L+R>>1;
	if(L==l && R==r) {
		if(col[p]==0) Modify(lson,l,mid,c),Modify(rson,mid+1,r,c);
		else add[p]+=val[col[p]]-val[c],tag[p]=c;
		col[p]=c;
		return ;
	}
	Down(p);
	if(r<=mid) Modify(lson,l,r,c);
	else if(l>mid) Modify(rson,l,r,c);
	else Modify(lson,l,mid,c),Modify(rson,mid+1,r,c);
	Up(p);
}
ll Query(int L,int R,int p,int x) {
	if(L==R) return add[p]+val[col[p]];
	Down(p);
	int mid=L+R>>1;
	if(x<=mid) return Query(lson,x);
	else return Query(rson,x);
}
int main() {
	int n,q;
	scanf("%d%d",&n,&q);
	build(1,n,1);
	FOR(_,1,q) {
		char o[10];
		scanf("%s",o);
		if(o[0]=='C') {
			int l,r,c;
			scanf("%d%d%d",&l,&r,&c);
			Modify(1,n,1,l,r,c);
		} else if(o[0]=='A') {
			int c,v;
			scanf("%d%d",&c,&v);
			val[c]+=v;
		} else {
			int x;
			scanf("%d",&x);
			printf("%lld\n",Query(1,n,1,x));
		}
	}
	return 0;
}