#include<stdio.h>
int n;
int a[100100];
int b[100100];
int c[100100];
int ans;
int main(){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		b[a[i]-1]=i;
	}
	for(i=0;i<n;i++){
		c[i]=1;
		if(i!=0&&b[i]>b[i-1])c[i]=c[i-1]+1;
		if(ans<c[i])ans=c[i];
	}
	printf("%d",n-ans);
	return 0;
}