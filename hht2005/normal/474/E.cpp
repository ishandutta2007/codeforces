#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int f[N],pre[N],Max[N<<2];
long long a[N],c[N];
void add(int p,int l,int r,int x,int v) {
	if(f[v]>f[Max[p]])Max[p]=v;
	if(l==r)return;
	int mid=(l+r)>>1;
	if(x<=mid)add(p<<1,l,mid,x,v);
	else add(p<<1|1,mid+1,r,x,v);
}
int qry(int p,int l,int r,int x,int y) {
	if(x<=l&&r<=y)return Max[p];
	int mid=(l+r)>>1,T1=0,T2=0;
	if(x<=mid)T1=qry(p<<1,l,mid,x,y);
	if(y>mid)T2=qry(p<<1|1,mid+1,r,x,y);
	if(f[T1]<f[T2])return T2;
	return T1;
}
void print(int x) {
	if(!x)return;
	print(pre[x]);
	printf("%d ",x);
}
int main() {
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++) {
		scanf("%lld",a+i);
		c[i]=a[i];
	}
	sort(c+1,c+n+1);
	int m=unique(c+1,c+n+1)-c-1,Max=0,T=0;
	for(int i=1;i<=n;i++) {
		int t1=qry(1,0,m,0,upper_bound(c+1,c+m+1,a[i]-d)-c-1);
		int t2=qry(1,0,m,lower_bound(c+1,c+m+1,a[i]+d)-c,m),t=0;
		if(f[t1]<f[t2])t=t2;
		else t=t1;
		pre[i]=t;
		f[i]=f[t]+1;
		add(1,0,m,lower_bound(c+1,c+m+1,a[i])-c,i);
		if(Max<f[i])Max=f[T=i];
	}
	printf("%d\n",f[T]);
	print(T);
	puts("");
	return 0;
}