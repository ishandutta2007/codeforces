#include<stdio.h>
int n;
int a[310];
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<a[0];i++){
		printf("PRL");
	}
	for(i=1;i<n;i++){
		printf("R");
		for(j=0;j<a[i];j++){
			printf("PLR");
		}
	}
	return 0;
}