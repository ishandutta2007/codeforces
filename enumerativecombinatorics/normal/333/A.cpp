#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	long long a;
	scanf("%I64d",&a);
	long long b=3;
	long long c=a;
	while(c%3==0){
		c/=3;
		b*=3;
	}
	printf("%I64d\n",(a+b-1)/b);
}