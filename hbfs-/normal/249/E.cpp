#include <bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL mod=(LL)1e+11;
const LL rev3=66666666667LL;
LL T(LL a,LL b){return ((a*b-(LL)((LD)a*b/mod)*mod+mod)%mod);}
LL C(LL x,LL y) {
	if(x>=y)
		return T(T(T(4,x)+T(3,T(x,x))+T(2,T(x,T(x,x)))-y-T(3,T(x,y))+T(y,T(y,y))+mod+mod,y),rev3*5);
	else
		return T(T(T(x,T(x,x))-x+T(4,y)+T(3,T(x,y))-T(3,T(y,y))+T(2,T(y,T(y,y)))+mod+mod,x),rev3*5);
}
LD W(LD x,LD y) {
	if(x>=y)
		return (4*x+3*x*x+2*x*x*x-y-3*x*y+y*y*y)*y/6;
	else
		return (x*x*x-x+4*y+3*x*y-3*y*y+2*y*y*y)*x/6;
}
int main() {
	int T,a,b,c,d;
	for(scanf("%d",&T);T--;) {
		scanf("%d%d%d%d",&a,&b,&c,&d);
		LL t=(C(c,d)-C(c,b-1)-C(a-1,d)+C(a-1,b-1)+mod+mod)%mod;
		if(W(c,d)-W(c,b-1)-W(a-1,d)+W(a-1,b-1)<1e+10)
			printf("%I64d\n",t/10);
		else
			printf("...%010I64d\n",t/10);
	}
}