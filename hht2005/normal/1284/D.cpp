#include<bits/stdc++.h>
using namespace std;
#define lb(x) lower_bound(v+1,v+i,x)-v
const int M=1e9,maxn=1e5+10;
struct node {
	int x1,y1,x2,y2;
}a[maxn];
inline int cmp1(const node &a,const node &b) {
	return a.y1<b.y1;
}
inline int cmp2(const node &a,const node &b) {
	return a.y2<b.y2;
}
int v[maxn],rt[maxn],ls[maxn*100],rs[maxn*100],f[maxn*100],tot;
inline int qry(int p,int l,int r,int x,int y) {
	if(!p)return 0;
	if(x<=l&&r<=y)return 1;
	if(f[p])return 1;
	int mid=(l+r)>>1,ans=0;
	if(x<=mid)ans|=qry(ls[p],l,mid,x,y);
	if(y>mid)ans|=qry(rs[p],mid+1,r,x,y);
	return ans;
}
inline void ins(int lp,int &np,int l,int r,int x,int y) {
	np=++tot;
	f[np]=f[lp];
	ls[np]=ls[lp];
	rs[np]=rs[lp];
	if(x<=l&&r<=y) {
		f[np]=1;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)ins(ls[lp],ls[np],l,mid,x,y);
	if(y>mid)ins(rs[lp],rs[np],mid+1,r,x,y);
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	sort(a+1,a+n+1,cmp1);
	for(int i=1;i<=n;i++) {
		if(qry(rt[lb(a[i].x1)-1],1,M,a[i].x2,a[i].y2)) {
			puts("NO");
			return 0;//////
		}////
		v[i]=a[i].y1;////
		ins(rt[i-1],rt[i],1,M,a[i].x2,a[i].y2);///////
	}
	memset(rt,tot=0,sizeof(rt));///////
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n;i++) {
		if(qry(rt[lb(a[i].x2)-1],1,M,a[i].x1,a[i].y1)) {
			puts("NO");
			return 0;
		}
		v[i]=a[i].y2;
		ins(rt[i-1],rt[i],1,M,a[i].x1,a[i].y1);
	}
	puts("YES");
	return 0;
}