#include<stdio.h>
int main(){
	long long a,b,c;scanf("%I64d%I64d%I64d",&a,&b,&c);
	if(a<=0LL&&b<=0LL&&a<c&&b<c){printf("-1\n");return 0;}
	if(b<a){
		long long d=b;
		b=a;
		a=d;
	}
	if(a>=c||b>=c){printf("0\n");return 0;}
	long long ret=0;
	if(a<0LL){
		ret+=(-a)/b+1;
		a+=b*ret;
	}
	while(a<c&&b<c){
		ret++;
		if(a<b){
			a+=b;
		}else b+=a;
	}
	printf("%I64d\n",ret);
}