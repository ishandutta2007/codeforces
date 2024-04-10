#include<stdio.h>
int n;
int a[100100];
int prime[101000];
int lgs[100100];
int main(){
	int i,j,k,t;
	for(i=2;i<100100;i++){
		if(prime[i]==0){
			for(j=i;j<100100;j+=i){
				prime[j]=i;
			}
		}
	}
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		t=0;
		for(j=a[i];j!=1;){
			k=prime[j];
			if(lgs[k]>t){
				t=lgs[k];
			}
			while(j%k==0)j/=k;
		}
		t++;
		for(j=a[i];j!=1;){
			k=prime[j];
			lgs[k]=t;
			while(j%k==0)j/=k;
		}
	}
	t=1;
	for(i=0;i<100100;i++){
		if(lgs[i]>t)t=lgs[i];
	}
	printf("%d",t);
	return 0;
}