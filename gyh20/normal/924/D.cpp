#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
struct node{
	double x,y;
	bool operator <(const node A)const{return x==A.x?y>A.y:x<A.x;}
}p[100002];
int n,m,c[100002];
double a[100002];
inline void add(re int x){for(;x<=n;x+=x&(-x))++c[x];}
inline int ask(re int x,re int s=0){for(;x;x^=x&(-x))s+=c[x];return s;}
long long ans;
int main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i){
		re int x=read(),y=read();
		re double X=1.0*x/(y-m),Y=1.0*x/(y+m);
		p[i].x=X,p[i].y=Y,a[i]=Y;
	}
	sort(p+1,p+n+1),sort(a+1,a+n+1);
	for(re int i=1;i<=n;++i)p[i].y=lower_bound(a+1,a+n+1,p[i].y)-a;
	for(re int i=n;i;--i)ans+=ask(p[i].y),add(p[i].y);
	printf("%lld",ans);
}