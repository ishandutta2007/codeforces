#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
#define EOR(i,x) for(int i=Head[x]; ~i; i=Nxt[i])

typedef double db;
typedef long long ll;

inline void rd(int &x) {
	static char c;x=0;
	while(c=getchar(),c<48);
	do x=(x<<3)+(x<<1)+(c^48);
	while(c=getchar(),c>47);
}
inline void pt(int x) {
	if(!x) putchar('0');
	static int Stk[30],tp=0;
	for(; x; x/=10) Stk[tp++]=x%10;
	while(tp) putchar(Stk[--tp]^48);
}
inline void ptk(const int &x) {pt(x);putchar(' ');}
inline void ptn(const int &x) {pt(x);putchar('\n');}

inline bool chkmx(int &x,const int &y) {return x<y?x=y,true:false;}
inline bool chkmi(int &x,const int &y) {return x>y?x=y,true:false;}

typedef double db;
const int M=(int)1e5+500;
const db EPS=(db)1e-6;
int chk(db x,db y){return x-y<EPS?-1:x-y>EPS?1:0;}
/*
x<y chk(x,y)<0
x<=y chk(x,y)<=0
x>y chk(x,y)>0
x>=y chk(x,y)>=0
*/
struct Point{
	db x,y;
	db dis2(){
		return x*x+y*y;
	}
	Point operator + (const Point &B)const{
		return (Point){x+B.x,y+B.y};
	}
	Point operator - (const Point &B)const{
		return (Point){x-B.x,y-B.y};
	}
	friend Point operator * (const Point &A,db x){
		return (Point){A.x*x,A.y*x};
	}
	void rd() {scanf("%lf%lf",&x,&y);}
}a1,a2,b1,b2;
db d1,d2;
db calc(db x){
	return ((a1+(a2-a1)*x)-(b1+(b2-b1)*x)).dis2();
}
int n;
bool Find_Mn() {
	db l=0,r=1;
	if(calc(0.001)-calc(0)>EPS) {
		if(calc(0)>calc(1)) l=r=1;
		else l=r=0;
	} else {
		while(r-l>EPS) {
			db m1=(l*2+r)/3;
			db m2=(l+r*2)/3;
			if(calc(m1)<calc(m2)) {
				r=m2;
			} else {
				l=m1;
			}
		}
	}
	bool f=false;
	if(chk(calc(l),d1*d1)<=0) f=true;
	a1=a1+(a2-a1)*l;
	b1=b1+(b2-b1)*l;
	return f;
}
bool Find_Mx() {
	db l=0,r=1;
	if(calc(0.001)-calc(0)>EPS) {
		while(r-l>EPS) {
			db m1=(l*2+r)/3;
			db m2=(l+r*2)/3;
			if(calc(m1)>calc(m2)) {
				r=m2;
			} else {
				l=m1;
			}
		}
	} else {
		if(calc(0)<calc(1)) l=r=1;
		else l=r=0;
	}
	bool f=false;
	if(chk(calc(l),d2*d2)>0) f=true;
	a1=a1+(a2-a1)*l;
	b1=b1+(b2-b1)*l;
	return f;
}
int ax[M],ay[M],bx[M],by[M];
int main(){
	int f=1,ans=0;
	scanf("%d%lf%lf",&n,&d1,&d2);
	FOR(i,1,n){
		scanf("%d%d%d%d",&ax[i],&ay[i],&bx[i],&by[i]);
		if(i==1)continue;
		a1=(Point){ax[i-1],ay[i-1]};
		a2=(Point){ax[i],ay[i]};
		b1=(Point){bx[i-1],by[i-1]};
		b2=(Point){bx[i],by[i]};
		if(f){
			if(Find_Mn()){
				++ans;
				f=Find_Mx();
			}
		}else{
			f=Find_Mx();
			if(f&&Find_Mn()){
				++ans;
				f=0;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}