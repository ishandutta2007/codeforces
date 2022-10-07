#include<stdio.h>
int n,m;
int a[300100][3];
int uft[300100];
int ans[300100];
int f(int x){
	if(x==uft[x])return x;
	return uft[x]=f(uft[x]);
}
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n+10;i++){
		uft[i]=i;
	}
	for(i=0;i<m;i++){
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		for(j=f(a[i][0]);j<=a[i][1];j=f(j+1)){
			if(j==a[i][2])continue;
			uft[j]=f(j+1);
			ans[j]=a[i][2];
		}
	}
	for(i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}