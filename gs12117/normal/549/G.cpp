#include<stdio.h>
#include<algorithm>
int n;
int a[200100];
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		a[i]+=i;
	}
	std::sort(a,a+n);
	for(i=0;i<n-1;i++){
		if(a[i]==a[i+1]){
			printf(":(");
			return 0;
		}
	}
	for(i=0;i<n;i++){
		printf("%d ",a[i]-i);
	}
}