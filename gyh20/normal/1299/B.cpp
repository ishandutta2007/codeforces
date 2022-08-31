#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#define re register
using namespace std;
#define eps 1e-12
#define double long double
int n,a,b;
double x[100002],y[100002];
 
inline double xl(re int a,re int b){
	if(x[b]==x[a])return 1e18;
	return (y[b]-y[a])/(x[b]-x[a]);
}
inline double F(re double x){
	return x>0?x:-x;
}
bool ia;
signed main() {
	scanf("%d",&n);
	for(re int i=1;i<=n;++i){
	scanf("%d%d",&a,&b);x[i]=a;y[i]=b;}
	if(n&1){
		puts("NO");
		return 0;
	}
	x[n+1]=x[1],y[n+1]=y[1];
	for(re int i=1;i<=n/2;++i){
		if(F(xl(i,i+1)-xl(i+n/2,i+n/2+1))>eps){
			puts("NO");
			return 0;
		}
		if(F(y[i+1]-y[i])!=F(y[i+n/2+1]-y[i+n/2])){
			
			puts("NO");
			return 0;
		}
		if(F(x[i+1]-x[i])!=F(x[i+n/2+1]-x[i+n/2])){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}