#include<stdio.h>
#include<algorithm>
using namespace std;
int b[100];
int gcd(int a,int b){
	while(b){
		a%=b;
		int c=a;
		a=b;
		b=c;
	}return a;
}
int main(){
	int a;
	scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",b+i);
	int n=b[0];
	int m=b[0];
	for(int i=1;i<a;i++){
		n=gcd(n,b[i]);
		m=max(b[i],m);
	}
	if((m/n+a)%2==1)printf("Alice\n");
	else printf("Bob\n");
}