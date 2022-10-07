#include<stdio.h>
#include<map>
int n;
int p;
int a[1000]={0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12};
std::map<int,int> dp;
int main(){
	long long int i,j,k;
	scanf("%d",&n);
	for(i=2;i*i<=n;i++){
		if(dp[i]!=1){
			j=1;
			for(k=0;j<=n;k++){
				j*=i;
				if(j<=n&&dp[j]!=1)p^=1;
				dp[j]=1;
			}
			k--;
			p^=a[k];
		}
	}
	p^=(n%2);
	if(p==0)printf("Petya");
	else printf("Vasya");
	return 0;
}