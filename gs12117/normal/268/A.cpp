#include<stdio.h>
int n;
int h[110];
int a[110];
int main(){
	int i,j,ta,tb,ans;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&ta,&tb);
		h[ta]++;
		a[tb]++;
	}
	ans=0;
	for(i=0;i<105;i++){
		ans+=h[i]*a[i];
	}
	printf("%d",ans);
}