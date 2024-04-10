#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=1e5;
long long d[N];
long long C(int n,int m) {
	if(m==2)return 1ll*n*(n-1)/2;
	return 1ll*n*(n-1)*(n-2)/6;
}
int main() {
	int T,a,b,c;
	for(int i=1;i<=M;i++)
		for(int j=i;j<=M;j+=i)
			d[j]++;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d",&a,&b,&c);
		int ga=__gcd(b,c),gb=__gcd(a,c),gc=__gcd(a,b),gg=__gcd(__gcd(a,b),c);
		printf("%lld\n",d[a]*d[b]*d[c]-d[a]*C(d[ga],2)-d[b]*C(d[gb],2)-d[c]*C(d[gc],2)
		+C(d[gg],3)*4+C(d[gg],2)*(d[ga]+d[gb]+d[gc]-3*d[gg]+2)
		-(d[ga]-d[gg])*(d[gb]-d[gg])*(d[gc]-d[gg]));
	}
	return 0;
}