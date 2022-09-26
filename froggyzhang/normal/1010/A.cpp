#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const double eps=1e-10;
#define N 1234
inline int read(){
	int x=0,f=1;
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
int n,m,a[N],b[N];
double l,r,ans;
inline bool check(double x){
	x+=m;
	for(int i=1;i<=n;++i){
		x-=x/a[i];
		x-=x/b[i%n+1];
		if(x<m)return false;
	}
	return true;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)b[i]=read();
	l=0,r=1e9+233;
	while(r-l>eps){
		double mid=(l+r)/2.0;
		if(check(mid)){
			r=mid;
		}
		else{
			l=mid;
		}
	}
	if(l>1e9+1){
		printf("-1\n");
		return 0;
	}
	printf("%.10lf\n",l);
	return 0;
}