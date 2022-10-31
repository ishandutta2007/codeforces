#include<stdio.h>
int main(){
	unsigned int a,b,c;
	scanf("%u%u%u",&a,&b,&c);
	if(((a%3+b%3+c%3==4&&(a==0||b==0||c==0))||a%3+b%3+c%3==3)&&(a%3)*(b%3)*(c%3)==0){
		printf("%u\n",(a+b+c)/3-1);
	}
	else printf("%u\n",(a+b+c)/3);
}