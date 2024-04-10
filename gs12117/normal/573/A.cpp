#include<stdio.h>
int n;
int a[100100];
int main(){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		while(a[i]%2==0){
			a[i]/=2;
		}
		while(a[i]%3==0){
			a[i]/=3;
		}
		if(a[i]!=a[0]){
			printf("No");
			return 0;
		}
	}
	printf("Yes");
	return 0;
}