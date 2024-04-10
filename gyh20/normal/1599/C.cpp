#include<bits/stdc++.h>
#define re register
#define double long double
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m;
double P;
signed main(){
	cin>>n>>P;
	for(re int i=0;i<=n;++i){
		re int nn=n*(n-1)*(n-2)/6;
		re int p0=(n-i)*(n-i-1)*(n-i-2)/6,p1=i*(n-i)*(n-i-1)/2,p2=i*(i-1)*(n-i)/2,p3=i*(i-1)*(i-2)/6;
		re double ss=0;
		ss+=p1*0.5+p2+p3,ss/=nn;
		if(ss>=P)printf("%d",i),exit(0);
	}
}