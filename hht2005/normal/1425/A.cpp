#include<bits/stdc++.h>
using namespace std;
const int F[5]={0,1,1,2,3};
long long f(long long x) {
	if(x<=4)return F[x];
	if(x%2==0&&x%4!=0)return x/2+f(x/2-1);
	else return f(x-2)+1;
}
int main() {
	int T;
	long long n;
	scanf("%d",&T);
	while(T--) {
		scanf("%lld",&n);
		if(n%2==0)printf("%lld\n",f(n));
		else printf("%lld\n",n-f(n-1));
	}
	return 0;
}