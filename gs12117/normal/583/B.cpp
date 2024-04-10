#include<stdio.h>
int n;
int a[1010];
int chk[1010];
int main(){
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	j=0;
	for(i=0;;i++){
		k=i%(2*n);
		if(k>=n)k=2*n-1-k;
		if(chk[k]==0&&a[k]<=j){
			chk[k]=1;
			j++;
			if(j==n)break;
		}
	}
	printf("%d",i/n);
}