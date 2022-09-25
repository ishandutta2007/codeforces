#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double eps=1e-9;
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
int T;
double Solve(double n,double m,double p,double v){
	double ans=1;
	if(n>eps){
		double t=min(n,v);
		ans+=Solve(n-t,m>eps?m+t/2:0,m>eps?p+t/2:p+t,v)*n;
	}
	if(m>eps){
		double t=min(m,v);
		ans+=Solve(n>eps?n+t/2:0,m-t,n>eps?p+t/2:p+t,v)*m;
	}
	return ans;
}
void Solve(){
	double n,m,p,v;
	scanf("%lf %lf %lf %lf",&n,&m,&p,&v);
	printf("%.10lf\n",Solve(n,m,p,v));
}
int main(){
	T=read();
	while(T--)Solve();
	return 0;
}