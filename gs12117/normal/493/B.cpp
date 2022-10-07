#include<stdio.h>
int n;
int a[200100];
long long int ans;
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		ans+=a[i];
	}
	if(ans>0){
		puts("first");
	}
	else if(ans<0){
		puts("second");
	}
	else{
		i=0;
		j=0;
		while(i<n||j<n){
			while(a[i]<0)i++;
			while(a[j]>0)j++;
			if(a[i]+a[j]>0){
				puts("first");
				return 0;
			}
			else if(a[i]+a[j]<0){
				puts("second");
				return 0;
			}
			i++;
			j++;
		}
		if(a[n-1]>0){
			puts("first");
		}
		else if(a[n-1]<0){
			puts("second");
		}
	}
}