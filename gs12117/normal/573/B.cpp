#include<stdio.h>
int n;
int a[100100];
int res[100100];
int main(){
	int i,p;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	p=1;
	for(i=0;i<n;i++){
		if(a[i]-i<p){
			p=a[i]-i;
		}
		res[i]=p+i;
	}
	p=n;
	for(i=n-1;i>=0;i--){
		if(a[i]+i<p){
			p=a[i]+i;
		}
		if(res[i]>p-i)res[i]=p-i;
	}
	p=0;
	for(i=0;i<n;i++){
		if(res[i]>p)p=res[i];
	}
	printf("%d",p);
}