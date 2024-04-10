#include<stdio.h>
int b[2000000];
int main(){
	int a;
	scanf("%d",&a);
	for(int i=0;i<a;i++)b[i]=i+1;
	int t=0;
	for(int i=2;i<=a;i++){
		for(int j=(a-1)/i*i;j>=0;j-=i){
			if(j==(a-1)/i*i){
				b[t+a]=b[t+j];
			}else b[t+j+i]=b[t+j];
		}
		t++;
	}
	for(int i=0;i<a;i++)printf("%d ",b[t+i]);
}