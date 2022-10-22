#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	long long ans=0;
	for(long long m=1; m < b; ++m){
		long long n=a;
		long long sum=((n*(n+1)))/2;
		sum%=MOD;
		long long prod=b*m;
		prod%=MOD;
		ans += sum*prod+n*m;	
		ans %= MOD;
	}
	printf("%I64d\n", ans);
}