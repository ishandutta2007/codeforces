#include<stdio.h>
int n;
int a[110];
int gcd(int x,int y){
	if(x==0)return y;
	return gcd(y%x,x);
}
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int tgcd=a[0];
	for(i=1;i<n;i++){
		tgcd=gcd(a[i],tgcd);
	}
	int max=a[0];
	for(i=1;i<n;i++){
		if(max<a[i])max=a[i];
	}
	if((max/tgcd-n)%2==1)printf("Alice");
	else printf("Bob");
	return 0;
}