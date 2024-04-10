#include<bits/stdc++.h>
#define N 1000005
using namespace std;
struct node {
	long long x,y,s;
}a[N],q[N];
long long f[N];
long long n;
const long long P=1000000000;

bool cmp(node x,node y) {
	return x.x<y.x;
}

bool check(node x,node y,node z) {
	x.x-=y.x;
	x.y-=y.y;
	y.x-=z.x;
	y.y-=z.y;
	return x.x/x.y>=y.x/y.y;
}

bool check(node x,node y,long long z) {
	return x.x-x.y*z>y.x-y.y*z;
}

int main() {
	scanf("%lld",&n);
	for (long long i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].s);
	sort(a+1,a+1+n,cmp);
	long long r=1; q[1].s=0,q[1].x=q[1].y=0;
	for (long long i=1;i<=n;i++) {
		long long L=2,R=r,s=1;
		while (L<=R) {
			long long mid=(L+R)>>1;
			if (check(q[mid],q[mid-1],a[i].y)) s=mid,L=mid+1;
			else R=mid-1;
		}
		s=q[s].s;
		f[i]=f[s]+(a[i].x-a[s].x)*a[i].y-a[i].s;
		node xx;
		xx.s=i;
		xx.x=f[i];
		xx.y=a[i].x;
		while (r>1&&check(xx,q[r],q[r-1])) r--;
		q[++r]=xx;
	}
	long long ans=0;
	for (int i=1;i<=n;i++) ans=max(ans,f[i]);
	printf("%lld\n",ans);
}