#include<stdio.h>
int n;
int a[2010];
long long int d[5010];
double td[10100];
double ans;
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<i;j++){
			if(a[i]-a[j]>0)d[a[i]-a[j]]++;
			else d[a[j]-a[i]]++;
		}
	}
	for(i=0;i<5005;i++){
		for(j=0;j<5005;j++){
			td[i+j]+=d[i]*d[j];
		}
	}
	for(i=0;i<5005;i++){
		for(j=0;j<i;j++){
			ans+=td[j]*d[i];
		}
	}
	ans/=n*(n-1)/2;
	ans/=n*(n-1)/2;
	ans/=n*(n-1)/2;
	printf("%.20lf",ans);
}