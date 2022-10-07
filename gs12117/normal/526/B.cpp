#include<stdio.h>
int n;
int a[3000];
int ans;
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=2;i<(1<<(n+1));i++){
		scanf("%d",&a[i]);
	}
	for(i=n;i>0;i--){
		for(j=0;j<(1<<(i-1));j++){
			if(a[2*j+(1<<i)]>a[2*j+1+(1<<i)]){
				ans+=a[2*j+(1<<i)]-a[2*j+1+(1<<i)];
				a[j+(1<<(i-1))]+=a[2*j+(1<<i)];
			}
			else{
				ans+=a[2*j+1+(1<<i)]-a[2*j+(1<<i)];
				a[j+(1<<(i-1))]+=a[2*j+1+(1<<i)];
			}
		}
	}
	printf("%d",ans);
}