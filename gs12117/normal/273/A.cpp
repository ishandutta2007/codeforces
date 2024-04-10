#include<stdio.h>
int n,m;
int a[100100];
long long int ans;
int main(){
	int i,w,h;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d\n",&a[i]);
	}
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&w,&h);
		if(a[w-1]>ans)ans=a[w-1];
		printf("%I64d\n",ans);
		ans+=h;
	}
}