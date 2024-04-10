#include<stdio.h>
__int64 gcd(__int64 a,__int64 b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int main(){
	__int64 n,i,ans;
	scanf("%I64d",&n);
	if(n<3){
		ans=n;
	}
	else if(n%2==1){
		ans=n*(n-1)*(n-2);
	}
	else{
		for(i=n-2;i>0;i--){
			if(gcd(n,i)==1&&gcd(n-1,i)==1)break;
		}
		ans=n*(n-1)*i;
		if(ans<(n-1)*(n-2)*(n-3))ans=(n-1)*(n-2)*(n-3);
	}
	printf("%I64d",ans);
}