#include <bits/stdc++.h>
#define DB double
#define MAXN 100010
using namespace std;

const DB eps=1e-6;

int read(){
	char c;
	while((c=getchar())<'0' || c>'9');
	int res=c-'0';
	while((c=getchar())>='0' && c<='9') res=res*10+c-'0';
	return res;
}

int n;
DB w,h;
DB sx1,sx2;
int ti[MAXN];
DB p[MAXN][2];

bool check(DB v){
	DB l=sx1,r=sx1;
	DB lx=(sx1+sx2)/2,ly=h/2;
	for(int i=1;i<=n;i++){
		DB a1=-(h-p[i][1])/p[i][1],b1=p[i][0]-a1*p[i][0];
		DB a2=-ly/(h-ly),b2=lx-a2*lx;
		DB a=a1*a2,b=b2+a2*b1;
		DB d1=v*(ti[i]-ti[i-1]),d2=-a2*d1;
		DB l1=l-d1,r1=r+d1,l2=(l-d2-b)/a,r2=(r+d2-b)/a,l3,r3,l4,r4;
		if(a<1-eps){
			l3=(d1+d2-b)/(a-1);
			r3=(-d1-d2-b)/(a-1);
		}else if(a>1+eps){
			l3=(-d1-d2-b)/(a-1);
			r3=(d1+d2-b)/(a-1);
		}else{
			if(abs(b)>d1+d2) return 0;
			l3=0,r3=w;
		}
		l4=p[i][0]-(w-p[i][0])*p[i][1]/(h-p[i][1]);
		r4=p[i][0]-(0-p[i][0])*p[i][1]/(h-p[i][1]);
		l=max(max(max(l1,l2),max(l3,l4)),(DB)0);
		r=min(min(min(r1,r2),min(r3,r4)),(DB)w);
		if(l>r && l-r<eps) swap(l,r); 
		if(l>r) return 0;
		lx=p[i][0]; ly=p[i][1];
	}
	return 1;
}

int main(){
#ifdef DEBUG
	freopen("E.in","r",stdin);
#endif
	n=read(); w=read(); h=read(); sx1=read(); sx2=read();
	for(int i=1;i<=n;i++) ti[i]=read(),p[i][0]=read(),p[i][1]=read();
	if(!check(w+1)){
		puts("-1");
		return 0;
	}
	DB l=0,r=w;
	while((r-l)/max((DB)1,l)>5e-5){
		DB mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}
	printf("%.10f\n",(double)(l+r)/2);
}