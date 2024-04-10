#include<stdio.h>
int n;
char a[100100];
char b[100100];
int ans;
int main(){
	int i;
	scanf("%d",&n);
	scanf("%s%s",a,b);
	ans=0;
	for(i=0;i<n;i++){
		if(a[i]!=b[i])break;
	}
	for(;i<n;i++){
		if(a[i+1]!=b[i])break;
	}
	for(;i<n;i++){
		if(a[i+1]!=b[i+1])break;
	}
	if(i==n)ans++;
	for(i=0;i<n;i++){
		if(a[i]!=b[i])break;
	}
	for(;i<n;i++){
		if(a[i]!=b[i+1])break;
	}
	for(;i<n;i++){
		if(a[i+1]!=b[i+1])break;
	}
	if(i==n)ans++;
	printf("%d",ans);
}