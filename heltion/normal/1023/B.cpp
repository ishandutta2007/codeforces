#include<bits/stdc++.h>
#define maxn 240000 
using namespace std;
int main(){
	long long n, k;
	scanf("%lld %lld", &n, &k);
	if(k % 2 == 0){
		if(n >= k) printf("%lld", k / 2 - 1);
		else if(n > k / 2) printf("%lld", n - k / 2);
		else printf("0");
	}
	else{
		if(n >= k) printf("%lld", k / 2);
		else if(n >= (k + 1) / 2) printf("%lld", n - (k + 1) / 2 + 1);
		else printf("0");
	}
}