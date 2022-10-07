#include<stdio.h>
#include<algorithm>
int n,m;
int a[2010];
int ans;
int main(){
	int i;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	std::sort(a,a+n);
	for(i=n-1;i>=0;i-=m){
		ans+=a[i]-1;
	}
	ans*=2;
	printf("%d",ans);
}