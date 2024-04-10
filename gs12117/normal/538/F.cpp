#include<stdio.h>
int n;
int a[200100];
int b[200100];
int ans[200100];
int findk(int x,int y){
	return (x-1)/(y+1)+1;
}
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<n;i++){
		for(j=1;j<n;j++){
			if((i-1)/j==(i-1)/(j+1))break;
			if(a[(i-1)/j]>a[i]){
				b[j]++;
				b[j+1]--;
			}
		}
		j=(i-1)/j;
		for(;j>0;j--){
			if(a[j]>a[i]){
				b[findk(i,j)]++;
				b[findk(i,j-1)]--;
			}
		}
		if(a[0]>a[i]){
			b[findk(i,0)]++;
		}
	}
	for(i=1;i<n;i++){
		ans[i]=ans[i-1]+b[i];
		printf("%d ",ans[i]);
	}
}