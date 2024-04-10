#include<stdio.h>
int n,ans;
int main(){
	int i,j,a,b;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		b--;
		for(j=0;b>0;j++)b/=4;
		if(a+j>ans)ans=a+j;
		if(a+1>ans)ans=a+1;
	}
	printf("%d",ans);
}