#include<cstdio>
#include<algorithm>
using namespace std;
#define re register
#define M 1000000007
const int Mxdt=100000;
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	int t=0;char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-'0',v=gc();
	return t;
}
int n,m;
long long a[200002],sum;
int main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+n+1);
	for(re int i=m+1;i<=n;++i)a[i]+=a[i-m];
	for(re int i=1;i<=n;++i)printf("%lld ",sum+=a[i]);
}