#include<bits/stdc++.h>
using namespace std;
#define re register
#define int long long
long long n;
inline int gcd(re int x,re int y){
	return y?gcd(y,x%y):x;
}
signed main(){
	scanf("%lld",&n);
	for(re int i=sqrt(n);i>=1;--i){
		if(n%i==0){
			if(gcd(i,n/i)==1){
				printf("%lld %lld",i,n/i);
				return 0;
			}
		}
	}
}