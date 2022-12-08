#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int w[maxn<<2];
struct node {
	int x,y,v;
	node(){}
	node(int xx,int yy,int vv) {
		x=xx,y=yy,v=vv;
	}
	int operator<(const node &a)const {
		return x<a.x;
	}
}p1[maxn],p2[maxn];
void add(int p,int l,int r,int x,int v) {
	if(l==r) {
		w[p]+=v;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)add(p<<1,l,mid,x,v);
	else add(p<<1|1,mid+1,r,x,v);
	w[p]=w[p<<1]+w[p<<1|1];
}
int qry(int p,int l,int r,int x,int y) {
	if(x<=l&&r<=y)return w[p];
	int mid=(l+r)>>1,s=0;
	if(x<=mid)s+=qry(p<<1,l,mid,x,y);
	if(y>mid)s+=qry(p<<1|1,mid+1,r,x,y);
	return s;
}
int main() {
	int n,m,x,l,r;
	long long sum=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%d%d%d",&x,&l,&r);
		p1[i*2-1]=node(l,x,1);
		p1[i*2]=node(r+1,x,-1);
		if(l==0&&r==1000000)sum++;
	}
	sort(p1+1,p1+2*n+1);
	for(int i=1;i<=m;i++) {
		scanf("%d%d%d",&p2[i].x,&p2[i].y,&p2[i].v);
		if(p2[i].y==0&&p2[i].v==1000000)sum++;
	}
	sort(p2+1,p2+m+1);
	int cnt=0;
	for(int i=1;i<=m;i++) {
		while(cnt<2*n&&p1[cnt+1].x<=p2[i].x)add(1,1,1e6,p1[cnt+1].y,p1[cnt+1].v),cnt++;
		sum+=qry(1,1,1e6,p2[i].y,p2[i].v);
	}
	printf("%lld\n",sum);
	return 0;
}