#include<stdio.h>
int n;
int a[100100];
long long int ans;
long long int dpa[100100];
long long int dpb[100100];
long long int dpc[100100];
int main(){
	int i;
	scanf("%d",&n);
	n--;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=n-1;i>=0;i--){
		if(a[i]==1){
			dpc[i]=0;
		}
		else if(a[i]%2==0){
			dpc[i]=dpc[i+1]+a[i];
		}
		else{
			dpc[i]=dpc[i+1]+a[i]-1;
		}
	}
	for(i=0;i<n;i++){
		if(a[i]==1){
			dpb[i+1]=0;
		}
		else if(a[i]%2==0){
			dpb[i+1]=dpb[i]+a[i];
		}
		else{
			dpb[i+1]=dpb[i]+a[i]-1;
		}
		if(a[i]==1){
			dpa[i+1]=dpa[i]+1;
		}
		else if(a[i]%2==0){
			dpa[i+1]=dpa[i]+a[i]-1;
		}
		else{
			dpa[i+1]=dpa[i]+a[i];
		}
		if(dpa[i+1]<dpb[i+1]){
			dpa[i+1]=dpb[i+1];
		}
		if(ans<dpa[i+1]+dpc[i+1])ans=dpa[i+1]+dpc[i+1];
	}
	printf("%I64d",ans);
}