#include<stdio.h>
int a,b,c,d;
int n,m;
int main(){
	int i,j;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a==0&&b==0&&c==0&&d==0){
		printf("1");
		return 0;
	}
	if(a==0){
		if(b==0&&c==0)n=0;
		else n=1;
	}
	else{
		n=2;
		while(n*(n-1)<a*2){
			n++;
		}
		if(n*(n-1)!=a*2){
			puts("Impossible");
			return 0;
		}
	}
	if(d==0){
		if(b==0&&c==0)m=0;
		else m=1;
	}
	else{
		m=2;
		while(m*(m-1)<d*2){
			m++;
		}
		if(m*(m-1)!=d*2){
			puts("Impossible");
			return 0;
		}
	}
	if(b+c!=n*m){
		puts("Impossible");
		return 0;
	}
	if(m==0){
		for(i=0;i<n;i++){
			printf("0");
		}
		return 0;
	}
	if(n==0){
		for(i=0;i<m;i++){
			printf("1");
		}
		return 0;
	}
	for(i=0;;i++){
		if(b<m)break;
		printf("0");
		b-=m;
	}
	for(j=0;j<m-b;j++){
		printf("1");
	}
	if(b>0){
		printf("0");
		i++;
	}
	for(j=0;j<b;j++){
		printf("1");
	}
	for(;i<n;i++){
		printf("0");
	}
	return 0;
}