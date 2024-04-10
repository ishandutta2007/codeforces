#include<stdio.h>
#include<string.h>
char str[100001];
int main(){
	int mod=1000000007;
	int b;
	scanf("%s%d",str,&b);
	int a=strlen(str);
	long long c=mod-2;
	long long d=1;
	long long e=1;
	for(int i=0;i<a;i++)e=e*2%mod;
	e--;
	while(c){
		if(c%2){
			d=d*e%mod;
		}
		e=e*e%mod;
		c/=2;
	}
	long long rev=d;
	c=(long long)a*b;
	d=1;
	e=2;
	while(c){
		if(c%2){
			d=d*e%mod;
		}
		e=e*e%mod;
		c/=2;
	}
	d--;
	d=d*rev%mod;
	long long p=0;
	long long q=1;
	for(int i=0;i<a;i++){
		if(str[i]=='0'||str[i]=='5')p=(p+q)%mod;
		q=q*2%mod;
	}
	printf("%d\n",p*d%mod);
}