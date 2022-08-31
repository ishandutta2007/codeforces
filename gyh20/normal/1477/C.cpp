#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
struct point{
	int x,y;
	int id;
	bool operator <(const point a)const{return x==a.x?y<a.y:x<a.x;}
}p[5002];
inline bool check(re point x,re point y,re point z){
	int a1=x.x-y.x,b1=x.y-y.y,a2=z.x-y.x,b2=z.y-y.y;
	if(a1*a1+b1*b1+a2*a2+b2*b2>(a2-a1)*(a2-a1)+(b2-b1)*(b2-b1))return 1;
	return 0;
}
int n,a[5002];
inline bool ck(){
	
	for(re int i=3;i<=n;++i)if(!check(p[a[i-2]],p[a[i-1]],p[a[i]]))return 0;
}
signed main(){
	n=read();
	for(re int i=1;i<=n;++i)p[i].x=read(),p[i].y=read(),p[i].id=i,a[i]=i;
	sort(p+1,p+n+1);
	for(re int i=1;i<=n;++i)
		for(re int pp=n;pp>=3;--pp)if(!check(p[a[pp-2]],p[a[pp-1]],p[a[pp]]))swap(a[pp-1],a[pp]);
	if(ck()){for(re int i=1;i<=n;++i)printf("%lld ",p[a[i]].id);return 0;
	}
	swap(a[1],a[2]);
	for(re int i=1;i<=n;++i)
		for(re int pp=n;pp>=3;--pp)if(!check(p[a[pp-2]],p[a[pp-1]],p[a[pp]]))swap(a[pp-1],a[pp]);
		if(ck()){for(re int i=1;i<=n;++i)printf("%lld ",p[a[i]].id);return 0;
	}
	return 1;
}