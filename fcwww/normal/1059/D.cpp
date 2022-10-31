#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
using namespace std;
#define N 100050
#define eps 1e-8
#define mp(x,y) make_pair(x,y)
#define fs first
#define sd second
typedef double f2;
typedef long double f3;
int n;
struct A {
	f3 x,y;
}a[N];
pair<f3,f3> get_x(f3 x,f3 y,f3 r) {
	f3 tmp=sqrt(r*r-(y-r)*(y-r));
	return mp(x-tmp,x+tmp);
}
int UP(f3 mid) {
	int i;
	f3 l=-1e20,r=1e20;
	for(i=1;i<=n;i++) {
		if(a[i].y>2*mid) return 0;
		pair<f3,f3> tmp=get_x(a[i].x,a[i].y,mid);
		l=max(l,tmp.fs);
		r=min(r,tmp.sd);
	}
	return l<r;
}
int check(f3 mid) {
	return UP(mid);
}
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) {
		scanf("%Lf%Lf",&a[i].x,&a[i].y);
	}
	for(i=1;i<=n;i++) {
		if(a[i].y*a[n].y<0) return puts("-1"),0;
		a[i].y=abs(a[i].y);
	}
	f3 l=0, r=1e17;
	for(i=1;i<=200;i++) {
		f3 mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}
	if(fabs(l-1e17)<l*eps) puts("-1");
	else printf("%.10Lf\n",l);
}