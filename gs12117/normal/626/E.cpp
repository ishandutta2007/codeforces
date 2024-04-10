#include<stdio.h>
#include<algorithm>
int n;
int x[200100];
long long int sum[200100];
double ans;
int ansp,ansq;
double fans(int p,int q){
	double tans=sum[n]-sum[n-q]+sum[p+1]-sum[p-q];
	tans/=(2*q+1);
	tans-=x[p];
	return tans;
}
int main(){
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x[i]);
	}
	std::sort(x,x+n);
	sum[0]=0;
	for(i=0;i<n;i++){
		sum[i+1]=sum[i]+x[i];
	}
	ans=-1;
	for(i=0;i<n;i++){
		k=0;
		for(j=20;j>=0;j--){
			k+=1<<j;
			if(k>i||k>n-i-1||fans(i,k)<fans(i,k-1))k-=1<<j;
		}
		if(fans(i,k)>ans){
			ans=fans(i,k);
			ansp=i;
			ansq=k;
		}
	}
	printf("%d\n",2*ansq+1);
	for(i=ansp-ansq;i<=ansp;i++){
		printf("%d ",x[i]);
	}
	for(i=n-ansq;i<n;i++){
		printf("%d ",x[i]);
	}
}