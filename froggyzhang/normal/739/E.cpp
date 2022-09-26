#include<bits/stdc++.h>
using namespace std;
#define N 200020
double eps=1e-9;
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
int n,A,B;
double a[N],b[N];
struct Data{
	double val;
	int _a,_b;
	Data(double _v=0,int __a=0,int __b=0){val=_v,_a=__a,_b=__b;}
	friend bool operator < (const Data &a,const Data &b){
		return a.val<=b.val;
	}
	friend Data operator + (const Data &a,const Data &b){
		return (Data){a.val+b.val,a._a+b._a,a._b+b._b};
	}
}myh;
inline void check(double x,double y){
	myh={0,0,0};
	for(int i=1;i<=n;++i){
		myh=myh+max(max(Data(0,0,0),Data(a[i]+b[i]-a[i]*b[i]-x-y,1,1)),max(Data(a[i]-x,1,0),Data(b[i]-y,0,1)));
	}
}
double Solve2(double t){
	double l=-eps,r=1+eps;
	while(r-l>eps){
		double mid=(l+r)/2;
		check(t,mid);
		if(myh._b>=B)l=mid;
		else r=mid;
	}
	check(t,l);
	return myh.val+B*l;
}
double Solve1(){
	double l=-eps,r=1+eps,ans=0;
	while(r-l>eps){
		double mid=(l+r)/2;
		double tp=Solve2(mid);
		if(myh._a>=A){
			ans=tp+A*mid;
			l=mid;
		}
		else r=mid;
	}
	return ans;
}
int main(){
	n=read(),A=read(),B=read();
	for(int i=1;i<=n;++i){
		scanf("%lf",a+i);
	}
	for(int i=1;i<=n;++i){
		scanf("%lf",b+i);
	}
	printf("%.6lf\n",Solve1());
	return 0;
}