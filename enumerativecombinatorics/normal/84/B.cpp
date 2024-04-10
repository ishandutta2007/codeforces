#include<stdio.h>
int a[100000];
int main(){
	int b;
	scanf("%d",&b);
	for(int i=0;i<b;i++)scanf("%d",a+i);
	long long ret=0;
	int val=a[0];
	long long re=1;
	for(int i=1;i<b;i++){
		if(val!=a[i]){
			ret+=re*(re+1)/2;
			val=a[i];
			re=1;
		}else re++;
	}
	ret+=re*(re+1)/2;
	printf("%I64d\n",ret);
}