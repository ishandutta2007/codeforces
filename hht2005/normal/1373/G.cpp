#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+10;
int Max[maxn<<2],f[maxn<<2],n,k,m;
void tag(int p,int v) {
	Max[p]+=v;
	f[p]+=v;
}
void pushdown(int p) {
	if(f[p]) {
		tag(p<<1,f[p]);
		tag(p<<1|1,f[p]);
		f[p]=0;
	}
}
void change(int p,int l,int r,int x,int v) {
	if(r<=x)return tag(p,v);
	pushdown(p);
	int mid=(l+r)>>1;
	change(p<<1,l,mid,x,v);
	if(x>mid)change(p<<1|1,mid+1,r,x,v);
	Max[p]=max(Max[p<<1],Max[p<<1|1]);
}
int qry(int p,int l,int r,int x) {
	if(r<=x)return Max[p];
	pushdown(p);
	int mid=(l+r)>>1,maxx=qry(p<<1,l,mid,x);
	if(x>mid)maxx=max(maxx,qry(p<<1|1,mid+1,r,x));
	return maxx;
}
void build(int p,int l,int r) {
	if(l==r) {
		Max[p]=l-1;
		return;
	}
	int mid=(l+r)>>1; 
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	Max[p]=max(Max[p<<1],Max[p<<1|1]);
}
map<int,map<int,int> >s;
multiset<int>p;
int main() {
	int x,y;
	scanf("%d%d%d",&n,&k,&m);
	build(1,1,2*n);
	while(m--) {
		scanf("%d%d",&x,&y);
		change(1,1,2*n,y+abs(x-k),s[x][y]?-1:1);
		if(!s[x][y])p.insert(y+abs(x-k));
		else p.erase(p.find(y+abs(x-k)));
		s[x][y]^=1;
		if(p.empty()) {
			puts("0");
			continue;
		}
		int Maxp=*p.rbegin();
		printf("%d\n",max(qry(1,1,2*n,Maxp)-n,0));
	}
	return 0;
}