#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define N 1000050
typedef long long ll;
typedef long double f3;
int n;
ll f[N];
struct A {
	ll x,y,v;
	bool operator < (const A &u) const {return x<u.x;}
}a[N];
struct P {
	ll x,y;
	P() {}
	P(ll x_,ll y_) {x=x_,y=y_;}
}po[N];
ll cross(const P &p1,const P &p2) {
	return p1.x*p2.y-p1.y*p2.x;
}
f3 K(const P &p1,const P &p2) {
	return f3(p2.y-p1.y)/(p2.x-p1.x);
}
int Q[N],l,r;
bool check(P p1,P p2,P p3) {
	// ll tmp=cross(P(p2.x-p1.x,p2.y-p2.y),P(p3.x-p1.x,p3.y-p1.y));
	// return tmp>0;
	return K(p1,p2)<K(p2,p3);
}
ll calc(int j,int i) {
	return f[j]+ll(a[i].y)*(a[i].x-a[j].x)-a[i].v;
}
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].v);
	sort(a+1,a+n+1);
	ll ans=0;
	for(i=1;i<=n;i++) {
		f[i]=ll(a[i].x)*a[i].y-a[i].v;
		while(l<r-1&&calc(Q[l],i)<=calc(Q[l+1],i)) l++;
		if(l<r) f[i]=max(f[i],calc(Q[l],i));
		ans=max(ans,f[i]);
		po[i]=P(a[i].x,f[i]);
		while(l<r-1&&check(po[Q[r-2]],po[Q[r-1]],po[i])) r--;
		Q[r++]=i;
	}
	printf("%lld\n",ans);
}