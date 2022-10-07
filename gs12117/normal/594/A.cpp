#include<stdio.h>
#include<algorithm>
int n;
int a[200100];
int ans;
int main(){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	std::sort(a,a+n);
	ans=1999999999;
	for(i=0;i+(n)/2<n;i++){
		if(a[i+(n)/2]-a[i]<ans){
			ans=a[i+(n)/2]-a[i];
		}
	}
	printf("%d",ans);
	return 0;
}