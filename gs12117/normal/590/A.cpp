#include<stdio.h>
int n;
int a[500100];
int fix[500100];
int nfix[500100];
int ans;
int main(){
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	fix[0]=1;
	fix[n-1]=1;
	for(i=0;i<n-1;i++){
		if(a[i]==a[i+1]){
			fix[i]=1;
			fix[i+1]=1;
		}
	}
	ans=0;
	for(i=0;i<n;i++){
		if(fix[i]==0){
			j=i;
			while(fix[j]==0)j++;
			j--;
			if(ans<1+(j-i)/2)ans=1+(j-i)/2;
			for(k=0;i+k<=j-k;k++){
				a[i+k]=a[i-1];
				a[j-k]=a[j+1];
			}
			i=j;
		}
	}
	printf("%d\n",ans);
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}