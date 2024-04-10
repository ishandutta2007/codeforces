#include<stdio.h>
#include<math.h>
long long int r,h;
int main(){
	scanf("%I64d%I64d",&r,&h);
	if(h*2<r){
		printf("1");
		return 0;
	}
	long long int t=h*2/r;
	if(t%2==1){
		if(h*2/(double)r-t>sqrt(3)-1){
			t++;
		}
	}
	t++;
	printf("%I64d",t);
}