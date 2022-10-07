#include<stdio.h>
int n,m;
int a[100100][3];
int ans[100100];
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		if(ans[a[i][0]]!=0){
			ans[a[i][1]]=ans[a[i][0]]%3+1;
			ans[a[i][2]]=ans[a[i][1]]%3+1;
		}
		else if(ans[a[i][1]]!=0){
			ans[a[i][2]]=ans[a[i][1]]%3+1;
			ans[a[i][0]]=ans[a[i][2]]%3+1;
		}
		else if(ans[a[i][2]]!=0){
			ans[a[i][0]]=ans[a[i][2]]%3+1;
			ans[a[i][1]]=ans[a[i][0]]%3+1;
		}
		else{
			ans[a[i][0]]=1;
			ans[a[i][1]]=2;
			ans[a[i][2]]=3;
		}
	}
	for(i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}