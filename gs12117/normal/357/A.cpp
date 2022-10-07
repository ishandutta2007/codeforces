#include<stdio.h>
int n;
int a[110];
int x,y;
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		a[i+1]+=a[i];
	}
	scanf("%d%d",&x,&y);
	for(i=0;i<n;i++){
		if(a[i]>=x&&a[i]<=y&&(a[n]-a[i])>=x&&(a[n]-a[i])<=y){
			printf("%d",i+2);
			return 0;
		}
	}
	printf("0");
	return 0;
}