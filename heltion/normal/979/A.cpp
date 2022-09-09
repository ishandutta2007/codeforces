#include<cstdio>
int main(){
	long long n;
	scanf("%lld", &n);
	if(n == 0) printf("%lld", n);
	else if(n & 1) printf("%lld", (n + 1) / 2);
	else printf("%lld", n  + 1);
}