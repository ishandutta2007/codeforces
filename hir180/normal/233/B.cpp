#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
/*(^(^(^(^(^o^)^)^)^)^) ('')  TLE*/
int main(){
	long long  a=0,n,c,d,e=0,i,x,num=0,sum=0;
	scanf("%lld",&n);
	long double r=n/2;
	if(n<=1000){
	for(i=sqrt(r);i<=sqrt(r*2);i++){
		if(n%i==0){
	x=i;
		while(x!=0){
			sum += x%10;
			x /= 10;
		}if(sum==(-1*i+n/i)){
			printf("%lld\n",i);
goto s;
		}
		sum=0;}
	}
printf("-1\n");
	}else{
			for(i=sqrt(81*81+r*2)-81;i<=sqrt(r*2);i++){
		if(n%i==0){
	x=i;
		while(x!=0){
			sum += x%10;
			x /= 10;
		}if(sum==(-1*i+n/i)){
			printf("%lld\n",i);
goto s;
		}
		sum=0;}
	}
printf("-1\n");
	}
	s:;
		return 0;
}