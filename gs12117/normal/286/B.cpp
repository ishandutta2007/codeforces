#include<stdio.h>
int n;
int a[1001000];
int b[2001000];
int main(){
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		a[i]=i;
		b[i]=i;
	}
	for(i=0;i<=n-2;i++){
		for(j=i;j<n+i;j+=i+2){
			k=b[j];
			a[k]+=i+2;
			if(a[k]>=n+i+1){
				a[k]=n+i;
			}
		}
		j-=i+2;
		for(;j>=i;j-=i+2){
			b[a[b[j]]]=b[j];
		}
	}
	for(i=n-1;i<n*2-1;i++){
		printf("%d ",b[i]+1);
	}
}