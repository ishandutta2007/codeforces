#include<stdio.h>
int n,m;
int a[100][2];
int main(){
	int i,t,ans;
	scanf("%d%d",&n,&m);
	t=0;
	ans=0;
	for(i=0;i<n;i++){
		scanf("%d%d",&a[i][0],&a[i][1]);
		a[i][0]--;
		ans+=(a[i][0]-t)%m;
		ans+=a[i][1]-a[i][0];
		t=a[i][1];
	}
	printf("%d",ans);
}