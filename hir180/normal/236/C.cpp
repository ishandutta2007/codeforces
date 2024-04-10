#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
/*(^(^(^(^(^o^)^)^)^)^) ('') */
long long i,j,k,sum=0,a,b,c,d,e,f;
int main(){
	scanf("%lld",&a);
	if(a==1){
		printf("1\n");goto wee;
	}
	if(a==2){
		printf("2\n");goto wee;
	}
	if(a==3){
		printf("6\n");goto wee;
	}
	if(a%2==1){
		printf("%lld\n",a*(a-1)*(a-2));
		goto wee;
	}else{
		b=a-1;
		c=a-2;
		d=a-3;
		sum=b*c*d;
		if(a%3!=0){
			if(sum<a*(a-1)*(a-3)){
				sum=a*(a-1)*(a-3);
			}
			if(a%5!=0){
			if(sum<a*(a-3)*(a-5)){
				sum=a*(a-3)*(a-5);
			}
			}
		}
	}
	printf("%lld\n",sum);
wee:;
	return 0;
}