#include<stdio.h>
int n,m;
int a[100100][2];
int ans;
int main(){
	int i;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&a[i][0],&a[i][1]);
		if(i!=0){
			if(a[i][0]-a[i-1][0]<a[i][1]-a[i-1][1]||a[i][0]-a[i-1][0]<a[i-1][1]-a[i][1]){
				printf("IMPOSSIBLE");
				return 0;
			}
			if(ans<(a[i][1]+a[i-1][1]+a[i][0]-a[i-1][0])/2){
				ans=(a[i][1]+a[i-1][1]+a[i][0]-a[i-1][0])/2;
			}
		}
	}
	if(ans<a[0][0]+a[0][1]-1){
		ans=a[0][0]+a[0][1]-1;
	}
	if(ans<a[m-1][1]+n-a[m-1][0]){
		ans=a[m-1][1]+n-a[m-1][0];
	}
	printf("%d",ans);
}