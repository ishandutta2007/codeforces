#include<stdio.h>
long long int a,b,c,d,e;
int ans;
int main(){
	int i;
	scanf("%I64d%I64d%I64d",&a,&b,&c);
	if(a==1&&b==1&&c==1){
		puts("inf");
		return 0;
	}
	if(a==b&&b!=c){
		puts("0");
		return 0;
	}
	if(a==b&&b==c){
		puts("2");
		return 0;
	}
	if(a!=b&&b==c){
		puts("1");
		return 0;
	}
	if(a>b||b>c){
		puts("0");
		return 0;
	}
	if(a==1){
		d=0;
		while(c!=0){
			d+=c%b;
			c/=b;
		}
		if(d!=b&&d!=1){
			puts("0");
		}
		else{
			puts("1");
		}
		return 0;
	}
	d=0;
	e=1;
	while(c!=0){
		d+=(c%b)*e;
		c/=b;
		e*=a;
	}
	if(d!=b){
		puts("0");
	}
	else{
		puts("1");
	}
	return 0;
}