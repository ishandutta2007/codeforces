#include<bits/stdc++.h>
using namespace std;
#define N 2000020
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,l;
ll l1,r1,l2,r2;
struct Pos{
	ll x,y;
	ll t;
	friend bool operator < (const Pos &a,const Pos &b){
		return a.t%l<b.t%l;
	}
}a[N];
int main(){
	n=read(),l=read();
	a[0].x=a[0].y=a[0].t=0;
	for(int i=1;i<=n;i++){
		a[i].t=read(),a[i].x=read(),a[i].y=read();
		if((a[i].t^a[i].x^a[i].y)&1)return puts("NO"),0;
	}
	sort(a,a+n+1);
	a[n+1].t=-l;
	l1=l2=-1e18,r1=r2=1e18;
	for(int i=0;i<=n;i++){
		ll d=a[i+1].t/l-a[i].t/l;
		ll x=a[i+1].x-a[i].x,y=a[i+1].y-a[i].y;
		ll t=a[i+1].t%l-a[i].t%l;
		if(i==n)t+=l;
		ll a1=x+y-t,b1=x+y+t;
		ll a2=x-y-t,b2=x-y+t;
		if(d==0&&(a1>0||b1<0||a2>0||b2<0))return puts("NO"),0;
		if(d){
			if(d<0)d=-d,swap(a1,b1),swap(a2,b2),a1=-a1,b1=-b1,a2=-a2,b2=-b2;
			l1=max(l1,a1>0?(a1+d-1)/d:a1/d);
			r1=min(r1,b1>0?b1/d:(b1-d+1)/d);
			l2=max(l2,a2>0?(a2+d-1)/d:a2/d);
			r2=min(r2,b2>0?b2/d:(b2-d+1)/d);
		}
	}
	if(l1>r1||l2>r2)return puts("NO"),0;
	if((l1^l)&1){
		if(l1==r1)return puts("NO"),0;
		else l1++;
	}
	if((l2^l)&1){
		if(l2==r2)return puts("NO"),0;
		else l2++;
	}
	ll dx=(l1+l2)/2,dy=(l1-l2)/2;
	ll t=0,x=0,y=0;
	for(int i=1;i<=n;i++){
		a[i].x-=a[i].t/l*dx;
		a[i].y-=a[i].t/l*dy;
		while(x<a[i].x)x++,t++,putchar('R');
		while(x>a[i].x)x--,t++,putchar('L');
		while(y<a[i].y)y++,t++,putchar('U');
		while(y>a[i].y)y--,t++,putchar('D');
		while(t<a[i].t%l)printf("LR"),t+=2;
	}
	while(x<dx)x++,t++,putchar('R');
	while(x>dx)x--,t++,putchar('L');
	while(y<dy)y++,t++,putchar('U');
	while(y>dy)y--,t++,putchar('D');
	while(t<l)printf("LR"),t+=2;
	printf("\n");
	return 0;
}