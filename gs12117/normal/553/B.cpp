#include<stdio.h>
int n;
long long int m;
long long int fib[100];
int cmg[100];
int arr[100];
int tmp[100];
int main(){
	int i,j,k;
	scanf("%d%I64d",&n,&m);
	m--;
	fib[1]=1;
	for(i=2;i<n+5;i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
	for(i=0;i<n;i++){
		if(m>=fib[n-i]){
			m-=fib[n-i];
			printf("%d %d ",i+2,i+1);
			i++;
		}
		else{
			printf("%d ",i+1);
		}
	}
}