#include <bits/stdc++.h>

using namespace std;

long long F(long long n){
	if(n == 0)
		return 0;
	long long ten=1;
	int p=0;
	while(10*ten <= n){
		ten*=10;
		++p;
	}
	long long ans;
	int i;
	for(i=1; i*ten <= n; ++i){
	}
	--i;
	ans=i*(ten/10)*45*p;
	ans += ((i*(i-1))/2)*ten;
	ans += (n-i*ten)*i;
	ans += F(n-i*ten);
	return ans;
}

int main(){
	/*while(true){
	long long a;
	scanf("%I64d", &a);
	printf("%I64d\n", F(a));
	}*/
	long long a;
	scanf("%I64d", &a);
	long long Max=20000000000000000LL, Min=0;
	while(Max-Min > 1){
		long long test=(Max+Min)/2;
		if(F(test) < a){
			Min=test;
		}
		else{
			Max=test;
		}
	}
	long long l=1, r=Max;
	while(true){
		long long f1=F(l), f2=F(r)-a;
		if(f1 < f2){
			++l;
		}
		else if(f1 > f2){
			++r;
		}
		else{
			printf("%I64d %I64d\n", l, r-1);
			break;
		}
	}
	/*while(true){
	long long a;
	scanf("%I64d", &a);
	printf("%I64d\n", F(a));
	}*/
}