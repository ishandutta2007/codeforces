#include<bits/stdc++.h>
using namespace std;
int main() {
	long long n,p;
	int w,d;
	scanf("%lld%lld%d%d",&n,&p,&w,&d);
	for(int i=0;i<w;i++) {
		if(p<1ll*d*i||(p-1ll*d*i)%w!=0)continue;
		long long j=(p-1ll*d*i)/w;
		if(i+j>n)continue;
		printf("%lld %d %lld\n",j,i,n-i-j);
		return 0;
	}
	puts("-1");
	return 0;
}