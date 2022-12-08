#include<bits/stdc++.h>
using namespace std;
int main() {
	int T;
	long long n;
	scanf("%d",&T);
	while(T--) {
		scanf("%lld",&n);
		long long N=(n-1)/3+1,t,a=1,b,P=1;
		while(a<N) {
			P<<=2;
			a+=P;
		}
		t=N-a+P-1;
		a=t+P;
		b=P<<1;
		int k=0;
		while(t) {
			if(t%4==1)b|=2ll<<k;
			if(t%4==2)b|=3ll<<k;
			if(t%4==3)b|=1ll<<k;
			t>>=2;
			k+=2;
		}
		if(n%3==1)printf("%lld\n",a);
		if(n%3==2)printf("%lld\n",b);
		if(n%3==0)printf("%lld\n",a^b);
	}
	return 0;
}