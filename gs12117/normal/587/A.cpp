#include<stdio.h>
int n;
int a[1001000];
int b[1001000];
int ans;
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		b[a[i]]++;
	}
	ans=0;
	for(i=0;i<1000100;i++){
		b[i+1]+=b[i]/2;
		b[i]%=2;
		ans+=b[i];
	}
	printf("%d",ans);
	return 0;
}