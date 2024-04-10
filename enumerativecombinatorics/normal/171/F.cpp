#include<stdio.h>
int prime[5000000];
int main(){
	int a;
	scanf("%d",&a);
	prime[0]=prime[1]=-1;
	for(int i=2;i<5000000;i++){
		if(~prime[i]){
			prime[i]=1;
			for(int j=i+i;j<5000000;j+=i)prime[j]=-1;
		}
	}
	int count=0;
	int at=10;
	do{
		at++;
		int B=at;
		if(!~prime[B])continue;
		int C=0;
		while(B){
			C*=10;
			C+=B%10;
			B/=10;
		}
		if(at==C)continue;
		if(!~prime[C])continue;
		count++;
	}while(count<a);
	printf("%d\n",at);
}