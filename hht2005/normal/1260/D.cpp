#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int a[maxn];
struct trap {
	int l,r,d;
	int operator<(const trap &a)const {
		return a.d<d;
	}
}p[maxn];
int s[maxn<<2],f[maxn<<2];
void tag(int p,int l) {
	s[p]=l;
	f[p]=1;
}
void cover(int p,int l,int r,int x,int y) {
	if(f[p])return;
	if(x<=l&&r<=y)return tag(p,r-l+1);
	int mid=(l+r)>>1;
	if(x<=mid)cover(p<<1,l,mid,x,y);
	if(y>mid)cover(p<<1|1,mid+1,r,x,y);
	s[p]=s[p<<1]+s[p<<1|1];
}
int main() {
	int m,n,k,t,cnt=0,D=0;
	scanf("%d%d%d%d",&m,&n,&k,&t);
	t-=n+1;
	for(int i=1;i<=m;i++)
		scanf("%d",a+i);
	for(int i=1;i<=k;i++)
		scanf("%d%d%d",&p[i].l,&p[i].r,&p[i].d);
	sort(p+1,p+1+k);
	for(int i=1;i<=k;i++) {
		cover(1,1,n,p[i].l,p[i].r);
		if(2*s[1]>t) {
			D=p[i].d;
			break;
		}
	}
	for(int i=1;i<=m;i++)
		if(a[i]>=D)cnt++;
	printf("%d\n",cnt);
	return 0;
}