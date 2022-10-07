#include<stdio.h>
int a[100100];
int b[100100];
long long int c[100100];
int d[100100];
int mod=1000000007;
int n;
int max;
long long int ans;
int f(int x,int y){
	if(y==0)return 1;
	long long int k=f(x,y/2);
	k*=k;
	k%=mod;
	if(y%2==1){
		k*=x;
		k%=mod;
	}
	return k;
}
int main(){
	int i,j,t;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&t);
		a[t]++;
		if(t>max)max=t;
	}
	for(i=1;i<=max;i++){
		a[i]+=a[i-1];
		c[i]=1;
	}
	for(i=1;i<=max;i++){
		for(j=i;j<=max;j+=i){
			c[j]*=f(d[j],a[i-1]-a[b[j]]);
			c[j]%=mod;
			b[j]=i-1;
			d[j]++;
		}
		ans+=c[i]*(f(d[i],n-a[b[i]])-f(d[i]-1,n-a[b[i]])+mod);
		ans%=mod;
	}
	printf("%d",ans);
}