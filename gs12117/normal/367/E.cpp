#include<stdio.h>
int dpt[40000000];
int mod=1000000007;
int n,m,p;
long long int ans;
int main(){
	int i,j,k;
	scanf("%d%d%d",&n,&m,&p);
	if(m<n){
		printf("0");
		return 0;
	}
	p--;
	dpt[0]=1;
	for(i=0;i<m;i++){
		for(j=0;j<=n;j++){
			for(k=0;k<=j;k++){
				dpt[(i*(n+1)+j)*(n+1)+k]%=mod;
				if(i!=p)dpt[((i+1)*(n+1)+j)*(n+1)+k]+=dpt[(i*(n+1)+j)*(n+1)+k];
				dpt[((i+1)*(n+1)+j)*(n+1)+k]%=mod;
				if(j+1<=n)dpt[((i+1)*(n+1)+j+1)*(n+1)+k]+=dpt[(i*(n+1)+j)*(n+1)+k];
				dpt[((i+1)*(n+1)+j+1)*(n+1)+k]%=mod;
				if(i!=p&&k+1<=j)dpt[((i+1)*(n+1)+j)*(n+1)+k+1]+=dpt[(i*(n+1)+j)*(n+1)+k];
				dpt[((i+1)*(n+1)+j)*(n+1)+k+1]%=mod;
				if(j+1<=n)dpt[((i+1)*(n+1)+j+1)*(n+1)+k+1]+=dpt[(i*(n+1)+j)*(n+1)+k];
				dpt[((i+1)*(n+1)+j+1)*(n+1)+k+1]%=mod;
			}
		}
	}
	ans=dpt[(m*(n+1)+n)*(n+1)+n];
	for(i=0;i<n;i++){
		ans*=i+1;
		ans%=mod;
	}
	printf("%I64d",ans);
	return 0;
}