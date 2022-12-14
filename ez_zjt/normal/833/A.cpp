#include <cstdio>
#include <cstring>
#include <cmath>
#define LL long long

LL x,y;

LL gcd(LL x,LL y){
	if(!y) return x;
	return gcd(y,x%y);
}

bool check(){
	double x2=log(x),y2=log(y);
	double t1=(2*y2-x2)/3,t2=(2*x2-y2)/3;
	t1=exp(t1);
	t2=exp(t2);
	LL s1=(t1+0.5),s2=t2+0.5;
	if(fabs(t1-s1)<1e-6 && fabs(t2-s2)<1e-6) return 1;
	return 0;
}

int main(){
#ifdef DEBUG
	freopen("A.in","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&x,&y);
		if(check()) puts("Yes");
		else puts("No");
	}
	return 0;
}